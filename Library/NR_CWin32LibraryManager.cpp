
#include "NR_CWin32LibraryManager.h"
#include "NR_CWin32Library.h"
#include "../StringConverter/NR_StringConverterTool.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32LibraryManager * NR_CWin32LibraryManager::Make(void)
{
	return new NR_CWin32LibraryManager();
}

NR_CWin32LibraryManager::NR_CWin32LibraryManager()
{

}

NR_CWin32LibraryManager::~NR_CWin32LibraryManager()
{

}

NR_ILibrary * NR_CWin32LibraryManager::GetLibraryW(const wchar_t * pszLibraryPath)
{
	if (pszLibraryPath)
	{
		auto hModule = LoadLibraryW(pszLibraryPath);
		if (hModule)
		{
			return NR_CWin32Library::Make(hModule);
		}
	}

	return 0;
}

NR_ILibrary * NR_CWin32LibraryManager::GetLibraryA(const char * pszLibraryPath)
{
	NR_ILibrary * pLib = 0;

	if (pszLibraryPath)
	{
		auto pszLibraryPathW = NR_MultiByte2Unicode(pszLibraryPath);
		if (pszLibraryPathW)
		{
			pLib = GetLibraryW(pszLibraryPathW);

			NR_FreeUnicodeString(pszLibraryPathW);
			pszLibraryPathW = 0;
		}
	}

	return pLib;
}

#endif
