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
WIENGINE_ROOT := $(LOCAL_PATH)/../../..
WIENGINE_LIBS := $(WIENGINE_ROOT)/libs
WIENGINE_JNI := $(WIENGINE_ROOT)/jni
LOCAL_LDLIBS := -L$(WIENGINE_LIBS)/$(TARGET_ARCH_ABI) -llog -lGLESv2 -lwiengine -llua -lwisound -lbox2d -lwinetwork -ljson -liap -lcegui
LOCAL_C_INCLUDES := $(LOCAL_PATH)/Demos \
	$(WIENGINE_JNI) \
	$(WIENGINE_JNI)/lua \
	$(WIENGINE_JNI)/lua/tolua++ \
	$(WIENGINE_JNI)/kazmath/include \
	$(WIENGINE_JNI)/WiEngine/include \
	$(WIENGINE_JNI)/WiEngine/include/actions \
	$(WIENGINE_JNI)/WiEngine/include/afcanim \
	$(WIENGINE_JNI)/WiEngine/include/astar \
	$(WIENGINE_JNI)/WiEngine/include/bitmapfont \
	$(WIENGINE_JNI)/WiEngine/include/box2d \
	$(WIENGINE_JNI)/WiEngine/include/cegui \
	$(WIENGINE_JNI)/WiEngine/include/common \
	$(WIENGINE_JNI)/WiEngine/include/dialog \
	$(WIENGINE_JNI)/WiEngine/include/easeactions \
	$(WIENGINE_JNI)/WiEngine/include/events \
	$(WIENGINE_JNI)/WiEngine/include/filters \
	$(WIENGINE_JNI)/WiEngine/include/grid \
	$(WIENGINE_JNI)/WiEngine/include/gridactions \
	$(WIENGINE_JNI)/WiEngine/include/json \
	$(WIENGINE_JNI)/WiEngine/include/lua \
	$(WIENGINE_JNI)/WiEngine/include/iap \
	$(WIENGINE_JNI)/WiEngine/include/material \
	$(WIENGINE_JNI)/WiEngine/include/mesh \
	$(WIENGINE_JNI)/WiEngine/include/model \
	$(WIENGINE_JNI)/WiEngine/include/nodes \
	$(WIENGINE_JNI)/WiEngine/include/opengl \
	$(WIENGINE_JNI)/WiEngine/include/particle \
	$(WIENGINE_JNI)/WiEngine/include/persistence \
	$(WIENGINE_JNI)/WiEngine/include/render \
	$(WIENGINE_JNI)/WiEngine/include/shader \
	$(WIENGINE_JNI)/WiEngine/include/tmx \
	$(WIENGINE_JNI)/WiEngine/include/transitions \
	$(WIENGINE_JNI)/WiEngine/include/types \
	$(WIENGINE_JNI)/WiEngine/include/winetwork \
	$(WIENGINE_JNI)/WiEngine/include/wisound \
	$(WIENGINE_JNI)/WiEngine/include/utils \
	$(WIENGINE_JNI)/libxml2/include \
	$(WIENGINE_JNI)/libpvr \
	$(WIENGINE_JNI)/cegui/include
LOCAL_SRC_FILES := $(call all-cpp-files-under,Demos)
	
include $(BUILD_SHARED_LIBRARY)
