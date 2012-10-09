###########################################################
# build libft2
###########################################################

include $(CLEAR_VARS)

LOCAL_MODULE := ft2
LOCAL_ARM_MODE := arm 
LOCAL_CFLAGS += -W -Wall -fPIC -DPIC -DDARWIN_NO_CARBON -DFT2_BUILD_LIBRARY -O2 -fvisibility=hidden -Wno-psabi
LOCAL_C_INCLUDES := $(LOCAL_PATH)/freetype/builds \
	$(LOCAL_PATH)/freetype/include
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/freetype/builds \
	$(LOCAL_PATH)/freetype/include
LOCAL_SRC_FILES := freetype/src/base/ftbbox.c \
	freetype/src/base/ftbitmap.c \
	freetype/src/base/ftglyph.c \
	freetype/src/base/ftlcdfil.c \
	freetype/src/base/ftstroke.c \
	freetype/src/base/ftxf86.c \
	freetype/src/base/ftbase.c \
	freetype/src/base/ftsystem.c \
	freetype/src/base/ftinit.c \
	freetype/src/base/ftgasp.c \
	freetype/src/raster/raster.c \
	freetype/src/sfnt/sfnt.c \
	freetype/src/smooth/smooth.c \
	freetype/src/autofit/autofit.c \
	freetype/src/truetype/truetype.c \
	freetype/src/cff/cff.c \
	freetype/src/psnames/psnames.c \
	freetype/src/pshinter/pshinter.c

include $(BUILD_STATIC_LIBRARY)
