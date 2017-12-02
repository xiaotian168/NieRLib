
#pragma once

#include "../NieRLibConfig.h"

#if defined NIER_PLATFORM_WIN32

#if defined UNICODE || defined _UNICODE
#	define NR_GuidToString NR_GuidToStringW
#	define NR_FormatCoCreateInstanceReturnCodeString NR_FormatCoCreateInstanceReturnCodeStringW
#else
#	define NR_GuidToString NR_GuidToStringA
#	define NR_FormatCoCreateInstanceReturnCodeString NR_FormatCoCreateInstanceReturnCodeStringA
#endif

NIER_CAPI bool NR_GuidToStringA(const GUID & guid, char * pszGUID, const unsigned int uSize);
NIER_CAPI bool NR_GuidToStringW(const GUID & guid, wchar_t * pszGUID, const unsigned int uSize);

NIER_CAPI const char * NR_FormatCoCreateInstanceReturnCodeStringA(const HRESULT hRet);
NIER_CAPI const wchar_t * NR_FormatCoCreateInstanceReturnCodeStringW(const HRESULT hRet);

#endif
