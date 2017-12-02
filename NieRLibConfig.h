
#pragma once

#define NR_STATIC_BUILD
#define NR_DYNAMIC_BUILD

#if defined NR_STATIC_BUILD
#	define NR_API
#	define NR_CAPI extern "C"
#else
#	if defined _NR_API
#		define NR_API __declspec(dllexport)
#		define NR_CAPI extern "C" __declspec(dllexport)
#	else
#		define NR_API __declspec(dllimport)
#		define NR_CAPI extern "C" __declspec(dllimport)
#	endif
#endif

#if defined _MSC_VER
#	define NR_PLATFORM_WIN32
#elif defined __GNU__
#	define NR_PLATFORM_LINUX
#else
#	error not support os platform
#endif

#if defined DEBUG || _DEBUG
#	define NR_DEBUG
#endif

#if defined NR_PLATFORM_WIN32
#	include <Windows.h>
#	include <shlwapi.h>
#	include <netcon.h>
#	include <ObjBase.h>
#	include <Psapi.h>
#	include <Tlhelp32.h>
#	include <shobjidl.h>
#	include <shlguid.h>
#	include <gdiplus.h>
#	pragma comment(lib, "Psapi.lib")
#	pragma comment(lib, "Shlwapi.lib")
#	pragma comment(lib, "Ole32.lib")
#	pragma comment(lib, "gdiplus.lib")
#elif defined NR_PLATFORM_LINUX
#	include <pthread.h>
#	include <unistd.h>
#endif

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdarg.h>
#include <list>
#include <string>
#include <vector>
#include <assert.h>
