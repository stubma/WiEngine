###########################################################
# build libbz
###########################################################

include $(LOCAL_PATH)/bzip2/Android.mk

###########################################################
# build libft2
###########################################################

include $(CLEAR_VARS)

LOCAL_MODULE := ft2
LOCAL_ARM_MODE := arm 
LOCAL_CFLAGS += -W -Wall -fPIC -DPIC -DDARWIN_NO_CARBON -DFT2_BUILD_LIBRARY -O2 -fvisibility=hidden
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
	freetype/src/pshinter/pshinter.c \
	freetype/src/bdf/bdf.c \
	freetype/src/bzip2/ftbzip2.c \
	freetype/src/cid/type1cid.c \
	freetype/src/gzip/ftgzip.c \
	freetype/src/lzw/ftlzw.c \
	freetype/src/pcf/pcf.c \
	freetype/src/pfr/pfr.c \
	freetype/src/psaux/psaux.c \
	freetype/src/type1/type1.c \
	freetype/src/type42/type42.c \
	freetype/src/winfonts/winfnt.c
LOCAL_STATIC_LIBRARIES := bz

include $(BUILD_STATIC_LIBRARY)
