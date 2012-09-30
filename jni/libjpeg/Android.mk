###########################################################
# build libjpeg
###########################################################

include $(CLEAR_VARS)
LOCAL_MODULE := jpeg
LOCAL_CFLAGS += -DAVOID_TABLES -O3 -fstrict-aliasing -fprefetch-loop-arrays -fvisibility=hidden -Wno-psabi
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/libjpeg 
LOCAL_SRC_FILES := $(call all-c-files-under,libjpeg)
ifeq ($(TARGET_ARCH),arm)
	LOCAL_CFLAGS += -DARM
	LOCAL_ARM_MODE := arm
	LOCAL_SRC_FILES += libjpeg/jidctfst.S
endif
	
include $(BUILD_STATIC_LIBRARY)