
#pragma once

#include "NR_IShortcutManager.h"

#if defined NR_PLATFORM_WIN32

class NR_CWin32ShortcutManager : public NR_IShortcutManager
{
public:

	static NR_CWin32ShortcutManager * Make(void);

protected:

	NR_CWin32ShortcutManager();

	~NR_CWin32ShortcutManager();

public:

	bool SearchShortcutW(const wchar_t * pszSearchDirectory, std::list<NR_IShortcut *> & ShortcutList) override;
};

#endif
