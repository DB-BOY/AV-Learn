#include <jni.h>
#include  <android/log.h>
#include <string.h>

#define  TAG  "__DB_BOY__"

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)

/*
 * 访问属性
 */
JNIEXPORT jstring JNICALL
Java_com_dbboy_ndk_jni_JniTest_stringFromJNI(JNIEnv *env, jobject jobj) {

    char *returnValue = "hello from JNI";
    LOGI("user info----%c--", *"HelloWorld");

    return (*env)->NewStringUTF(env, returnValue);
}

/*
 * 访问属性
 */
JNIEXPORT jstring JNICALL
Java_com_dbboy_ndk_jni_JniTest_getStringFiled(JNIEnv *env, jobject jobj) {

    //jobj是jniTest对象
    jclass cls = (*env)->GetObjectClass(env, jobj);
    //获取属性名，属性值
    jfieldID jfid = (*env)->GetFieldID(env, cls, "strJava", "Ljava/lang/String;");

    jstring jstr = (*env)->GetObjectField(env, jobj, jfid);
    LOGI("db_boy----jstr:%s ", &jstr);

    char *c_s = (*env)->GetStringUTFChars(env, jstr, JNI_FALSE);

    LOGI("db_boy----c_s:%s ", &c_s);

    char x[20] = "and native ";
    strcat(x, c_s);
    LOGI("db_boy---- :%s", &x);
    jstring returnValue = (*env)->NewStringUTF(env, x);

    return returnValue;
}

/*
 * 访问静态属性
 */
JNIEXPORT jstring JNICALL
Java_com_dbboy_ndk_jni_JniTest_getStaticFiled(JNIEnv *env, jobject jobj) {

    jclass jcls = (*env)->GetObjectClass(env, jobj);
    jfieldID jfid = (*env)->GetStaticFieldID(env, jcls, "staticProperty", "Ljava/lang/String;");
    jstring js = (*env)->GetStaticObjectField(env, jcls, jfid);

    LOGI("db_boy----js---:%s ", &js);

    return js;
}

/*
 * 访问方法
 */
JNIEXPORT void JNICALL
Java_com_dbboy_ndk_jni_JniTest_getMethod(JNIEnv *env, jobject jobj) {
    jclass jcls = (*env)->GetObjectClass(env, jobj);
    jmethodID jmid = (*env)->GetMethodID(env, jcls, "callByNative", "()V");
    (*env)->CallVoidMethod(env, jobj, jmid);
}

/*
 * 访问静态方法
 */JNIEXPORT void JNICALL
Java_com_dbboy_ndk_jni_JniTest_getStaticMethod(JNIEnv *env, jobject instance) {
    jclass jcls = (*env)->GetObjectClass(env, instance);
    jmethodID jmid = (*env)->GetStaticMethodID(env, jcls, "callStaticByNative", "(Ljava/lang/String;)V");
    jstring js = (*env)->NewStringUTF(env, " static method from JNI");
    LOGI("db_boy----访问静态方法 ");

    (*env)->CallStaticVoidMethod(env, jcls, jmid, js);
}

/*
 * 访问构造方法
 */
JNIEXPORT jlong JNICALL
Java_com_dbboy_ndk_jni_JniTest_getConstructor(JNIEnv *env, jobject jobj) {
    //根据包名类名，获取到类
    jclass jcls = (*env)->FindClass(env, "java/util/Date");
    //获取签名
    // javap -s -p java.util.Date 
    //找到无参构造方法
    jmethodID jmid = (*env)->GetMethodID(env, jcls, "<init>", "()V");

    //实例化对象
    jobject  date = (*env)->NewObject(env,jcls,jmid);
    //通过jcls获取getTime method
    jmethodID  getTimeMethod= (*env)->GetMethodID(env, jcls, "getTime","()J");
    
    jlong time = (*env)->CallLongMethod(env,date,getTimeMethod);
    
    LOGI("----native 获取时间戳-%ld",time);

    return time;

}