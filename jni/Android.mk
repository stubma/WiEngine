LOCAL_PATH := $(call my-dir)

###########################################################
## Find all of files under the named directories.
###########################################################

define all-files-under
$(patsubst ./%,%, \
  $(shell cd $(LOCAL_PATH) ; \
          find $(1) -name "$(2)" -and -not -name ".*") \
 )
endef

define all-cpp-files-under
$(call all-files-under,$(1),*.cpp)
endef

define all-c-files-under
$(call all-files-under,$(1),*.c)
endef

define all-S-files-under
$(call all-files-under,$(1),*.S)
endef

###########################################################
# build libwiskia
###########################################################

include $(LOCAL_PATH)/skia/Android.mk

###########################################################
# build wiengine lib
###########################################################

include $(LOCAL_PATH)/WiEngine/Android.mk

###########################################################
# build android adapter layer
###########################################################

include $(LOCAL_PATH)/android_adapter/Android.mk

###########################################################
# build wisound lib
###########################################################

include $(LOCAL_PATH)/WiSound/Android.mk

###########################################################
# build box2d lib
###########################################################

include $(LOCAL_PATH)/Box2D/Android.mk

###########################################################
# build lua lib
###########################################################

include $(LOCAL_PATH)/lua/Android.mk

###########################################################
# build winetwork lib
###########################################################

include $(LOCAL_PATH)/WiNetwork/Android.mk

###########################################################
# build json lib
###########################################################

include $(LOCAL_PATH)/json/Android.mk

###########################################################
# build iap lib
###########################################################

include $(LOCAL_PATH)/iap/Android.mk