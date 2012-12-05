###########################################################
# build bzip2 lib
###########################################################

include $(CLEAR_VARS)

LOCAL_MODULE := bz
LOCAL_CFLAGS += -O3 -DUSE_MMAP
LOCAL_C_INCLUDES := $(LOCAL_PATH)/bzip2
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/bzip2
LOCAL_SRC_FILES := $(call all-c-files-under,bzip2)
	
include $(BUILD_STATIC_LIBRARY)