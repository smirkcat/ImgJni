#include "tojava.h"
#include <string>
#include <iostream>
#include <sstream>

/*
stringTojstring 和 jstringTostring 是为了防止乱码的
*/

// char* To jstring  
jstring stringTojstring(JNIEnv* env, const char* pat)
{
	jclass strClass = env->FindClass("Ljava/lang/String;");
	jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
	jbyteArray bytes = env->NewByteArray(strlen(pat));
	env->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*)pat);
	//此处用GB2312是因为char*中文这个方式保存，如果换成UTF-8认为char*是UTF-8显然不对,linux也测试成功
	jstring encoding = env->NewStringUTF("GB2312");
	return (jstring)env->NewObject(strClass, ctorID, bytes, encoding);
}

// jstring To char*  
char* jstringTostring(JNIEnv* env, jstring jstr)
{
	char* rtn = NULL;
	jclass clsstring = env->FindClass("java/lang/String");
	jstring strencode = env->NewStringUTF("GB2312");
	jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
	jsize alen = env->GetArrayLength(barr);
	jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
	if (alen > 0)
	{
		rtn = (char*)malloc(alen + 1);
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	env->ReleaseByteArrayElements(barr, ba, 0);
	return rtn;
}

JNIEXPORT jstring JNICALL Java_org_img_processing_ImgJni_processing
(JNIEnv *env, jobject obj, jbyteArray img){
	jboolean isCopy = JNI_FALSE;
	int size = env->GetArrayLength(img);
	jbyte * imagebuffer = env->GetByteArrayElements(img, &isCopy);
	if (NULL == imagebuffer)
	{
		return NULL;
	}
	//此处前面通用

	/* //通用函数 opencv环境
	Mat src = imdecode(Mat(1, size, CV_8U, imagebuffer), IMREAD_COLOR);
	if (!src.data)
	return NULL;

	//在这里做相关处理
	string result=somefunc(src)
	*/
	//此处只是测试
	std::stringstream ss;
	std::string str;
	ss << size;
	ss >> str;
	std::string result = "result,图片byte长度为"+str;
	
	//此处后面通用
	env->ReleaseByteArrayElements(img, imagebuffer, JNI_COMMIT);
	jstring  jresult = stringTojstring(env, result.c_str());
	return jresult;
}

