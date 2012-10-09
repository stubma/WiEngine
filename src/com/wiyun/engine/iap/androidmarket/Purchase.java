package com.wiyun.engine.iap.androidmarket;

import com.wiyun.engine.iap.androidmarket.Consts.PurchaseState;

class Purchase {
    public PurchaseState purchaseState;
    public String notificationId;
    public String productId;
    public String orderId;
    public long purchaseTime;
    public String developerPayload;
    public String packageName;

    public Purchase(PurchaseState purchaseState, String notificationId,
            String productId, String orderId, long purchaseTime, String developerPayload, String pkg) {
        this.purchaseState = purchaseState;
        this.notificationId = notificationId;
        this.productId = productId;
        this.orderId = orderId;
        this.purchaseTime = purchaseTime;
        this.developerPayload = developerPayload;
        this.packageName = pkg;
    }
}
