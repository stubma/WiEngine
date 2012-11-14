###########################################################
# build libpng
###########################################################

include $(CLEAR_VARS)
LOCAL_MODULE := png
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/libpng
LOCAL_SRC_FILES := $(call all-c-files-under,libpng)
	
include $(BUILD_STATIC_LIBRARY)