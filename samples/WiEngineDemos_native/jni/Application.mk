# Build all arch machine code.
APP_ABI := armeabi

# enable rtti
APP_STL := gnustl_static
APP_CPPFLAGS := -frtti -fexceptions -Wno-psabi