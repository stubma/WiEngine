#################################################################################
# build cegui lib
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := cegui
LOCAL_CFLAGS += -DCEGUI_STATIC -DHAVE_CONFIG_H
LOCAL_LDLIBS := -L$(LOCAL_PATH)/../system_libs/$(TARGET_ARCH) -llog -lGLESv2 -lz
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/cegui/include \
	$(LOCAL_PATH)/cegui/include/elements \
	$(LOCAL_PATH)/cegui/include/falagard \
	$(LOCAL_PATH)/cegui/include/XMLParserModules/ExpatParser \
	$(LOCAL_PATH)/cegui/include/ImageCodecModules/TGAImageCodec \
	$(LOCAL_PATH)/cegui/include/WindowRendererSets/Falagard \
	$(LOCAL_PATH)/cegui/include/ScriptingModules/LuaScriptModule \
	$(LOCAL_PATH)/cegui/src/minizip
LOCAL_C_INCLUDES := $(LOCAL_EXPORT_C_INCLUDES)
LOCAL_STATIC_LIBRARIES := ft2 expat
LOCAL_SHARED_LIBRARIES := lua
LOCAL_SRC_FILES := $(call all-cpp-files-under,cegui)
	
include $(BUILD_SHARED_LIBRARY)