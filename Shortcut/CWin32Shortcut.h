
#pragma once

#include "IShortcut.h"

#if defined NIER_PLATFORM_WIN32

class CWin32Shortcut : public IShortcut
{
public:

	static CWin32Shortcut * Make(wchar_t * pszShortcutPath);

protected:

	CWin32Shortcut(wchar_t * pszShortcutPath);

	~CWin32Shortcut();

public:

	bool GetTargetPathW(wchar_t * pszTargetPath, const unsigned int uSize) override;
	
	bool GetPathW(wchar_t * pszPath, const unsigned int uSize) override;

	bool Delete(void) override;

private:

	IShellLinkW * m_pShellLink;
	std::wstring m_strPath;
};

#endif
