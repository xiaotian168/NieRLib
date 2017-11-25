
#pragma once

#include "ILibraryManager.h"
#include "../NieRLibConfig.h"

#if defined NIER_PLATFORM_WIN32

class CWin32LibraryManager : public ILibraryManager
{
public:

	static CWin32LibraryManager * Make(void);

protected:

	CWin32LibraryManager();

	~CWin32LibraryManager();

public:

	ILibrary * GetLibraryW(const wchar_t * pszLibraryPath) override;

	ILibrary * GetLibraryA(const char * pszLibraryPath) override;
};

#endif
