## 总结

### 调用JAVA方法

1. 非静态

  ```void (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);```
  
  传入的是jobject而非jclass
  
2. 静态

  ```void (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);```
  
  传入的是jclass

### 获取MethodID 与 CallMethod 的区别
        
   ```(*env)->GetMethodID(JNIEnv*, jclass, const char*, const char*);```
   使用jclass获取方法ID
   
   ```(*env)->CallLongMethod(JNIEnv*, jobject, jmethodID, ...);```
   使用jobject对象来调用对应的方法

    