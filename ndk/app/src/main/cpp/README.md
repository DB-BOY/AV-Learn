## 总结

### 调用JAVA方法

1. 非静态

  ```void (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);```
  
  传入的是jobject而非jclass
  
2. 静态

  ```void (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);```
  
  传入的是jclass
  

    