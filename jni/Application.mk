# Build for all arch ndk supported
APP_ABI := all
APP_CFLAGS += -Os

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
	APP_CFLAGS += -mfloat-abi=hard
endif

# enable rtti
APP_STL := gnustl_static
APP_CPPFLAGS += -frtti -Wno-psabi
