package com.dbboy.ndk;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import com.dbboy.ndk.jni.JniTest;

public class MainActivity extends AppCompatActivity {


    private String TAG = "--db.boy--jni";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = findViewById(R.id.text);


        JniTest jni = new JniTest();
        tv.setText(jni.stringFromJNI());
        Log.i(TAG, jni.getStringFiled());
        
        Log.i(TAG + "static-", jni.getStaticFiled());
        jni.getMethod();
        jni.getStaticMethod();
        Log.i(TAG+"-获取构造方法-","Date获取时间戳"+ jni.getConstructor());
        
        
        Log.i(TAG,"获取父类方法" );
        jni.getSuperMethod();
        int [] arr = {7,89,2,13,315,7,8,92,12};
        jni.setArray(arr);
        for (int i : arr) {
            Log.i(TAG,i+" ");
        }
    }


}
