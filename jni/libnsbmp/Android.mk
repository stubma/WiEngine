###########################################################
# build libnsbmp
###########################################################

include $(CLEAR_VARS)
LOCAL_MODULE := nsbmp
LOCAL_LDLIBS := -llog
LOCAL_CFLAGS += -fvisibility=hidden -Wno-psabi
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/libnsbmp
LOCAL_SRC_FILES := $(call all-c-files-under,libnsbmp)
	
include $(BUILD_STATIC_LIBRARY)