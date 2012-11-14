###########################################################
# build lua lib
###########################################################

include $(CLEAR_VARS)
LOCAL_MODULE := lua
LOCAL_LDLIBS := -llog
LOCAL_CFLAGS += -DTOLUA_RELEASE -fpermissive
LOCAL_C_INCLUDES := $(LOCAL_PATH)/lua \
	$(LOCAL_PATH)/lua/tolua++ \
	$(LOCAL_PATH)/WiEngine/include/lua
LOCAL_SHARED_LIBRARIES := wiengine
LOCAL_SRC_FILES := $(call all-c-files-under,lua) \
	$(call all-cpp-files-under,lua)
	
include $(BUILD_SHARED_LIBRARY)