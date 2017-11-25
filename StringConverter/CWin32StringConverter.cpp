
#define _NIER_API

#include "CWin32StringConverter.h"
#include "../MemoryAllocator/IMemoryAllocator.h"

#if defined NIER_PLATFORM_WIN32

CWin32StringConverter * CWin32StringConverter::Make(void)
{
	return new CWin32StringConverter();
}

CWin32StringConverter::CWin32StringConverter()
{
	m_pMemAllocator = 0;
}

CWin32StringConverter::~CWin32StringConverter()
{
	SAFE_RELEASE(m_pMemAllocator);
}

void CWin32StringConverter::SetMemoryAllocator(IMemoryAllocator * pAllocator)
{
	if (m_pMemAllocator != pAllocator)
	{
		SAFE_RELEASE(m_pMemAllocator);
		m_pMemAllocator = pAllocator;
		SAFE_ADDREF(m_pMemAllocator);
	}
}

IMemoryAllocator * CWin32StringConverter::GetMemoryAllocator(void) const
{
	SAFE_ADDREF(m_pMemAllocator);

	return m_pMemAllocator;
}

bool CWin32StringConverter::UnicodeToMultiByte(const wchar_t * pszUnicodeString, char ** ppszMultiByteString)
{
	bool bRet = false;

	if (m_pMemAllocator && pszUnicodeString && ppszMultiByteString)
	{
		auto nLenMultiByteString = WideCharToMultiByte(CP_ACP, 0, pszUnicodeString, -1, 0, 0, 0, 0);
		if (nLenMultiByteString)
		{
			*ppszMultiByteString = static_cast<char *>(m_pMemAllocator->Alloc(MultiByteCharSize * (nLenMultiByteString + 1)));
			if (*ppszMultiByteString)
			{
				if (WideCharToMultiByte(CP_ACP, 0, pszUnicodeString, -1, *ppszMultiByteString, nLenMultiByteString + 1, 0, 0))
				{
					(*ppszMultiByteString)[nLenMultiByteString] = '\0';

					bRet = true;
				}
			}
		}
	}

	return bRet;
}

bool CWin32StringConverter::UnicodeToUTF8MultiByte(const wchar_t * pszUnicodeString, char ** ppszMultiByteString)
{
	bool bRet = false;

	if (m_pMemAllocator && pszUnicodeString && ppszMultiByteString)
	{
		auto nLenMultiByteString = WideCharToMultiByte(CP_UTF8, 0, pszUnicodeString, -1, 0, 0, 0, 0);
		if (nLenMultiByteString)
		{
			*ppszMultiByteString = static_cast<char *>(m_pMemAllocator->Alloc(MultiByteCharSize * (nLenMultiByteString + 1)));
			if (*ppszMultiByteString)
			{
				if (WideCharToMultiByte(CP_UTF8, 0, pszUnicodeString, -1, *ppszMultiByteString, nLenMultiByteString + 1, 0, 0))
				{
					(*ppszMultiByteString)[nLenMultiByteString] = '\0';

					bRet = true;
				}
			}
		}
	}

	return bRet;
}

bool CWin32StringConverter::MultiByteToUnicode(const char * pszMultiByteString, wchar_t ** ppszUnicodeString)
{
	bool bRet = false;

	if (m_pMemAllocator && pszMultiByteString && ppszUnicodeString)
	{
		auto nLenUnicodeString = MultiByteToWideChar(CP_ACP, 0, pszMultiByteString, -1, 0, 0);
		if (nLenUnicodeString)
		{
			*ppszUnicodeString = static_cast<wchar_t *>(m_pMemAllocator->Alloc(UnicodeCharSize * (nLenUnicodeString + 1)));
			if (*ppszUnicodeString)
			{
				if (MultiByteToWideChar(CP_ACP, 0, pszMultiByteString, -1, *ppszUnicodeString, nLenUnicodeString + 1))
				{
					(*ppszUnicodeString)[nLenUnicodeString] = L'\0';

					bRet = true;
				}
			}
		}
	}

	return bRet;
}

bool CWin32StringConverter::MultiByteToUTF8Unicode(const char * pszMultiByteString, wchar_t ** ppszUnicodeString)
{
	bool bRet = false;

	if (m_pMemAllocator && pszMultiByteString && ppszUnicodeString)
	{
		auto nLenUnicodeString = MultiByteToWideChar(CP_UTF8, 0, pszMultiByteString, -1, 0, 0);
		if (nLenUnicodeString)
		{
			*ppszUnicodeString = static_cast<wchar_t *>(m_pMemAllocator->Alloc(UnicodeCharSize * (nLenUnicodeString + 1)));
			if (*ppszUnicodeString)
			{
				if (MultiByteToWideChar(CP_UTF8, 0, pszMultiByteString, -1, *ppszUnicodeString, nLenUnicodeString + 1))
				{
					(*ppszUnicodeString)[nLenUnicodeString] = L'\0';

					bRet = true;
				}
			}
		}
	}

	return bRet;
}

void CWin32StringConverter::FreeUnicodeString(const wchar_t * pszUnicodeString)
{
	if (m_pMemAllocator && pszUnicodeString)
	{
		m_pMemAllocator->Free((void *)pszUnicodeString);
	}
}

void CWin32StringConverter::FreeMultiByteString(const char * pszMultiByteString)
{
	if (m_pMemAllocator && pszMultiByteString)
	{
		m_pMemAllocator->Free((void *)pszMultiByteString);
	}
}

#endif
