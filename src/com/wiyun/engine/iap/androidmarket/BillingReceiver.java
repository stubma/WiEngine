package com.wiyun.engine.iap.androidmarket;

import com.wiyun.engine.iap.androidmarket.Consts.ResponseCode;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

public class BillingReceiver extends BroadcastReceiver {
	private static final String TAG = "BillingReceiver";
	
	@Override
	public void onReceive(Context context, Intent intent) {
        String action = intent.getAction();
        BillingService bs = BillingService.getInstanceNoCreate();
        if(bs != null) {
            if (Consts.ACTION_NOTIFY.equals(action)) {
                String notifyId = intent.getStringExtra(Consts.NOTIFICATION_ID);
                bs.getPurchaseInformation(new String[] { notifyId });
            } else if (Consts.ACTION_PURCHASE_STATE_CHANGED.equals(action)) {
                String signedData = intent.getStringExtra(Consts.INAPP_SIGNED_DATA);
                String signature = intent.getStringExtra(Consts.INAPP_SIGNATURE);
                bs.purchaseStateChanged(signedData, signature);
            } else if (Consts.ACTION_RESPONSE_CODE.equals(action)) {
                long requestId = intent.getLongExtra(Consts.INAPP_REQUEST_ID, -1);
                int responseCodeIndex = intent.getIntExtra(Consts.INAPP_RESPONSE_CODE,
                        ResponseCode.RESULT_ERROR.ordinal());
                ResponseCode responseCode = ResponseCode.valueOf(responseCodeIndex);
                bs.checkResponseCode(requestId, responseCode);
            } else {
                Log.w(TAG, "unexpected action: " + action);
            }
        }
	}
}
