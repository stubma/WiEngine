ALL_INCLUDES := $(LOCAL_PATH)/android_adapter \
	$(LOCAL_PATH)/cutils \
	$(LOCAL_PATH)/utils
	 
#################################################################################
# build android adapter layer
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := aal
LOCAL_LDLIBS := -L$(LOCAL_PATH)/../system_libs/$(TARGET_ARCH) \
	-L$(LOCAL_PATH)/../system_libs/$(TARGET_ARCH)/2.x \
	-llog -lcutils -lutils
LOCAL_C_INCLUDES := $(ALL_INCLUDES)
LOCAL_SRC_FILES := $(call all-cpp-files-under,android_adapter)
LOCAL_SHARED_LIBRARIES := wiskia
	
include $(BUILD_SHARED_LIBRARY)

#################################################################################
# build android adapter layer for honeycomb 
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := aal_honeycomb
LOCAL_CFLAGS += -DHONEYCOMB
LOCAL_LDLIBS := -L$(LOCAL_PATH)/../system_libs/$(TARGET_ARCH) \
	-L$(LOCAL_PATH)/../system_libs/$(TARGET_ARCH)/3.x \
	-llog -lcutils -lutils
LOCAL_C_INCLUDES := $(ALL_INCLUDES)
LOCAL_SRC_FILES := $(call all-cpp-files-under,android_adapter)
LOCAL_SHARED_LIBRARIES := wiskia
	
include $(BUILD_SHARED_LIBRARY)

#################################################################################
# build android adapter layer for jelly bean 
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := aal_jellybean
LOCAL_CFLAGS += -DHONEYCOMB
LOCAL_LDLIBS := -L$(LOCAL_PATH)/../system_libs/$(TARGET_ARCH) \
	-L$(LOCAL_PATH)/../system_libs/$(TARGET_ARCH)/4.1 \
	-llog -lcutils -lutils -landroidfw
LOCAL_C_INCLUDES := $(ALL_INCLUDES)
LOCAL_SRC_FILES := $(call all-cpp-files-under,android_adapter)
LOCAL_SHARED_LIBRARIES := wiskia
	
include $(BUILD_SHARED_LIBRARY)