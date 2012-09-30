###############################################################################
# build chipmunk lib
###############################################################################

include $(CLEAR_VARS)

LOCAL_MODULE := chipmunk
LOCAL_CFLAGS += -Wno-psabi
LOCAL_LDLIBS := -llog -lGLESv1_CM
LOCAL_C_INCLUDES := $(LOCAL_PATH)/chipmunk \
	$(LOCAL_PATH)/WiEngine/include/chipmunk
LOCAL_SHARED_LIBRARIES := wiengine xml2
LOCAL_SRC_FILES := $(call all-cpp-files-under,chipmunk)

include $(BUILD_SHARED_LIBRARY)