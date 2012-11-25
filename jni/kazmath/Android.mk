#################################################################################
# build kazmath lib
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := kazmath
ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
    LOCAL_CFLAGS += -D__ARM_NEON__ -mfpu=neon
endif
LOCAL_LDLIBS := -llog
LOCAL_C_INCLUDES := $(LOCAL_PATH)/kazmath/include
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/kazmath/include
LOCAL_SRC_FILES := $(call all-c-files-under,kazmath)
	
include $(BUILD_SHARED_LIBRARY)
