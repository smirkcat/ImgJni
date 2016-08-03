﻿/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "process.h"
/* Header for class org_img_processing_ImgJni */

#ifndef _Included_org_img_processing_ImgJni
#define _Included_org_img_processing_ImgJni
#ifdef __cplusplus
extern "C" {
#endif
	/*
	* Class:     org_img_processing_ImgJni
	* Method:    processing
	* Signature: (I[B)Ljava/lang/String;
	*/
	JNIEXPORT jstring JNICALL Java_org_img_processing_ImgJni_processing
		(JNIEnv *, jobject, Process *, jbyteArray);

	/*
	* Class:     org_img_processing_ImgJni
	* Method:    initPath
	* Signature: (Ljava/lang/String;)I
	*/
	JNIEXPORT Process * JNICALL Java_org_img_processing_ImgJni_initPath
		(JNIEnv *, jobject, jstring);

	/*
	* Class:     org_img_processing_ImgJni
	* Method:    init
	* Signature: ()I
	*/
	JNIEXPORT Process * JNICALL Java_org_img_processing_ImgJni_init
		(JNIEnv *, jobject);

	/*
	* Class:     org_img_processing_ImgJni
	* Method:    delete
	* Signature: (I)V
	*/
	JNIEXPORT void JNICALL Java_org_img_processing_ImgJni_delete
		(JNIEnv *, jobject, Process *);

	//函数签名定义
	static JNINativeMethod methods[]{
		{ "processing", "(I[B)Ljava/lang/String;", (void *)Java_org_img_processing_ImgJni_processing},
		{ "initPath", "(Ljava/lang/String;)I", (void *)Java_org_img_processing_ImgJni_initPath},
		{ "init", "()I", (void *)Java_org_img_processing_ImgJni_init},
		{ "delete", "(I)V", (void *)Java_org_img_processing_ImgJni_delete},
	};

	static const char * classPathName = "org/img/processing/ImgJni";
	typedef union {
		JNIEnv* env;
		void* venv;
	} UnionJNIEnvToVoid;

	static int registerNativeMethods(JNIEnv* env, const char* className,
		JNINativeMethod* gMethods, int numMethods);

	static int registerNatives(JNIEnv* env);

#ifdef __cplusplus
}
#endif
#endif