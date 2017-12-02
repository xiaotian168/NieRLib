
#pragma once

#include "NR_ILibraryManager.h"
#include "../NieRLibConfig.h"

#if defined NIER_PLATFORM_WIN32

class NR_CWin32LibraryManager : public NR_ILibraryManager
{
public:

	static NR_CWin32LibraryManager * Make(void);

protected:

	NR_CWin32LibraryManager();

	~NR_CWin32LibraryManager();

public:

	NR_ILibrary * GetLibraryW(const wchar_t * pszLibraryPath) override;

	NR_ILibrary * GetLibraryA(const char * pszLibraryPath) override;
};

#endif
