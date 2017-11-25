
#define _NIER_API

#include "COMTool.h"
#include <stdio.h>

bool GuidToStringA(const GUID & guid, char * pszGUID, const unsigned int uSize)
{
	bool bRet = false;

	if (pszGUID && uSize)
	{
		sprintf_s(
			pszGUID,
			uSize,
			"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
			guid.Data1,
			guid.Data2,
			guid.Data3,
			guid.Data4[0],
			guid.Data4[1],
			guid.Data4[2],
			guid.Data4[3],
			guid.Data4[4],
			guid.Data4[5],
			guid.Data4[6],
			guid.Data4[7]);

		bRet = true;
	}

	return bRet;
}

bool GuidToStringW(const GUID & guid, wchar_t * pszGUID, const unsigned int uSize)
{
	bool bRet = false;

	if (pszGUID && uSize)
	{
		swprintf_s(
			pszGUID,
			uSize,
			L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
			guid.Data1,
			guid.Data2,
			guid.Data3,
			guid.Data4[0],
			guid.Data4[1],
			guid.Data4[2],
			guid.Data4[3],
			guid.Data4[4],
			guid.Data4[5],
			guid.Data4[6],
			guid.Data4[7]);

		bRet = true;
	}

	return bRet;
}

const char * FormatCoCreateInstanceReturnCodeStringA(const HRESULT hRet)
{
	if (REGDB_E_CLASSNOTREG == hRet)
	{
		return "REGDB_E_CLASSNOTREG";
	}
	else if (CLASS_E_NOAGGREGATION == hRet)
	{
		return "CLASS_E_NOAGGREGATION";
	}
	else if (E_NOINTERFACE == hRet)
	{
		return "E_NOINTERFACE";
	}
	else if (S_OK == hRet)
	{
		return "S_OK";
	}

	return "Unknown Error";
}

const wchar_t * FormatCoCreateInstanceReturnCodeStringW(const HRESULT hRet)
{
	if (REGDB_E_CLASSNOTREG == hRet)
	{
		return L"REGDB_E_CLASSNOTREG";
	}
	else if (CLASS_E_NOAGGREGATION == hRet)
	{
		return L"CLASS_E_NOAGGREGATION";
	}
	else if (E_NOINTERFACE == hRet)
	{
		return L"E_NOINTERFACE";
	}
	else if (S_OK == hRet)
	{
		return L"S_OK";
	}

	return L"Unknown Error";
}
