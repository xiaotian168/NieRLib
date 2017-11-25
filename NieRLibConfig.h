
#pragma once

#define NIER_STATIC_BUILD
//#define NIER_DYNAMIC_BUILD

#if defined NIER_STATIC_BUILD
#	define NIER_API
#	define NIER_CAPI extern "C"
#else
#	if defined _NIER_API
#		define NIER_API __declspec(dllexport)
#		define NIER_CAPI extern "C" __declspec(dllexport)
#	else
#		define NIER_API __declspec(dllimport)
#		define NIER_CAPI extern "C" __declspec(dllimport)
#	endif
#endif

#if defined _MSC_VER
#	define NIER_PLATFORM_WIN32
#elif defined __GNU__
#	define NIER_PLATFORM_LINUX
#else
#	error not support os platform
#endif

#if defined DEBUG || _DEBUG
#	define NIER_DEBUG
#endif

#if defined NIER_PLATFORM_WIN32
#	include <Windows.h>
#	include <shlwapi.h>
#	include <netcon.h>
#	include <ObjBase.h>
#	include <Psapi.h>
#	include <Tlhelp32.h>
#	include <shobjidl.h>
#	include <shlguid.h>
#	pragma comment(lib, "Psapi.lib")
#	pragma comment(lib, "Shlwapi.lib")
#	pragma comment(lib, "Ole32.lib")
#elif defined NIER_PLATFORM_LINUX
#	include <pthread.h>
#	include <unistd.h>
#endif

#include <stdio.h>
#include <malloc.h>
#include <list>
#include <string>
#include <assert.h>
