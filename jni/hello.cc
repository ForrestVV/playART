#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "jni.h"
// #include <JNIHelp.h>

char* art_path = "/system/lib/libart.so";

jint (*JNI_CreateJavaVM_)(JavaVM**, JNIEnv**, void*);
jint (*JNI_GetDefaultJavaVMInitArgs_)(void*);
jint (*JNI_GetCreatedJavaVMs_)(JavaVM**, jsize, jsize*);

int isNull(void* input, char* des){
	if(input == NULL){
		fprintf(stderr, "%s%s\n", des, "NULL");
	}else{
		fprintf(stderr, "%s%s\n", des, " is Not NULL");
	}
}

int main(int argc, char** argv){
	printf("%s\n", "hello art");

	void* handle;
	char* error;

	handle = dlopen(art_path, RTLD_NOW); // RTLD_LAZY
	if(!handle){
		fprintf(stderr, "%s\n", dlerror());
		return 0;
	}else{
		fprintf(stdout, "%s\n", "open art success");
	}

	dlerror();

	void* one = dlsym(handle, "JNI_GetDefaultJavaVMInitArgs");
	void** tmp = reinterpret_cast<void**>(&JNI_GetDefaultJavaVMInitArgs_);
	*tmp = one;
	isNull(JNI_GetDefaultJavaVMInitArgs_, "JNI_GetDefaultJavaVMInitArgs_");

	void* two = dlsym(handle, "JNI_CreateJavaVM");
	void** tmp2 = reinterpret_cast<void**>(&JNI_CreateJavaVM_);
	*tmp2 = two;
	isNull(JNI_CreateJavaVM_, "JNI_CreateJavaVM_");

	void* three = dlsym(handle, "JNI_GetCreatedJavaVMs");
	void** tmp3 = reinterpret_cast<void**>(&JNI_GetCreatedJavaVMs_);
	*tmp3 = three;
	isNull(JNI_GetCreatedJavaVMs_, "JNI_GetCreatedJavaVMs_");

	dlclose(handle);
}