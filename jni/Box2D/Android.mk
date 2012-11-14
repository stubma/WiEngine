###########################################################
# build box2d lib
###########################################################

include $(CLEAR_VARS)

LOCAL_MODULE := box2d
LOCAL_LDLIBS := -llog -lGLESv2
LOCAL_C_INCLUDES := $(LOCAL_PATH)/Box2D \
	$(LOCAL_PATH)/WiEngine/include/box2d
LOCAL_SHARED_LIBRARIES := wiengine xml2
LOCAL_SRC_FILES := $(call all-cpp-files-under,Box2D)
	
include $(BUILD_SHARED_LIBRARY)