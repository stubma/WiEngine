###########################################################
# build expat lib
###########################################################

include $(CLEAR_VARS)

LOCAL_MODULE := expat
LOCAL_CFLAGS += -Wall -Wmissing-prototypes -Wstrict-prototypes -fexceptions -DHAVE_EXPAT_CONFIG_H
LOCAL_C_INCLUDES := $(LOCAL_PATH)/expat
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/expat
LOCAL_SRC_FILES := expat/xmlparse.c \
	expat/xmlrole.c \
	expat/xmltok.c
	
include $(BUILD_STATIC_LIBRARY)