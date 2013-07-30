###########################################################
# build libxml2
###########################################################

include $(CLEAR_VARS)
LOCAL_MODULE := xml2
LOCAL_C_INCLUDES := $(LOCAL_PATH)/libxml2/include
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/libxml2/include
LOCAL_SRC_FILES := $(call all-c-files-under,libxml2)
LOCAL_DISABLE_FORMAT_STRING_CHECKS := true
	
include $(BUILD_STATIC_LIBRARY)