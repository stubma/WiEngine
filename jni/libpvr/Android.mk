###########################################################
# build libpvr
###########################################################

include $(CLEAR_VARS)
LOCAL_MODULE := pvr
LOCAL_LDLIBS := -llog -lGLESv2
LOCAL_CFLAGS += -DEGL_NOT_PRESENT
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/libpvr \
	$(LOCAL_PATH)/libpvr/OGLES2
LOCAL_C_INCLUDES := $(LOCAL_EXPORT_C_INCLUDES)
LOCAL_SRC_FILES := $(call all-cpp-files-under,libpvr)
	
include $(BUILD_STATIC_LIBRARY)