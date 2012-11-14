#################################################################################
# build libmpg123
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := mpg123
LOCAL_CFLAGS += -DNO_32BIT -DNO_REAL -DREAL_IS_FIXED -fvisibility=hidden
ifeq ($(TARGET_ARCH),x86)
	LOCAL_CFLAGS += -DOPT_I386
else
	LOCAL_ARM_MODE := arm
	LOCAL_CFLAGS += -DOPT_ARM
endif
LOCAL_C_INCLUDES := $(LOCAL_PATH)/libmpg123
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/libmpg123
LOCAL_SRC_FILES := libmpg123/compat.c \
	libmpg123/dct64.c \
	libmpg123/dct64_i386.c \
	libmpg123/equalizer.c \
	libmpg123/format.c \
	libmpg123/frame.c \
	libmpg123/icy.c \
	libmpg123/icy2utf8.c \
	libmpg123/id3.c \
	libmpg123/index.c \
	libmpg123/layer1.c \
	libmpg123/layer2.c \
	libmpg123/layer3.c \
	libmpg123/libmpg123.c \
	libmpg123/ntom.c \
	libmpg123/optimize.c \
	libmpg123/parse.c \
	libmpg123/readers.c \
	libmpg123/stringbuf.c \
	libmpg123/synth.c \
	libmpg123/synth_8bit.c \
	libmpg123/synth_arm.S \
	libmpg123/tabinit.c

include $(BUILD_STATIC_LIBRARY)