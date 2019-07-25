package com.dbboy.ndk.demo;

import android.util.Log;

/**
 * Created by DB_BOY on 2019/7/23.</br>
 */
public class Child extends Parent {

    @Override
    public void getString() {
        Log.i( "------db.boy-", "child string");
    }
}
