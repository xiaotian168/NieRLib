
#define _NR_API

#include "NR_CWin32Shortcut.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32Shortcut * NR_CWin32Shortcut::Make(wchar_t * pszShortcutPath)
{
	return new NR_CWin32Shortcut(pszShortcutPath);
}

NR_CWin32Shortcut::NR_CWin32Shortcut(wchar_t * pszShortcutPath)
{
	IPersistFile * pPersistFile = 0;

	m_pShellLink = 0;

	if (pszShortcutPath)
	{
		if (SUCCEEDED(CoCreateInstance(CLSID_ShellLink, 0, CLSCTX_INPROC_SERVER, IID_IShellLink, (void **)&m_pShellLink)))
		{
			if (SUCCEEDED(m_pShellLink->QueryInterface(IID_IPersistFile, (void **)&pPersistFile)))
			{
				if (SUCCEEDED(pPersistFile->Load(pszShortcutPath, STGM_READ)))
				{
					m_strPath = pszShortcutPath;
				}

				NR_SAFE_RELEASE(pPersistFile);
			}
		}
	}
}

NR_CWin32Shortcut::~NR_CWin32Shortcut()
{
	NR_SAFE_RELEASE(m_pShellLink);
	m_strPath.clear();
}

bool NR_CWin32Shortcut::GetTargetPathW(wchar_t * pszTargetPath, const unsigned int uSize)
{
	bool bRet = false;

	if (m_pShellLink && pszTargetPath && uSize)
	{
		if (SUCCEEDED(m_pShellLink->GetPath(pszTargetPath, uSize, 0, 0)))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32Shortcut::GetPathW(wchar_t * pszPath, const unsigned int uSize)
{
	bool bRet = false;

	if (m_strPath.c_str() && pszPath && uSize)
	{
		wcscpy_s(pszPath, uSize, m_strPath.c_str());

		bRet = true;
	}

	return bRet;
}

bool NR_CWin32Shortcut::Delete(void)
{
	bool bRet = false;

	if (m_strPath.c_str())
	{
		if (DeleteFileW(m_strPath.c_str()))
		{
			m_strPath.clear();
			NR_SAFE_RELEASE(m_pShellLink);

			bRet = true;
		}
	}

	return bRet;
}

#endif
