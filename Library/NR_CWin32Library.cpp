
#include "NR_CWin32Library.h"
#include "../StringConverter/NR_StringConverterTool.h"

#if defined NIER_PLATFORM_WIN32

NR_CWin32Library * NR_CWin32Library::Make(const HMODULE hModule)
{
	return new NR_CWin32Library(hModule);
}

NR_CWin32Library::NR_CWin32Library(const HMODULE hModule)
{
	m_hModule = hModule;
}

NR_CWin32Library::~NR_CWin32Library()
{
	if (m_hModule)
	{
		FreeLibrary(m_hModule);
		m_hModule = 0;
	}
}

void * NR_CWin32Library::ExportSymbolW(const wchar_t * pszSymbolName)
{
	void * pSymbol = 0;

	if (pszSymbolName)
	{
		auto pszSymbolNameA = NR_Unicode2MultiByte(pszSymbolName);
		if (pszSymbolNameA)
		{
			pSymbol = ExportSymbolA(pszSymbolNameA);

			NR_FreeMultiByteString(pszSymbolNameA);
			pszSymbolNameA = 0;
		}
	}

	return pSymbol;
}

void * NR_CWin32Library::ExportSymbolA(const char * pszSymbolName)
{
	if (m_hModule && pszSymbolName)
	{
		return GetProcAddress(m_hModule, pszSymbolName);
	}

	return 0;
}

#endif
