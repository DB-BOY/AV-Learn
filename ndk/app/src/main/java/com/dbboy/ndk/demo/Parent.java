package com.dbboy.ndk.demo;

import android.util.Log;

import java.util.Date;

/**
 * Created by DB_BOY on 2019/7/23.</br>
 */
public class Parent {
    
    
    public long getTime(){
        return new Date().getTime();
    }
    
    public void  getString(){
        Log.i( "------db.boy-","Parent class string");
    }
    
}
