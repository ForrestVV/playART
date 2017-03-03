LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

APP_ABI := armeabi

LOCAL_SRC_FILES := hello.cc
LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_CFLAGS += -fPIE -fpermissive
LOCAL_LDFLAGS += -fPIE -pie
LOCAL_MODULE := hello

include $(BUILD_EXECUTABLE)