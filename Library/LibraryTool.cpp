
#define _NIER_API

#include "LibraryTool.h"
#include "CWin32LibraryManager.h"
#include "LibraryManagerFactory.h"
#include "ILibraryManager.h"
#include "ILibrary.h"

class CLibraryHelper
{
public:

	inline CLibraryHelper()
	{
		pLibraryManager = MakeLibraryManagerByOSPlatform();
	}

	inline ~CLibraryHelper()
	{
		SAFE_RELEASE(pLibraryManager);
	}

public:

	static ILibraryManager * pLibraryManager;
};

ILibraryManager * CLibraryHelper::pLibraryManager = 0;
CLibraryHelper LibraryHelper;

ILibrary * GetLibraryW(const wchar_t * pszLibraryPath)
{
	if (CLibraryHelper::pLibraryManager && pszLibraryPath)
	{
		return CLibraryHelper::pLibraryManager->GetLibraryW(pszLibraryPath);
	}

	return 0;
}
