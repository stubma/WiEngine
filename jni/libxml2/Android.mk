###########################################################
# build libxml2
###########################################################

include $(CLEAR_VARS)
LOCAL_MODULE := xml2
LOCAL_CFLAGS += -Wno-psabi
LOCAL_C_INCLUDES := $(LOCAL_PATH)/libxml2/include
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/libxml2/include
LOCAL_SRC_FILES := $(call all-c-files-under,libxml2)
	
include $(BUILD_SHARED_LIBRARY)