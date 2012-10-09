#include <windows.h>
#include "WiEngineDemos.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call)	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}

static bool s_isDemoStarted = false;
DWORD WINAPI demoProc(LPVOID lpParameter);
extern void startDemo(int clazz, int id);

typedef struct wyDemoEntryInfo {
	int clazz;
	int id;
} wyDemoEntryInfo;

DWORD WINAPI demoProc(LPVOID lpParameter) {
	wyDemoEntryInfo* info = (wyDemoEntryInfo*)lpParameter;
	startDemo(info->clazz, info->id);
	return 0;
}

#ifdef __cplusplus
extern "C" {
#endif

void __stdcall startWiEngineDemos(int clazz, int demoId) {
	if(s_isDemoStarted) {
		return;
	}

	s_isDemoStarted = true;
	wyDemoEntryInfo info = {clazz, demoId};

	HANDLE hThread = CreateThread(NULL, 0, demoProc, &info, 0, NULL);
	if(hThread != NULL) {
		WaitForSingleObject(hThread, INFINITE);
	}
	s_isDemoStarted = false;
}

#ifdef __cplusplus
}
#endif