### 这个例子是示例jni调用c++自定义类
+ 换个意思就是java能通过jni调用c++类
+ 思想是返回c++类的指针地址，调用对应函数时，传入指针地址调用函数
+ 为什么这样，原先是在外部定义全局(静态变量)，这样很不好，特别是在每个类对应参数不一样时有很大缺陷，在多线程处理时也不友好，上层应交由java管理
+ 这种方式还以替换原有的jni函数，方法重新映射关系

### 这个jni c++ 工程项目java代码对应如下
```java
package org.img.processing;

import org.img.utils.JarDllJava;

/**
 * @author smirklijie
 * @time 2016年7月7日17:27:05
 * @see 用于提供java调用c++接口例子
 */
public class ImgJni {
    //函数指针地址，需要init函数初始化
    public int ptrNative;
    
    public ImgJni(){
        ptrNative=init();
    }
    
    public ImgJni(String path){
        ptrNative=initPath(path);
    }
    /**
     * 实现图片的传图，返回相关信息
     * 
     * @param img
     * @return
     */
    public native String processing(int ptrNative,byte[] img);
    /**
     * 预留函数，初始化类和模型文件
     * @param path
     * @return
     */
    public native int initPath(String path);
    /**
     * 预留函数，初始化类
     * @return
     */
    public native int init();
    
    /**
     * 删除c++类，删除前确信不在调用，不然需重新执行init函数给ptrNative赋值
     * 只能执行一次，两次出错，内存释放只有一次
     * @return
     */
    public native void delete(int ptrNative);

    // 静态调用只执行一次，加载本地库 ,编译好的动态放到src/main/resources下面
    // 此处用了我的 项目loaddll来加载，可以用原生方法来加载s
    static {
        try {
            JarDllJava.loadLib("libimgjni", "/dll/", ImgJni.class);
            System.out.println("加载动态库imgjni完成");
        } catch (Exception e) {
            System.err.println("加载动态库imgjni失败，错误日志:" + e.getMessage());
        }
    }
}

```

### 对应c++ 关键代码请查看源文件

### 参考网址
+ <http://www.2cto.com/kf/201207/143036.html>
+ <http://blog.csdn.net/imyfriend/article/details/9117917>