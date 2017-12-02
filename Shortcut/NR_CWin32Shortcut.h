
#pragma once

#include "NR_IShortcut.h"

#if defined NIER_PLATFORM_WIN32

class NR_CWin32Shortcut : public NR_IShortcut
{
public:

	static NR_CWin32Shortcut * Make(wchar_t * pszShortcutPath);

protected:

	NR_CWin32Shortcut(wchar_t * pszShortcutPath);

	~NR_CWin32Shortcut();

public:

	bool GetTargetPathW(wchar_t * pszTargetPath, const unsigned int uSize) override;
	
	bool GetPathW(wchar_t * pszPath, const unsigned int uSize) override;

	bool Delete(void) override;

private:

	IShellLinkW * m_pShellLink;
	std::wstring m_strPath;
};

#endif
