package com.dbboy.ndk.jni;

import android.util.Log;

/**
 * Created by DB_BOY on 2019/7/1.</br>
 */
public class JniTest {


    static {
        System.loadLibrary("native-lib");
    }

    public String strJava="strJava";
    private static String staticProperty="static Property";

    public native String stringFromJNI();
    public native String getStringFiled();
    public native String getStaticFiled();
    public native void getMethod();
    public native void getStaticMethod();

    /**
     * 获取构造方法，Data获取时间戳
     */
    public native long getConstructor();
    
    
    
    
    private void callByNative(){
        Log.i("----","call by native");
    }
    private static void callStaticByNative(String input){
        Log.i("----","call by native： "+input);
    }

}
