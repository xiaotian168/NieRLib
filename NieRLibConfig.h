
#pragma once

#if defined _MSC_VER
#	define NIER_PLATFORM_WIN32
#elif defined __GNU__
#	define NIER_PLATFORM_LINUX
#else
#	error not support os platform
#endif

/**
** @brief 下面两个宏决定编译成静态库还是动态库
*/
#define NIER_STATIC_BUILD
//#define NIER_DYNAMIC_BUILD

#if defined NIER_STATIC_BUILD
#	define NIER_API
#	define NIER_CAPI
#else
#	if defined _NIER_API
#		define NIER_API __declspec(dllexport)
#		define NIER_CAPI extern "C" __declspec(dllexport)
#	else
#		define NIER_API __declspec(dllimport)
#		define NIER_CAPI extern "C" __declspec(dllimport)
#	endif
#endif
