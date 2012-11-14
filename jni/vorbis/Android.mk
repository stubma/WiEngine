###########################################################
# build libvorbis
###########################################################

include $(CLEAR_VARS)

LOCAL_MODULE := vorbis
LOCAL_CFLAGS += -DLITTLE_ENDIAN=1 -DBIG_ENDIAN=2 -DBYTE_ORDER=1 -fvisibility=hidden
ifneq ($(TARGET_ARCH),x86)
	LOCAL_ARM_MODE := arm
	LOCAL_CFLAGS += -D_ARM_ASSEM_
endif
LOCAL_C_INCLUDES := $(LOCAL_PATH)/vorbis
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/vorbis
LOCAL_SRC_FILES := $(call all-c-files-under,vorbis)

include $(BUILD_STATIC_LIBRARY)