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
# build wiengineskeleton lib
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := wiengineskeleton
LOCAL_LDLIBS := -L$(LOCAL_PATH)/../../../libs/$(TARGET_ARCH_ABI) -llog -lGLESv1_CM -lwiengine -llua -lchipmunk -lwisound -lbox2d -ljson -liap -lwinetwork
LOCAL_C_INCLUDES := $(LOCAL_PATH) \
	$(LOCAL_PATH)/../../../jni \
	$(LOCAL_PATH)/../../../jni/chipmunk \
	$(LOCAL_PATH)/../../../jni/chipmunk/constraints \
	$(LOCAL_PATH)/../../../jni/lua \
	$(LOCAL_PATH)/../../../jni/libcurl/include \
	$(LOCAL_PATH)/../../../jni/WiEngine/include \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/abstraction \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/actions \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/afcanim \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/astar \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/bitmapfont \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/box2d \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/chipmunk \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/common \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/dialog \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/easeactions \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/events \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/filters \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/gridactions \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/grid \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/iap \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/json \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/mfs \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/network \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/nodes \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/opengl \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/particle \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/persistence \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/spritex \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/tmx \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/transitions \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/types \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/wisound \
	$(LOCAL_PATH)/../../../jni/WiEngine/include/utils \
	$(LOCAL_PATH)/../../../jni/libxml2/include
LOCAL_SRC_FILES := $(call all-cpp-files-under,.)
	
include $(BUILD_SHARED_LIBRARY)
