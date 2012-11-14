###########################################################
# build libpng
###########################################################

include $(LOCAL_PATH)/libpng/Android.mk

###########################################################
# build libjpeg
###########################################################

include $(LOCAL_PATH)/libjpeg/Android.mk

###########################################################
# build libnsbmp
###########################################################

include $(LOCAL_PATH)/libnsbmp/Android.mk

###########################################################
# build libxml2
###########################################################

include $(LOCAL_PATH)/libxml2/Android.mk

###########################################################
# build libkazmath
###########################################################

include $(LOCAL_PATH)/kazmath/Android.mk

#################################################################################
# build wiengine lib
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := wiengine
LOCAL_LDLIBS := -L$(LOCAL_PATH)/../system_libs/$(TARGET_ARCH) -llog -lGLESv2 -lz -ldl -lsqlite
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/WiEngine/include \
	$(LOCAL_PATH)/WiEngine/include/actions \
	$(LOCAL_PATH)/WiEngine/include/afcanim \
	$(LOCAL_PATH)/WiEngine/include/astar \
	$(LOCAL_PATH)/WiEngine/include/bitmapfont \
	$(LOCAL_PATH)/WiEngine/include/common \
	$(LOCAL_PATH)/WiEngine/include/dialog \
	$(LOCAL_PATH)/WiEngine/include/easeactions \
	$(LOCAL_PATH)/WiEngine/include/events \
	$(LOCAL_PATH)/WiEngine/include/filters \
	$(LOCAL_PATH)/WiEngine/include/grid \
	$(LOCAL_PATH)/WiEngine/include/gridactions \
	$(LOCAL_PATH)/WiEngine/include/iap \
	$(LOCAL_PATH)/WiEngine/include/json \
	$(LOCAL_PATH)/WiEngine/include/lua \
	$(LOCAL_PATH)/WiEngine/include/material \
	$(LOCAL_PATH)/WiEngine/include/mesh \
	$(LOCAL_PATH)/WiEngine/include/mfs \
	$(LOCAL_PATH)/WiEngine/include/nodes \
	$(LOCAL_PATH)/WiEngine/include/opengl \
	$(LOCAL_PATH)/WiEngine/include/particle \
	$(LOCAL_PATH)/WiEngine/include/persistence \
	$(LOCAL_PATH)/WiEngine/include/render \
	$(LOCAL_PATH)/WiEngine/include/shader \
	$(LOCAL_PATH)/WiEngine/include/tmx \
	$(LOCAL_PATH)/WiEngine/include/transitions \
	$(LOCAL_PATH)/WiEngine/include/types \
	$(LOCAL_PATH)/WiEngine/include/utils \
	$(LOCAL_PATH)/WiEngine/include/winetwork \
	$(LOCAL_PATH)/WiEngine/impl/common \
	$(LOCAL_PATH)/WiEngine/impl/nodes \
	$(LOCAL_PATH)/WiEngine/impl/platform/android \
	$(LOCAL_PATH)/WiEngine/impl/platform/ios
LOCAL_C_INCLUDES := $(LOCAL_EXPORT_C_INCLUDES) \
	$(LOCAL_PATH)/WiEngine/impl/dialog \
	$(LOCAL_PATH)/WiEngine/impl/events \
	$(LOCAL_PATH)/WiEngine/impl/render \
	$(LOCAL_PATH)/WiEngine/impl/tmx \
	$(LOCAL_PATH)/sqlite3
LOCAL_STATIC_LIBRARIES := png jpeg nsbmp kazmath
LOCAL_SHARED_LIBRARIES := xml2
LOCAL_SRC_FILES := $(call all-cpp-files-under,WiEngine)
	
include $(BUILD_SHARED_LIBRARY)