#include <jni.h>
#include  <android/log.h>
#include <string.h>
#include <stdlib.h>

#define  TAG  "_______DB_BOY__jni"

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
    jobject date = (*env)->NewObject(env, jcls, jmid);
    //通过jcls获取getTime method
    jmethodID getTimeMethod = (*env)->GetMethodID(env, jcls, "getTime", "()J");

    jlong time = (*env)->CallLongMethod(env, date, getTimeMethod);

    LOGI("----native 获取时间戳-%ld", time);

    return time;

}

/*
 * 访问父类方法
 */
JNIEXPORT void JNICALL
Java_com_dbboy_ndk_jni_JniTest_getSuperMethod(JNIEnv *env, jobject instance) {


    jclass cls = (*env)->GetObjectClass(env, instance);
    jfieldID fieldId = (*env)->GetFieldID(env, cls, "child", "Lcom/dbboy/ndk/demo/Parent;");

    //通过属性获取到的对象是子类对象
    //Parent child  = new Child();
    jobject obj = (*env)->GetObjectField(env, instance, fieldId);

    //找到父类对象，传入父类名
    jclass parent = (*env)->FindClass(env, "com/dbboy/ndk/demo/Parent");
    jmethodID methodid = (*env)->GetMethodID(env, parent, "getString", "()V");

    //子类的方法
    (*env)->CallVoidMethod(env, obj, methodid);

    //父类的方法,不覆盖父类方法
    (*env)->CallNonvirtualVoidMethod(env, obj, parent, methodid);

}

int compare(int *a,int *b ){
    return (*a)-(*b);
}

JNIEXPORT void JNICALL
Java_com_dbboy_ndk_jni_JniTest_operateArray(JNIEnv *env, jobject instance, jintArray array) {
    
    jint *ints = (*env)->GetIntArrayElements(env, array, NULL); //只能使用NULL，或者JNI_FALSE
    
    int len = (*env)->GetArrayLength(env,array);
    qsort(ints,len, sizeof(jint),compare);
    
    //同步，如果不加，JAVA中不改变
    // 使用完直接指针后需要立即释放
    (*env)->ReleaseIntArrayElements(env, array, ints, 0);
}

JNIEXPORT jintArray JNICALL
Java_com_dbboy_ndk_jni_JniTest_getArray(JNIEnv *env, jobject instance, jint  len) {
    jintArray  arr = (*env)->NewIntArray(env,len);
    jint *elems = (*env)->GetIntArrayElements(env,arr,NULL);
    
    int i =0;
    for(;i<10;i++){
        elems[i]=i;
    }
    
    (*env)->ReleaseIntArrayElements(env,arr,elems,0);
    return arr ;
}