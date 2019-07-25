package com.dbboy.ndk.jni;

import android.util.Log;

import com.dbboy.ndk.demo.Child;
import com.dbboy.ndk.demo.Parent;

/**
 * Created by DB_BOY on 2019/7/1.</br>
 */
public class JniTest {


    private static String staticProperty = "static Property";

    static {
        System.loadLibrary("native-lib");
    }

    public String strJava = "strJava";

    public Parent child = new Child();
    
    
    private static void callStaticByNative(String input) {
        Log.i("----", "call by native： " + input);
    }

    public native String stringFromJNI();

    public native String getStringFiled();

    public native String getStaticFiled();

    public native void getMethod();

    public native void getStaticMethod();

    /**
     * 获取构造方法，Data获取时间戳
     */
    public native long getConstructor();

    public native void getSuperMethod();
    public native void setArray(int[] ints);

    private void callByNative() {
        Log.i("----", "call by native");
    }

}
