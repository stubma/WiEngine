package com.wiyun.engine.network;

import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.util.List;

import org.apache.http.Header;
import org.apache.http.HttpHost;
import org.apache.http.HttpResponse;
import org.apache.http.HttpVersion;
import org.apache.http.NameValuePair;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpDelete;
import org.apache.http.client.methods.HttpEntityEnclosingRequestBase;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.methods.HttpPut;
import org.apache.http.client.methods.HttpUriRequest;
import org.apache.http.client.params.CookiePolicy;
import org.apache.http.client.params.HttpClientParams;
import org.apache.http.conn.ClientConnectionManager;
import org.apache.http.conn.params.ConnRoutePNames;
import org.apache.http.conn.scheme.PlainSocketFactory;
import org.apache.http.conn.scheme.Scheme;
import org.apache.http.conn.scheme.SchemeRegistry;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.impl.conn.tsccm.ThreadSafeClientConnManager;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;
import org.apache.http.params.HttpParams;
import org.apache.http.params.HttpProtocolParams;

import android.content.Context;
import android.content.pm.PackageManager;
import android.net.Proxy;
import android.net.wifi.SupplicantState;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.Process;
import android.telephony.TelephonyManager;
import android.text.TextUtils;
import android.util.Log;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.utils.Utilities;

/**
 * Java side network utility class. Only used by native, not public class
 */
class Network {
	private static final class HttpClientThread extends Thread {
		DefaultHttpClient mClient;
		HttpUriRequest mRequest;
		int mRequestPointer;
		int mListenerPointer;
		
		HttpClientThread(DefaultHttpClient client, HttpUriRequest request, int requestPointer, int listenerPointer) {
			mClient = client;
			mRequest = request;
			mRequestPointer = requestPointer;
			mListenerPointer = listenerPointer;
			
			setDaemon(true);
		}
		
		@Override
		public void run() {
			Process.setThreadPriority(Process.THREAD_PRIORITY_LOWEST);
			
			int responsePointer = 0;
			try {
				// execute
	            HttpResponse response = mClient.execute(mRequest);
	            responsePointer = notifyOnHttpReceiveResponse(response, mRequestPointer, mListenerPointer);
	            
	            // read
	            do {
	            	// if director is in destroying, break from network thread
	            	if(Director.isEnding())
	            		break;
	            	
	            	// if request already cancelled
	            	if(isRequestCancelled(mRequestPointer))
	            		break;
	            	
	            	// read data
	            	int ret = notifyOnHttpReceiveData(responsePointer, mListenerPointer);
		            if(ret == -2) {
		            	// notify failed event
		            	notifyOnHttpLoadingFailed(responsePointer, mListenerPointer);
		            	break;
		            } else if(ret == -1) {
		            	// notify for success
		            	notifyOnHttpFinishLoading(responsePointer, mListenerPointer);
		            	break;
		            }
	            } while(true);
            } catch (Exception e) {
            	// notify for failed event
            	if(responsePointer == 0)
            		responsePointer = createHttpResponse();
            	notifyOnHttpLoadingFailed(responsePointer, mListenerPointer);
            } finally {
            	// release response
            	if(responsePointer != 0)
            		releaseResponse(responsePointer);
            }
		}
		
		private native void releaseResponse(int responsePointer);
		private native int createHttpResponse();
		private native int notifyOnHttpReceiveResponse(HttpResponse response, int requestPointer, int listenerPointer);
		private native int notifyOnHttpReceiveData(int responsePointer, int listenerPointer);
		private native void notifyOnHttpFinishLoading(int responsePointer, int listenerPointer);
		private native void notifyOnHttpLoadingFailed(int responsePointer, int listenerPointer);
		private native boolean isRequestCancelled(int requestPointer);
	}
	
	/// network type
	enum NetworkType {
		NONE,
		UNKNOWN,
		G2,
		EDGE,
		G3,
		WIFI
	};
	
	/// http method
	enum Method {
		GET,
		POST,
		DELETE,
		PUT
	};
	
	/// is wifi connected?
	static boolean isWifiConnected() {
		Context context = Director.getInstance().getContext();
		if(context.checkCallingOrSelfPermission(android.Manifest.permission.ACCESS_WIFI_STATE) == PackageManager.PERMISSION_GRANTED) {
			WifiManager wm = (WifiManager)context.getSystemService(Context.WIFI_SERVICE);
			if(wm != null) {
				WifiInfo info = wm.getConnectionInfo();
				return info != null && info.getSupplicantState() == SupplicantState.COMPLETED;
			} else {
				return false;
			}
		} else {
			Log.w("libwiengine", "you need add ACCESS_WIFI_STATE permission");
			return false;
		}
	}
	
	/// get network type
	static int getNetworkType() {
		NetworkType type = NetworkType.NONE;
		
		if(isWifiConnected()) {
			type = NetworkType.WIFI;
		} else {
			Context context = Director.getInstance().getContext();
			TelephonyManager tm = (TelephonyManager)context.getSystemService(Context.TELEPHONY_SERVICE);
			if(tm == null)
				type = NetworkType.NONE;
			else {
				int t = tm.getNetworkType();
				if(t == TelephonyManager.NETWORK_TYPE_GPRS || t == TelephonyManager.NETWORK_TYPE_UNKNOWN)
					type = NetworkType.G2;
				else if(t == TelephonyManager.NETWORK_TYPE_EDGE)
					type = NetworkType.EDGE;
				else
					type = NetworkType.G3;
			}
		}
	
		return type.ordinal();
	}
	
	/// check proxy existence or not
	static boolean hasProxy() {
		return !TextUtils.isEmpty(Proxy.getDefaultHost());
	}
	
	/// get proxy if has
	static HttpHost getProxy() {
		return new HttpHost(Proxy.getDefaultHost(), Proxy.getDefaultPort());
	}
	
	/// create http client
	static DefaultHttpClient createHttpClient(int timeout) {
		// wifi connected?
		boolean wifi = isWifiConnected();
		
		// create client
		SchemeRegistry schemeRegistry = new SchemeRegistry();
		schemeRegistry.register(new Scheme("http", PlainSocketFactory.getSocketFactory(), 80));
		try {
			schemeRegistry.register(new Scheme("https", new TrustAllSSLSocketFactory(), 443));
		} catch (Exception e) {
		}
		HttpParams params = new BasicHttpParams();
		HttpProtocolParams.setVersion(params, HttpVersion.HTTP_1_1);
		HttpProtocolParams.setContentCharset(params, "UTF-8");
		HttpProtocolParams.setUseExpectContinue(params, false);
		HttpClientParams.setCookiePolicy(params, CookiePolicy.BROWSER_COMPATIBILITY);
		HttpConnectionParams.setConnectionTimeout(params, wifi ? timeout : (timeout * 3));
		HttpConnectionParams.setSoTimeout(params, wifi ? timeout : (timeout * 3));
		ClientConnectionManager ccm = new ThreadSafeClientConnManager(params, schemeRegistry);
		DefaultHttpClient client = new DefaultHttpClient(ccm, params);
		
		if(!wifi && hasProxy()) {
			HttpHost proxy = getProxy();
			if(proxy != null)
				client.getParams().setParameter(ConnRoutePNames.DEFAULT_PROXY, proxy);
		}

		return client;
	}
	
	/// create http request
	static HttpUriRequest createHttpRequest(String url, int method) {
		Method m = Method.values()[method];
		switch(m) {
			case GET:
				return new HttpGet(url);
			case DELETE:
				return new HttpDelete(url);
			case POST:
				return new HttpPost(url);
			case PUT:
				return new HttpPut(url);
			default:
				return null;
		}
	}
	
	/// synchronously execute a http request
	static HttpResponse syncExec(DefaultHttpClient client, HttpUriRequest request) {
		try {
	        HttpResponse response = client.execute(request);
	        return response;
        } catch (Exception e) {
        	return null;
        }
	}
	
	/// asynchronously execute a http request
	static void asyncExec(DefaultHttpClient client, HttpUriRequest request, int requestPointer, int listenerPointer) {
		new HttpClientThread(client, request, requestPointer, listenerPointer).start();
	}
	
	/// close http connection
	static void shutdown(DefaultHttpClient client) {
		try {
	        if(client != null)
	        	client.getConnectionManager().shutdown();
        } catch (Exception e) {
        }
	}
	
	/// get status code of a http response
	static int getStatusCode(HttpResponse response) {
		return response.getStatusLine().getStatusCode();
	}
	
	/// get header of a http response
	static String getHeader(HttpResponse response, String key) {
		Header header = response.getFirstHeader(key);
		if(header == null)
			return null;
		else
			return header.getValue();
	}
	
	/// read all http response body as a string
	static String getBodyAsString(HttpResponse response) {
		try {
	        ByteArrayOutputStream baos = new ByteArrayOutputStream();
	        byte[] buf = new byte[2048];
	        InputStream is = response.getEntity().getContent();
	        for(int i = 0; i != -1; i = is.read(buf))
	        	baos.write(buf, 0, i);
	        return Utilities.getUTF8String(baos.toByteArray());
        } catch (Exception e) {
        	return null;
        }
	}
	
	/// read all http response body as a byte array
	static byte[] getBodyAsBytes(HttpResponse response) {
		try {
	        ByteArrayOutputStream baos = new ByteArrayOutputStream();
	        byte[] buf = new byte[2048];
	        InputStream is = response.getEntity().getContent();
	        for(int i = 0; i != -1; i = is.read(buf))
	        	baos.write(buf, 0, i);
	        return baos.toByteArray();
        } catch (Exception e) {
        	return null;
        }
	}
	
	/// get input stream of http body data
	static InputStream getEntityContentStream(HttpResponse response) {
		try {
	        return response.getEntity().getContent();
        } catch (Exception e) {
        	return null;
        }
	}
	
	/// read http body stream for max bytes
	static int readEntity(InputStream is, byte[] buf) {
		try {
	        int i = is.read(buf);
	        return i;
        } catch (Exception e) {
        	return -2;
        }
	}

	/// add a string part
	static void addStringPart(List<Part> parts, String name, String value) {
		parts.add(new StringPart(name, value));
	}
	
	/// add a file part
	static void addFilePart(List<Part> parts, String name, byte[] blob) {
		parts.add(new FilePart(name, new ByteArrayPartSource("blob", blob)));
	}
	
	/// set multipart entity
	static void setMultipartEntity(HttpEntityEnclosingRequestBase request, List<Part> parts) {
		request.setEntity(new MultipartEntity(parts.toArray(new Part[parts.size()])));
	}
	
	/// set a http url encoded entity for post method
	static void setUrlEncodedEntity(HttpEntityEnclosingRequestBase request, List<NameValuePair> pairs) {
		try {
	        request.setEntity(new UrlEncodedFormEntity(pairs, "utf-8"));
        } catch (UnsupportedEncodingException e) {
        }
	}
	
	/// add name value pair
	static void addNameValuePair(List<NameValuePair> pairs, String name, String value) {
		pairs.add(new BasicNameValuePair(name, value));
	}
}
