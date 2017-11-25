
#include "CWin32Library.h"
#include "../StringConverter/StringConverterTool.h"

#if defined NIER_PLATFORM_WIN32

CWin32Library * CWin32Library::Make(const HMODULE hModule)
{
	return new CWin32Library(hModule);
}

CWin32Library::CWin32Library(const HMODULE hModule)
{
	m_hModule = hModule;
}

CWin32Library::~CWin32Library()
{
	if (m_hModule)
	{
		FreeLibrary(m_hModule);
		m_hModule = 0;
	}
}

void * CWin32Library::ExportSymbolW(const wchar_t * pszSymbolName)
{
	void * pSymbol = 0;

	if (pszSymbolName)
	{
		auto pszSymbolNameA = Unicode2MultiByte(pszSymbolName);
		if (pszSymbolNameA)
		{
			pSymbol = ExportSymbolA(pszSymbolNameA);

			FreeMultiByteString(pszSymbolNameA);
			pszSymbolNameA = 0;
		}
	}

	return pSymbol;
}

void * CWin32Library::ExportSymbolA(const char * pszSymbolName)
{
	if (m_hModule && pszSymbolName)
	{
		return GetProcAddress(m_hModule, pszSymbolName);
	}

	return 0;
}

#endif
