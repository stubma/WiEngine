#################################################################################
# build libwinetwork
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := winetwork
LOCAL_LDLIBS := -llog
LOCAL_C_INCLUDES := $(LOCAL_PATH)/WiNetwork \
	$(LOCAL_PATH)/WiEngine/include/winetwork
LOCAL_SHARED_LIBRARIES := wiengine
LOCAL_SRC_FILES := $(call all-cpp-files-under,WiNetwork)
	
include $(BUILD_SHARED_LIBRARY)