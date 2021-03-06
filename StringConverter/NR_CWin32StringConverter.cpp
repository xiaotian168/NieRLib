
#define _NR_API

#include "NR_CWin32StringConverter.h"
#include "../MemoryAllocator/NR_IMemoryAllocator.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32StringConverter * NR_CWin32StringConverter::Make(void)
{
	return new NR_CWin32StringConverter();
}

NR_CWin32StringConverter::NR_CWin32StringConverter()
{
	m_pMemAllocator = 0;
}

NR_CWin32StringConverter::~NR_CWin32StringConverter()
{
	NR_SAFE_RELEASE(m_pMemAllocator);
}

void NR_CWin32StringConverter::SetMemoryAllocator(NR_IMemoryAllocator * pAllocator)
{
	if (m_pMemAllocator != pAllocator)
	{
		NR_SAFE_RELEASE(m_pMemAllocator);
		m_pMemAllocator = pAllocator;
		NR_SAFE_ADDREF(m_pMemAllocator);
	}
}

NR_IMemoryAllocator * NR_CWin32StringConverter::GetMemoryAllocator(void) const
{
	NR_SAFE_ADDREF(m_pMemAllocator);

	return m_pMemAllocator;
}

bool NR_CWin32StringConverter::UnicodeToMultiByte(const wchar_t * pszUnicodeString, char ** ppszMultiByteString)
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

bool NR_CWin32StringConverter::UnicodeToUTF8MultiByte(const wchar_t * pszUnicodeString, char ** ppszMultiByteString)
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

bool NR_CWin32StringConverter::MultiByteToUnicode(const char * pszMultiByteString, wchar_t ** ppszUnicodeString)
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

bool NR_CWin32StringConverter::MultiByteToUTF8Unicode(const char * pszMultiByteString, wchar_t ** ppszUnicodeString)
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

void NR_CWin32StringConverter::FreeUnicodeString(const wchar_t * pszUnicodeString)
{
	if (m_pMemAllocator && pszUnicodeString)
	{
		m_pMemAllocator->Free((void *)pszUnicodeString);
	}
}

void NR_CWin32StringConverter::FreeMultiByteString(const char * pszMultiByteString)
{
	if (m_pMemAllocator && pszMultiByteString)
	{
		m_pMemAllocator->Free((void *)pszMultiByteString);
	}
}

#endif
