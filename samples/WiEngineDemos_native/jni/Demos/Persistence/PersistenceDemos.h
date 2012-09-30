#ifndef __PersistenceDemos_h__
#define __PersistenceDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(persistence, CreateDatabaseTest);
DEMO_ENTRY(persistence, PreferenceTest);
DEMO_ENTRY(persistence, SQLFileTest);
DEMO_ENTRY(persistence, TransactionTest);

#ifdef __cplusplus
}
#endif

#endif
