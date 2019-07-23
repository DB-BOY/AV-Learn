package com.dbboy.ndk;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import com.dbboy.ndk.jni.JniTest;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = findViewById(R.id.text);


        JniTest jni = new JniTest();
        tv.setText(jni.stringFromJNI());
        Log.i("----db.boy---", jni.getStringFiled());
        Log.i("----db.boy--static-", jni.getStaticFiled());
        jni.getMethod();
        jni.getStaticMethod();
        Log.i("----db.boy--获取构造方法-","Date获取时间戳"+ jni.getConstructor());
    }


}
