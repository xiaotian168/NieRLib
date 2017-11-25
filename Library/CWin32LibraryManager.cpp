
#include "CWin32LibraryManager.h"
#include "CWin32Library.h"
#include "../StringConverter/StringConverterTool.h"

#if defined NIER_PLATFORM_WIN32

CWin32LibraryManager * CWin32LibraryManager::Make(void)
{
	return new CWin32LibraryManager();
}

CWin32LibraryManager::CWin32LibraryManager()
{

}

CWin32LibraryManager::~CWin32LibraryManager()
{

}

ILibrary * CWin32LibraryManager::GetLibraryW(const wchar_t * pszLibraryPath)
{
	if (pszLibraryPath)
	{
		auto hModule = LoadLibraryW(pszLibraryPath);
		if (hModule)
		{
			return CWin32Library::Make(hModule);
		}
	}

	return 0;
}

ILibrary * CWin32LibraryManager::GetLibraryA(const char * pszLibraryPath)
{
	ILibrary * pLib = 0;

	if (pszLibraryPath)
	{
		auto pszLibraryPathW = MultiByte2Unicode(pszLibraryPath);
		if (pszLibraryPathW)
		{
			pLib = GetLibraryW(pszLibraryPathW);

			FreeUnicodeString(pszLibraryPathW);
			pszLibraryPathW = 0;
		}
	}

	return pLib;
}

#endif
