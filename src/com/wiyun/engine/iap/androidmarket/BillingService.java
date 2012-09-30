/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.wiyun.engine.iap.androidmarket;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.app.PendingIntent;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.Looper;
import android.os.RemoteException;
import android.util.Log;

import com.android.vending.billing.IMarketBillingService;
import com.wiyun.engine.iap.androidmarket.Consts.PurchaseState;
import com.wiyun.engine.iap.androidmarket.Consts.ResponseCode;
import com.wiyun.engine.nodes.Director;


/**
 * This class sends messages to Android Market on behalf of the application by
 * connecting (binding) to the MarketBillingService. The application
 * creates an instance of this class and invokes billing requests through this service.
 *
 * The {@link BillingReceiver} class starts this service to process commands
 * that it receives from Android Market.
 *
 * You should modify and obfuscate this code before using it.
 */
public class BillingService implements ServiceConnection {
    private static final String TAG = "BillingService";
    
    /// public key
    protected static String PUBLIC_KEY = null;
    
    /** The service connection to the remote MarketBillingService. */
    private IMarketBillingService mService;
    
    // observer
    private PurchaseObserver mObserver;

    /**
     * The list of requests that are pending while we are waiting for the
     * connection to the MarketBillingService to be established.
     */
    private LinkedList<BillingRequest> mPendingRequests = new LinkedList<BillingRequest>();

    /**
     * The list of requests that we have sent to Android Market but for which we have
     * not yet received a response code. The HashMap is indexed by the
     * request Id that each request receives when it executes.
     */
    private HashMap<Long, BillingRequest> mSentRequests =
        new HashMap<Long, BillingRequest>();
    
    // value is boolean, true means nonce request is restore transaction request
    private HashMap<Long, Boolean> mNonceTypes = new HashMap<Long, Boolean>();
   
    /**
     * The base class for all requests that use the MarketBillingService.
     * Each derived class overrides the run() method to call the appropriate
     * service interface.  If we are already connected to the MarketBillingService,
     * then we call the run() method directly. Otherwise, we bind
     * to the service and save the request on a queue to be run later when
     * the service is connected.
     */
    abstract class BillingRequest {
        protected long mRequestId;

        public BillingRequest() {
        }

        /**
         * Run the request, starting the connection if necessary.
         * @return true if the request was executed or queued; false if there
         * was an error starting the connection
         */
        public boolean runRequest() {
            if (runIfConnected()) {
                return true;
            }

            if (bindToMarketBillingService()) {
                // Add a pending request to run when the service is connected.
            	if(Consts.DEBUG)
            		Log.d(TAG, "add request to pending list");
                mPendingRequests.add(this);
                runPendingRequests();
                return true;
            }
            return false;
        }

        /**
         * Try running the request directly if the service is already connected.
         * @return true if the request ran successfully; false if the service
         * is not connected or there was an error when trying to use it
         */
        public boolean runIfConnected() {
            if (Consts.DEBUG) {
                Log.d(TAG, getClass().getSimpleName());
            }
            if (mService != null) {
                try {
                    mRequestId = run();
                    if (Consts.DEBUG) {
                        Log.d(TAG, "request id: " + mRequestId);
                    }
                    if (mRequestId >= 0) {
                        mSentRequests.put(mRequestId, this);
                    }
                    return true;
                } catch (RemoteException e) {
                    onRemoteException(e);
                }
            }
            return false;
        }

        /**
         * Called when a remote exception occurs while trying to execute the
         * {@link #run()} method.  The derived class can override this to
         * execute exception-handling code.
         * @param e the exception
         */
        protected void onRemoteException(RemoteException e) {
            Log.w(TAG, "remote billing service crashed");
            mService = null;
        }

        /**
         * The derived class must implement this method.
         * @throws RemoteException
         */
        abstract protected long run() throws RemoteException;

        /**
         * This is called when Android Market sends a response code for this
         * request.
         * @param responseCode the response code
         */
        protected void responseCodeReceived(ResponseCode responseCode) {
        }

        protected Bundle makeRequestBundle(String method) {
            Bundle request = new Bundle();
            request.putString(Consts.BILLING_REQUEST_METHOD, method);
            request.putInt(Consts.BILLING_REQUEST_API_VERSION, 1);
            request.putString(Consts.BILLING_REQUEST_PACKAGE_NAME, Director.getInstance().getContext().getPackageName());
            return request;
        }

        protected void logResponseCode(String method, Bundle response) {
            ResponseCode responseCode = ResponseCode.valueOf(
                    response.getInt(Consts.BILLING_RESPONSE_RESPONSE_CODE));
            if (Consts.DEBUG) {
                Log.e(TAG, method + " received " + responseCode.toString());
            }
        }
    }

    /**
     * Wrapper class that checks if in-app billing is supported.
     */
    class CheckBillingSupported extends BillingRequest {
        public CheckBillingSupported() {
            super();
        }

        @Override
        protected long run() throws RemoteException {
            Bundle request = makeRequestBundle("CHECK_BILLING_SUPPORTED");
            Bundle response = mService.sendBillingRequest(request);
            int responseCode = response.getInt(Consts.BILLING_RESPONSE_RESPONSE_CODE);
            if (Consts.DEBUG) {
                Log.i(TAG, "CheckBillingSupported response code: " +
                        ResponseCode.valueOf(responseCode));
            }
            boolean billingSupported = (responseCode == ResponseCode.RESULT_OK.ordinal());
            ResponseHandler.checkBillingSupportedResponse(billingSupported);
            return Consts.BILLING_RESPONSE_INVALID_REQUEST_ID;
        }
    }

    /**
     * Wrapper class that requests a purchase.
     */
    class RequestPurchase extends BillingRequest {
        public final String mProductId;
        public final String mDeveloperPayload;

        public RequestPurchase(String itemId) {
            this(itemId, null);
        }

        public RequestPurchase(String itemId, String developerPayload) {
            super();
            mProductId = itemId;
            mDeveloperPayload = developerPayload;
        }

        @Override
        protected long run() throws RemoteException {
            Bundle request = makeRequestBundle("REQUEST_PURCHASE");
            request.putString(Consts.BILLING_REQUEST_ITEM_ID, mProductId);
            // Note that the developer payload is optional.
            if (mDeveloperPayload != null) {
                request.putString(Consts.BILLING_REQUEST_DEVELOPER_PAYLOAD, mDeveloperPayload);
            }
            Bundle response = mService.sendBillingRequest(request);
            PendingIntent pendingIntent
                    = response.getParcelable(Consts.BILLING_RESPONSE_PURCHASE_INTENT);
            if (pendingIntent == null) {
                Log.e(TAG, "Error with requestPurchase");
                return Consts.BILLING_RESPONSE_INVALID_REQUEST_ID;
            }

            Intent intent = new Intent();
            ResponseHandler.buyPageIntentResponse(pendingIntent, intent);
            return response.getLong(Consts.BILLING_RESPONSE_REQUEST_ID,
                    Consts.BILLING_RESPONSE_INVALID_REQUEST_ID);
        }

        @Override
        protected void responseCodeReceived(ResponseCode responseCode) {
            ResponseHandler.responseCodeReceived(Director.getInstance().getContext(), this, responseCode);
        }
    }

    /**
     * Wrapper class that confirms a list of notifications to the server.
     */
    class ConfirmNotifications extends BillingRequest {
        final String[] mNotifyIds;

        public ConfirmNotifications(String[] notifyIds) {
            super();
            mNotifyIds = notifyIds;
        }

        @Override
        protected long run() throws RemoteException {
            Bundle request = makeRequestBundle("CONFIRM_NOTIFICATIONS");
            request.putStringArray(Consts.BILLING_REQUEST_NOTIFY_IDS, mNotifyIds);
            Bundle response = mService.sendBillingRequest(request);
            logResponseCode("confirmNotifications", response);
            return response.getLong(Consts.BILLING_RESPONSE_REQUEST_ID,
                    Consts.BILLING_RESPONSE_INVALID_REQUEST_ID);
        }
    }

    /**
     * Wrapper class that sends a GET_PURCHASE_INFORMATION message to the server.
     */
    class GetPurchaseInformation extends BillingRequest {
        long mNonce;
        final String[] mNotifyIds;

        public GetPurchaseInformation(String[] notifyIds) {
            super();
            mNotifyIds = notifyIds;
        }

        @Override
        protected long run() throws RemoteException {
            mNonce = Security.generateNonce();
            mNonceTypes.put(mNonce, false);

            Bundle request = makeRequestBundle("GET_PURCHASE_INFORMATION");
            request.putLong(Consts.BILLING_REQUEST_NONCE, mNonce);
            request.putStringArray(Consts.BILLING_REQUEST_NOTIFY_IDS, mNotifyIds);
            Bundle response = mService.sendBillingRequest(request);
            logResponseCode("getPurchaseInformation", response);
            return response.getLong(Consts.BILLING_RESPONSE_REQUEST_ID,
                    Consts.BILLING_RESPONSE_INVALID_REQUEST_ID);
        }

        @Override
        protected void onRemoteException(RemoteException e) {
            super.onRemoteException(e);
            Security.removeNonce(mNonce);
        }
    }

    /**
     * Wrapper class that sends a RESTORE_TRANSACTIONS message to the server.
     */
    class RestoreTransactions extends BillingRequest {
        long mNonce;

        public RestoreTransactions() {
            super();
        }

        @Override
        protected long run() throws RemoteException {
            mNonce = Security.generateNonce();
            mNonceTypes.put(mNonce, true);

            Bundle request = makeRequestBundle("RESTORE_TRANSACTIONS");
            request.putLong(Consts.BILLING_REQUEST_NONCE, mNonce);
            Bundle response = mService.sendBillingRequest(request);
            logResponseCode("restoreTransactions", response);
            return response.getLong(Consts.BILLING_RESPONSE_REQUEST_ID,
                    Consts.BILLING_RESPONSE_INVALID_REQUEST_ID);
        }

        @Override
        protected void onRemoteException(RemoteException e) {
            super.onRemoteException(e);
            Security.removeNonce(mNonce);
        }

        @Override
        protected void responseCodeReceived(ResponseCode responseCode) {
            ResponseHandler.responseCodeReceived(Director.getInstance().getContext(), this, responseCode);
        }
    }
    
    private static BillingService sInstance = null;
    
    public static final BillingService getInstance() {
    	if(sInstance == null)
    		sInstance = new BillingService();
    	return sInstance;
    }
    
    public static final BillingService getInstanceNoCreate() {
    	return sInstance;
    }
    
    private BillingService() {
		// need prepare looper because it may be created in gl thread
		if(Looper.getMainLooper() != Looper.myLooper())
			Looper.prepare();
		
        // register observer
        mObserver = new PurchaseObserver();
        ResponseHandler.register(mObserver);
    }

    /**
     * Binds to the MarketBillingService and returns true if the bind
     * succeeded.
     * @return true if the bind succeeded; false otherwise
     */
    private boolean bindToMarketBillingService() {
        try {
            if (Consts.DEBUG) {
                Log.i(TAG, "binding to Market billing service");
            }
            boolean bindResult = Director.getInstance().getContext().bindService(
                    new Intent(Consts.MARKET_BILLING_SERVICE_ACTION),
                    this,  // ServiceConnection.
                    Context.BIND_AUTO_CREATE);

            if (bindResult) {
                return true;
            } else {
                Log.e(TAG, "Could not bind to service.");
            }
        } catch (SecurityException e) {
            Log.e(TAG, "Security exception: " + e);
        }
        return false;
    }

    /**
     * Checks if in-app billing is supported.
     * @return true if supported; false otherwise
     */
    public boolean checkBillingSupported() {
        return new CheckBillingSupported().runRequest();
    }

    /**
     * Requests that the given item be offered to the user for purchase. When
     * the purchase succeeds (or is canceled) the {@link BillingReceiver}
     * receives an intent with the action {@link Consts#ACTION_NOTIFY}.
     * Returns false if there was an error trying to connect to Android Market.
     * @param productId an identifier for the item being offered for purchase
     * @param developerPayload a payload that is associated with a given
     * purchase, if null, no payload is sent
     * @return false if there was an error connecting to Android Market
     */
    public boolean requestPurchase(String productId, String developerPayload) {
        return new RequestPurchase(productId, developerPayload).runRequest();
    }

    /**
     * Requests transaction information for all managed items. Call this only when the
     * application is first installed or after a database wipe. Do NOT call this
     * every time the application starts up.
     * @return false if there was an error connecting to Android Market
     */
    public boolean restoreTransactions() {
        return new RestoreTransactions().runRequest();
    }

    /**
     * Confirms receipt of a purchase state change. Each {@code notifyId} is
     * an opaque identifier that came from the server. This method sends those
     * identifiers back to the MarketBillingService, which ACKs them to the
     * server. Returns false if there was an error trying to connect to the
     * MarketBillingService.
     * @param notifyIds a list of opaque identifiers associated with purchase
     * state changes.
     * @return false if there was an error connecting to Market
     */
    private boolean confirmNotifications(String[] notifyIds) {
        return new ConfirmNotifications(notifyIds).runRequest();
    }

    /**
     * Gets the purchase information. This message includes a list of
     * notification IDs sent to us by Android Market, which we include in
     * our request. The server responds with the purchase information,
     * encoded as a JSON string, and sends that to the {@link BillingReceiver}
     * in an intent with the action {@link Consts#ACTION_PURCHASE_STATE_CHANGED}.
     * Returns false if there was an error trying to connect to the MarketBillingService.
     *
     * @param notifyIds a list of opaque identifiers associated with purchase
     * state changes
     * @return false if there was an error connecting to Android Market
     */
    boolean getPurchaseInformation(String[] notifyIds) {
        return new GetPurchaseInformation(notifyIds).runRequest();
    }

    /**
     * Verifies that the data was signed with the given signature, and calls
     * {@link ResponseHandler#purchaseResponse(Context, PurchaseState, String, String, long)}
     * for each verified purchase.
     * @param startId an identifier for the invocation instance of this service
     * @param signedData the signed JSON string (signed, not encrypted)
     * @param signature the signature for the data, signed with the private key
     */
    void purchaseStateChanged(String signedData, String signature) {
    	// get nonce
    	boolean isRestore = false;
    	long nonce = 0;
        try {
	        JSONObject jObject = new JSONObject(signedData);
	        nonce = jObject.optLong("nonce");
	        isRestore = mNonceTypes.containsKey(nonce) && mNonceTypes.get(nonce).booleanValue();
        } catch (JSONException e1) {
        } finally {
        	mNonceTypes.remove(nonce);
        }
        
        // iterate every purchase
        ArrayList<Purchase> purchases = parsePurchase(signedData);
        ArrayList<String> notifyList = new ArrayList<String>();
        for (Purchase vp : purchases) {
            if (vp.notificationId != null) {
                notifyList.add(vp.notificationId);
            }
            ResponseHandler.purchaseResponse(Director.getInstance().getContext(), vp.purchaseState, vp.productId,
                    vp.orderId, vp.purchaseTime, vp.developerPayload, signedData, signature, isRestore);
        }
        
        // confirm notifications
        if (!notifyList.isEmpty()) {
            String[] notifyIds = notifyList.toArray(new String[notifyList.size()]);
            confirmNotifications(notifyIds);
        }
    }
    
    public void verifyPurchase(String productId, String signedData, String signature) {
    	if(Security.verifyPurchase(signedData, signature)) {
    		ResponseHandler.onVerifyPurchaseOK(productId);
    	} else {
    		ResponseHandler.onVerifyPurchaseFailed(productId);
    	}
    }
    
    private ArrayList<Purchase> parsePurchase(String signedData) {
        ArrayList<Purchase> purchases = new ArrayList<Purchase>();
        try {
        	JSONObject jObject = new JSONObject(signedData);
        	JSONArray jTransactionsArray = jObject.optJSONArray("orders");
            if (jTransactionsArray != null) {
                int numTransactions = jTransactionsArray.length();
                for (int i = 0; i < numTransactions; i++) {
                    JSONObject jElement = jTransactionsArray.getJSONObject(i);
                    int response = jElement.getInt("purchaseState");
                    PurchaseState purchaseState = PurchaseState.valueOf(response);
                    String productId = jElement.getString("productId");
                    String packageName = jElement.getString("packageName");
                    long purchaseTime = jElement.getLong("purchaseTime");
                    String orderId = jElement.optString("orderId", "");
                    String notifyId = null;
                    if (jElement.has("notificationId")) {
                        notifyId = jElement.getString("notificationId");
                    }
                    String developerPayload = jElement.optString("developerPayload", null);

                    purchases.add(new Purchase(purchaseState, notifyId, productId,
                            orderId, purchaseTime, developerPayload, packageName));
                }
            }
        } catch (JSONException e) {
            Log.e(TAG, "JSON exception: ", e);
        }
        
        return purchases;
    }

    /**
     * This is called when we receive a response code from Android Market for a request
     * that we made. This is used for reporting various errors and for
     * acknowledging that an order was sent to the server. This is NOT used
     * for any purchase state changes.  All purchase state changes are received
     * in the {@link BillingReceiver} and passed to this service, where they are
     * handled in {@link #purchaseStateChanged(int, String, String)}.
     * @param requestId a number that identifies a request, assigned at the
     * time the request was made to Android Market
     * @param responseCode a response code from Android Market to indicate the state
     * of the request
     */
    void checkResponseCode(long requestId, ResponseCode responseCode) {
        BillingRequest request = mSentRequests.get(requestId);
        if (request != null) {
            if (Consts.DEBUG) {
                Log.d(TAG, request.getClass().getSimpleName() + ": " + responseCode);
            }
            request.responseCodeReceived(responseCode);
        }
        mSentRequests.remove(requestId);
    }

    /**
     * Runs any pending requests that are waiting for a connection to the
     * service to be established.  This runs in the main UI thread.
     */
    private void runPendingRequests() {
    	if(Consts.DEBUG)
    		Log.d(TAG, "runPendingRequests");
    	
    	// if service not ready, return
    	if(mService == null)
    		return;
    	
        int size = mPendingRequests.size();
        for(int i = size - 1; i >= 0; i--) {
        	BillingRequest request = mPendingRequests.get(i);
            if (request.runIfConnected()) {
                mPendingRequests.remove(i);
            }
        }
    }

    /**
     * This is called when we are connected to the MarketBillingService.
     * This runs in the main UI thread.
     */
    public void onServiceConnected(ComponentName name, IBinder service) {
        if (Consts.DEBUG) {
            Log.d(TAG, "Billing service connected");
        }
        mService = IMarketBillingService.Stub.asInterface(service);
        runPendingRequests();
    }

    /**
     * This is called when we are disconnected from the MarketBillingService.
     */
    public void onServiceDisconnected(ComponentName name) {
    	if (Consts.DEBUG) {
    		Log.d(TAG, "Billing service disconnected");
    	}
        mService = null;
    }

    /**
     * Unbinds from the MarketBillingService. Call this when the application
     * terminates to avoid leaking a ServiceConnection.
     */
    public void destroy() {
    	// unregister observer
    	ResponseHandler.unregister(mObserver);
    	mObserver = null;
    	
    	// unbind billing service
        try {
        	Context ctx = Director.getInstance().getContext();
            ctx.unbindService(this);
        } catch (IllegalArgumentException e) {
            // This might happen if the service was disconnected
        }
        
        // nullify self
        sInstance = null;
    }
}
