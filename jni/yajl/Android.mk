###########################################################
# build libyajl
###########################################################

include $(CLEAR_VARS)

LOCAL_MODULE := yajl
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_C_INCLUDES := $(LOCAL_PATH)/yajl/src \
	$(LOCAL_PATH)/yajl/include
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/yajl/include
LOCAL_SRC_FILES := $(call all-c-files-under,yajl)

include $(BUILD_STATIC_LIBRARY)