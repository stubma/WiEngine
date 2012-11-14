# backend macro
# possible value: openal or mediaplayer or opensl
BACKEND := mediaplayer

#################################################################################
# build openal
#################################################################################

ifeq ($(BACKEND),openal)
include $(LOCAL_PATH)/openal/Android.mk
endif

#################################################################################
# build libmpg123
#################################################################################

ifneq ($(BACKEND),mediaplayer)
include $(LOCAL_PATH)/libmpg123/Android.mk
endif

#################################################################################
# build vorbis
#################################################################################

ifneq ($(BACKEND),mediaplayer)
include $(LOCAL_PATH)/vorbis/Android.mk
endif

#################################################################################
# build wisound lib
#################################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := wisound
LOCAL_LDLIBS := -llog
ifeq ($(BACKEND),openal)
	LOCAL_CFLAGS += -DBACKEND_OPENAL
	LOCAL_STATIC_LIBRARIES := mpg123 vorbis openal
endif
ifeq ($(BACKEND),opensl)
	LOCAL_CFLAGS += -DBACKEND_OPENSL
	LOCAL_LDLIBS += -lOpenSLES
	LOCAL_STATIC_LIBRARIES := mpg123 vorbis
endif
ifeq ($(BACKEND),mediaplayer)
	LOCAL_CFLAGS += -DBACKEND_MEDIAPLAYER
endif
LOCAL_C_INCLUDES := $(LOCAL_PATH)/WiEngine/include/wisound \
	$(LOCAL_PATH)/WiSound \
	$(LOCAL_PATH)/WiSound/backends/mediaplayer \
	$(LOCAL_PATH)/WiSound/backends/openal \
	$(LOCAL_PATH)/WiSound/backends/opensl
LOCAL_SHARED_LIBRARIES := wiengine
LOCAL_SRC_FILES := $(call all-cpp-files-under,WiSound)

include $(BUILD_SHARED_LIBRARY)