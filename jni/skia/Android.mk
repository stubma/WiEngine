###########################################################
# build libft2
###########################################################

include $(LOCAL_PATH)/freetype/Android.mk

###########################################################
# build libexpat
###########################################################

include $(LOCAL_PATH)/expat/Android.mk

######################################################################
# build a minimum skia library
######################################################################

include $(CLEAR_VARS)

LOCAL_MODULE := wiskia
LOCAL_ARM_MODE := arm

# by default hide skia api
LOCAL_CFLAGS += -fvisibility=hidden

# build release
LOCAL_CFLAGS += -DNDEBUG

# need a flag to tell the C side when we're on devices with large memory
# budgets (i.e. larger than the low-end devices that initially shipped)
ifeq ($(ARCH_ARM_HAVE_VFP),true)
    LOCAL_CFLAGS += -DANDROID_LARGE_MEMORY_DEVICE
endif

# enable this if we turn on SK_DEBUG, otherwise we exceed our prelink budget
ifneq ($(ARCH_ARM_HAVE_VFP),true)
	LOCAL_CFLAGS += -DSK_SOFTWARE_FLOAT
endif
ifeq ($(ARCH_ARM_HAVE_NEON),true)
	LOCAL_CFLAGS += -D__ARM_HAVE_NEON
endif

LOCAL_LDLIBS := -L$(LOCAL_PATH)/../system_libs/$(TARGET_ARCH) \
	-L$(LOCAL_PATH)/../system_libs/$(TARGET_ARCH)/2.x \
	-llog -lcutils -lutils
LOCAL_C_INCLUDES := $(LOCAL_PATH)/skia/include/core \
	$(LOCAL_PATH)/skia/src/core \
	$(LOCAL_PATH)/utils \
	$(LOCAL_PATH)/cutils
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/skia/include/core
LOCAL_SRC_FILES := $(call all-cpp-files-under,skia/src/core) \
	$(call all-cpp-files-under,skia/src/ports)

# platform-dependent files
ifeq ($(TARGET_ARCH),arm)
LOCAL_SRC_FILES += skia/src/opts/SkBlitRow_opts_arm.cpp \
	skia/src/opts/SkBitmapProcState_opts_arm.cpp
else
LOCAL_SRC_FILES += skia/src/opts/SkBlitRow_opts_none.cpp \
	skia/src/opts/SkBitmapProcState_opts_none.cpp
endif

LOCAL_STATIC_LIBRARIES := ft2 expat

include $(BUILD_SHARED_LIBRARY)