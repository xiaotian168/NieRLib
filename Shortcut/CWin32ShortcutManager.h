
#pragma once

#include "IShortcutManager.h"

#if defined NIER_PLATFORM_WIN32

class CWin32ShortcutManager : public IShortcutManager
{
public:

	static CWin32ShortcutManager * Make(void);

protected:

	CWin32ShortcutManager();

	~CWin32ShortcutManager();

public:

	bool SearchShortcutW(const wchar_t * pszSearchDirectory, std::list<IShortcut *> & ShortcutList) override;
};

#endif
