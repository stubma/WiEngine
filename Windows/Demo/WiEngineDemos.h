#ifndef __WiEngineDemos_H__
#define __WiEngineDemos_H__

// export definition
#if WINDOWS
	#if LIBWIENGINEDEMOS_EXPORTS
		#define WIENGINEDEMOS_API __declspec(dllexport)
	#else
		#define WIENGINEDEMOS_API __declspec(dllimport)
	#endif
#else
	#define WIENGINEDEMOS_API
#endif

extern "C" WIENGINEDEMOS_API void __stdcall startWiEngineDemos(int clazz, int demoId);

#endif