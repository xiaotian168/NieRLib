
#include "NR_CWin32FileSystem.h"
#include "NR_CWin32File.h"

#if defined NIER_PLATFORM_WIN32

NR_CWin32FileSystem * NR_CWin32FileSystem::Make(void)
{
	return new NR_CWin32FileSystem();
}

NR_CWin32FileSystem::NR_CWin32FileSystem()
{

}

NR_CWin32FileSystem::~NR_CWin32FileSystem()
{

}

bool NR_CWin32FileSystem::CreateFileW(const wchar_t * pszFilePath)
{
	bool bRet = false;
	FILE * pFile = 0;

	if (pszFilePath)
	{
		if (0 == _wfopen_s(&pFile, pszFilePath, L"a+b"))
		{
			fclose(pFile);
			pFile = 0;

			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32FileSystem::DeleteFileW(const wchar_t * pszFilePath)
{
	bool bRet = false;

	if (pszFilePath)
	{
		if (::DeleteFileW(pszFilePath))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32FileSystem::IsFileExistW(const wchar_t * pszFilePath)
{
	bool bRet = false;
	FILE * pFile = 0;

	if (pszFilePath)
	{
		if (0 == _wfopen_s(&pFile, pszFilePath, L"rb"))
		{
			fclose(pFile);
			pFile = 0;

			bRet = true;
		}
	}

	return bRet;
}

NR_IFile * NR_CWin32FileSystem::GetFileForReadW(const wchar_t * pszFilePath)
{
	if (pszFilePath)
	{
		return NR_CWin32File::MakeW(pszFilePath, L"rb");
	}

	return 0;
}

NR_IFile * NR_CWin32FileSystem::GetFileForWriteW(const wchar_t * pszFilePath)
{
	if (pszFilePath)
	{
		return NR_CWin32File::MakeW(pszFilePath, L"wb");
	}

	return 0;
}

NR_IFile * NR_CWin32FileSystem::GetFileForReadWriteW(const wchar_t * pszFilePath)
{
	if (pszFilePath)
	{
		return NR_CWin32File::MakeW(pszFilePath, L"a+b");
	}

	return 0;
}

#endif
