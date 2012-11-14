######################################################################
# build opengl library
######################################################################

include $(CLEAR_VARS)

LOCAL_MODULE := openal
LOCAL_ARM_MODE := arm
LOCAL_LDLIBS := -llog
LOCAL_CFLAGS += -DAL_BUILD_LIBRARY -DAL_ALEXT_PROTOTYPES -fvisibility=hidden
LOCAL_C_INCLUDES := $(LOCAL_PATH)/openal \
	$(LOCAL_PATH)/openal/include \
	$(LOCAL_PATH)/openal/OpenAL32/Include
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/openal/include
LOCAL_SRC_FILES := $(call all-c-files-under,openal)

include $(BUILD_STATIC_LIBRARY)