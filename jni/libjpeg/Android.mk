###########################################################
# build libjpeg
###########################################################

include $(CLEAR_VARS)
LOCAL_MODULE := jpeg
LOCAL_CFLAGS += -DAVOID_TABLES -O3 -fstrict-aliasing -fprefetch-loop-arrays -fvisibility=hidden
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/libjpeg 
LOCAL_SRC_FILES := $(call all-c-files-under,libjpeg)
	
include $(BUILD_STATIC_LIBRARY)