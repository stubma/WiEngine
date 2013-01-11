###########################################################
# build libpvr
###########################################################

include $(CLEAR_VARS)
LOCAL_MODULE := pvr
LOCAL_LDLIBS := -llog
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/libpvr
LOCAL_SRC_FILES := $(call all-cpp-files-under,libpvr)
	
include $(BUILD_STATIC_LIBRARY)