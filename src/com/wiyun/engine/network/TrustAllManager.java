/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wiyun.engine.network;

import java.security.cert.X509Certificate;

import javax.net.ssl.X509TrustManager;

public class TrustAllManager implements X509TrustManager {
    /** 
     * Return an array of certificate authority certificates which are trusted 
     * for authenticating peers. 
     * @return <code>X509Certificate[]</code> - Return an array of certificate 
     * authority certificates which are trusted for authenticating peers. 
     */ 
    public X509Certificate[] getAcceptedIssuers() { 
         return( null ); 
    } 

    /** 
     * Given the partial or complete certificate chain provided by the peer, 
     * build a certificate path to a trusted root and return if it can be 
     * validated and is trusted for client SSL authentication based on the 
     * authentication type. The authentication type is determined by the 
     * actual certificate used. For instance, if RSAPublicKey is used, the 
     * authType should be "RSA". Checking is case-sensitive. 
     * @param chain <code>X509Certificate[]</code> the peer certificate chain 
     * @param authType <code>String</code> the authentication type based on 
     * the client certificate 
     */ 
    public void checkClientTrusted( X509Certificate[] chain, String authType ) {         
    } 
     
    /** 
     * Given the partial or complete certificate chain provided by the peer, 
     * build a certificate path to a trusted root and return if it can be 
     * validated and is trusted for server SSL authentication based on the 
     * authentication type. The authentication type is the key exchange 
     * algorithm portion of the cipher suites represented as a String, such 
     * as "RSA", "DHE_DSS". Note: for some exportable cipher suites, the key 
     * exchange algorithm is determined at run time during the handshake. For 
     * instance, for TLS_RSA_EXPORT_WITH_RC4_40_MD5, the authType should be 
     * RSA_EXPORT when an ephemeral RSA key is used for the key exchange, and 
     * RSA when the key from the server certificate is used. Checking is 
     * case-sensitive. 
     * @param chain <code>X509Certificate[]</code> the peer certificate chain 
     * @param authType <code>String</code> the authentication type based on 
     * the client certificate 
     */ 
    public void checkServerTrusted( X509Certificate[] chain, String authType ) {         
    } 
}
