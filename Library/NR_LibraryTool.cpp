
#define _NR_API

#include "NR_LibraryTool.h"
#include "NR_CWin32LibraryManager.h"
#include "NR_LibraryManagerFactory.h"
#include "NR_ILibraryManager.h"
#include "NR_ILibrary.h"

class NR_CLibraryHelper
{
public:

	inline NR_CLibraryHelper()
	{
		pLibraryManager = NR_MakeLibraryManagerByOSPlatform();
	}

	inline ~NR_CLibraryHelper()
	{
		NR_SAFE_RELEASE(pLibraryManager);
	}

public:

	static NR_ILibraryManager * pLibraryManager;
};

NR_ILibraryManager * NR_CLibraryHelper::pLibraryManager = 0;
NR_CLibraryHelper LibraryHelper;

NR_ILibrary * NR_GetLibraryW(const wchar_t * pszLibraryPath)
{
	if (NR_CLibraryHelper::pLibraryManager && pszLibraryPath)
	{
		return NR_CLibraryHelper::pLibraryManager->GetLibraryW(pszLibraryPath);
	}

	return 0;
}
