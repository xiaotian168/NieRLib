
#define _NIER_API

#include "NR_LibraryTool.h"
#include "NR_CWin32LibraryManager.h"
#include "NR_LibraryManagerFactory.h"
#include "NR_ILibraryManager.h"
#include "NR_ILibrary.h"

class CLibraryHelper
{
public:

	inline CLibraryHelper()
	{
		pLibraryManager = NR_MakeLibraryManagerByOSPlatform();
	}

	inline ~CLibraryHelper()
	{
		SAFE_RELEASE(pLibraryManager);
	}

public:

	static NR_ILibraryManager * pLibraryManager;
};

NR_ILibraryManager * CLibraryHelper::pLibraryManager = 0;
CLibraryHelper LibraryHelper;

NR_ILibrary * NR_GetLibraryW(const wchar_t * pszLibraryPath)
{
	if (CLibraryHelper::pLibraryManager && pszLibraryPath)
	{
		return CLibraryHelper::pLibraryManager->GetLibraryW(pszLibraryPath);
	}

	return 0;
}
