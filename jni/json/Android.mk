###########################################################
# build libyajl
###########################################################

include $(LOCAL_PATH)/yajl/Android.mk

###########################################################
# build libjson
###########################################################

include $(CLEAR_VARS)

LOCAL_MODULE := json
LOCAL_LDLIBS := -llog
LOCAL_CFLAGS += -Wno-psabi
LOCAL_C_INCLUDES := $(LOCAL_PATH)/json \
	$(LOCAL_PATH)/WiEngine/include/json
LOCAL_SHARED_LIBRARIES := wiengine
LOCAL_STATIC_LIBRARIES := yajl
LOCAL_SRC_FILES := $(call all-cpp-files-under,json)

include $(BUILD_SHARED_LIBRARY)