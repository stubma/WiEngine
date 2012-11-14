###########################################################
# build libiap
###########################################################

include $(CLEAR_VARS)

LOCAL_MODULE := iap
LOCAL_LDLIBS := -llog
LOCAL_C_INCLUDES := $(LOCAL_PATH)/iap \
	$(LOCAL_PATH)/iap/backends/androidmarket \
	$(LOCAL_PATH)/WiEngine/include/iap
LOCAL_SHARED_LIBRARIES := wiengine
LOCAL_SRC_FILES := $(call all-cpp-files-under,iap)

include $(BUILD_SHARED_LIBRARY)