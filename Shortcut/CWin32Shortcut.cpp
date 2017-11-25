
#define _NIER_API

#include "CWin32Shortcut.h"

#if defined NIER_PLATFORM_WIN32

CWin32Shortcut * CWin32Shortcut::Make(wchar_t * pszShortcutPath)
{
	return new CWin32Shortcut(pszShortcutPath);
}

CWin32Shortcut::CWin32Shortcut(wchar_t * pszShortcutPath)
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

				SAFE_RELEASE(pPersistFile);
			}
		}
	}
}

CWin32Shortcut::~CWin32Shortcut()
{
	SAFE_RELEASE(m_pShellLink);
	m_strPath.clear();
}

bool CWin32Shortcut::GetTargetPathW(wchar_t * pszTargetPath, const unsigned int uSize)
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

bool CWin32Shortcut::GetPathW(wchar_t * pszPath, const unsigned int uSize)
{
	bool bRet = false;

	if (m_strPath.c_str() && pszPath && uSize)
	{
		wcscpy_s(pszPath, uSize, m_strPath.c_str());

		bRet = true;
	}

	return bRet;
}

bool CWin32Shortcut::Delete(void)
{
	bool bRet = false;

	if (m_strPath.c_str())
	{
		if (DeleteFileW(m_strPath.c_str()))
		{
			m_strPath.clear();
			SAFE_RELEASE(m_pShellLink);

			bRet = true;
		}
	}

	return bRet;
}

#endif
