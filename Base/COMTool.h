
#pragma once

#include "../NieRLibConfig.h"

#include <Windows.h>

#if defined UNICODE || defined _UNICODE
#	define GuidToString GuidToStringW
#	define FormatCoCreateInstanceReturnCodeString FormatCoCreateInstanceReturnCodeStringW
#else
#	define GuidToString GuidToStringA
#	define FormatCoCreateInstanceReturnCodeString FormatCoCreateInstanceReturnCodeStringA
#endif

NIER_CAPI bool GuidToStringA(const GUID & guid, char * pszGUID, const unsigned int uSize);
NIER_CAPI bool GuidToStringW(const GUID & guid, wchar_t * pszGUID, const unsigned int uSize);
NIER_CAPI const char * FormatCoCreateInstanceReturnCodeStringA(const HRESULT hRet);
NIER_CAPI const wchar_t * FormatCoCreateInstanceReturnCodeStringW(const HRESULT hRet);
