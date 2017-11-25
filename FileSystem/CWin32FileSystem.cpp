
#include "CWin32FileSystem.h"
#include "CWin32File.h"
#include <Windows.h>

CWin32FileSystem * CWin32FileSystem::Make(void)
{
	return new CWin32FileSystem();
}

CWin32FileSystem::CWin32FileSystem()
{

}

CWin32FileSystem::~CWin32FileSystem()
{

}

bool CWin32FileSystem::CreateFileW(const wchar_t * pszFilePath)
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

bool CWin32FileSystem::DeleteFileW(const wchar_t * pszFilePath)
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

bool CWin32FileSystem::IsFileExistW(const wchar_t * pszFilePath)
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

IFile * CWin32FileSystem::GetFileForReadW(const wchar_t * pszFilePath)
{
	if (pszFilePath)
	{
		return CWin32File::MakeW(pszFilePath, L"rb");
	}

	return 0;
}

IFile * CWin32FileSystem::GetFileForWriteW(const wchar_t * pszFilePath)
{
	if (pszFilePath)
	{
		return CWin32File::MakeW(pszFilePath, L"wb");
	}

	return 0;
}

IFile * CWin32FileSystem::GetFileForReadWriteW(const wchar_t * pszFilePath)
{
	if (pszFilePath)
	{
		return CWin32File::MakeW(pszFilePath, L"a+b");
	}

	return 0;
}
