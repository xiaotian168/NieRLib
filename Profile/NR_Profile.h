
#pragma once

#include "../NieRLibConfig.h"

#if defined NIER_ENABLE_PROFILE && defined NR_PLATFORM_WIN32

#ifndef NIER_BEGIN_PROFILE_W
#define NIER_BEGIN_PROFILE_W(_ProfileName) { \
	const wchar_t * pszProfileName = _ProfileName; \
	wchar_t szMessage[MAX_PATH] = { 0 }; \
	LARGE_INTEGER liTickFrequency = { 0 }; \
	LARGE_INTEGER liTickPrev = { 0 }; \
	LARGE_INTEGER liTickNow = { 0 }; \
	LARGE_INTEGER liTickElapse = { 0 }; \
	QueryPerformanceFrequency(&liTickFrequency); \
	QueryPerformanceCounter(&liTickPrev);
#endif

#ifndef NIER_END_PROFILE
#define NIER_END_PROFILE \
	QueryPerformanceCounter(&liTickNow); \
	liTickElapse.QuadPart = liTickNow.QuadPart - liTickPrev.QuadPart; \
	swprintf_s(szMessage, MAX_PATH, L"Profile [%s] In [%lld] Tick [%f] Second \r\n", \
		pszProfileName, \
		liTickElapse.QuadPart, \
		(double)liTickElapse.QuadPart / (double)liTickFrequency.QuadPart); \
	OutputDebugStringW(szMessage); \
}
#endif

#else

#ifndef NIER_BEGIN_PROFILE_W
#	define NIER_BEGIN_PROFILE_W(_ProfileName)
#endif

#ifndef NIER_END_PROFILE
#	define NIER_END_PROFILE
#endif

#endif
