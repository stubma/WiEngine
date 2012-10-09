#################################################################################
# build wiengine binding lib
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := wiengine_binding
LOCAL_LDLIBS := -llog
LOCAL_CFLAGS += -Wno-psabi
LOCAL_SHARED_LIBRARIES := wiengine
LOCAL_SRC_FILES := $(call all-cpp-files-under,WiEngine_binding)
	
include $(BUILD_SHARED_LIBRARY)