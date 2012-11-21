LOCAL_PATH := $(call my-dir)

###########################################################
## Find all of files under the named directories.
###########################################################

define all-cpp-files-under
$(patsubst ./%,%, \
  $(shell cd $(LOCAL_PATH) ; \
          find $(1) -name "*.cpp" -and -not -name ".*") \
 )
endef

#################################################################################
# build wienginedemos lib
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := wienginedemos
LOCAL_LDLIBS := -L$(LOCAL_PATH)/../../../libs/$(TARGET_ARCH_ABI) -llog -ldl -lGLESv2 -lwiengine -llua -lwisound -lbox2d -lwinetwork -ljson -liap
LOCAL_C_INCLUDES := $(LOCAL_PATH)/Demos \
	$(LOCAL_PATH)/../../../jni \
	$(LOCAL_PATH)/../../../jni/lua \
	$(LOCAL_PATH)/../../../jni/lua/tolua++ \
	$(LOCAL_PATH)/../../../jni/kazmath/include \
	$(LOCAL_PATH)/../../../jni/WiEngine/include \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/actions \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/afcanim \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/astar \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/bitmapfont \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/box2d \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/common \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/dialog \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/easeactions \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/events \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/filters \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/grid \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/gridactions \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/json \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/lua \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/iap \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/mfs \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/material \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/mesh \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/nodes \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/opengl \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/particle \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/persistence \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/render \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/shader \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/tmx \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/transitions \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/types \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/winetwork \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/wisound \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/utils \
	$(LOCAL_PATH)/../../../jni/libxml2/include
LOCAL_SRC_FILES := $(call all-cpp-files-under,Demos)
	
include $(BUILD_SHARED_LIBRARY)
