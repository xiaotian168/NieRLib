
#pragma once

#include <Windows.h>

#if defined UNICODE || defined _UNICODE
#	define GuidToString GuidToStringW
#	define FormatCoCreateInstanceReturnCodeString FormatCoCreateInstanceReturnCodeStringW
#else
#	define GuidToString GuidToStringA
#	define FormatCoCreateInstanceReturnCodeString FormatCoCreateInstanceReturnCodeStringA
#endif

extern bool GuidToStringA(const GUID & guid, char * pszGUID, const unsigned int uSize);
extern bool GuidToStringW(const GUID & guid, wchar_t * pszGUID, const unsigned int uSize);
extern const char * FormatCoCreateInstanceReturnCodeStringA(const HRESULT hRet);
extern const wchar_t * FormatCoCreateInstanceReturnCodeStringW(const HRESULT hRet);
