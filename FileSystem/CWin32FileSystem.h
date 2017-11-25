
#pragma once

#include "IFileSystem.h"

class CWin32FileSystem : public IFileSystem
{
public:

	static CWin32FileSystem * Make(void);

protected:

	CWin32FileSystem();

	~CWin32FileSystem();

public:

	bool CreateFileW(const wchar_t * pszFilePath) override;

	bool DeleteFileW(const wchar_t * pszFilePath) override;

	bool IsFileExistW(const wchar_t * pszFilePath) override;

	IFile * GetFileForReadW(const wchar_t * pszFilePath) override;

	IFile * GetFileForWriteW(const wchar_t * pszFilePath) override;

	IFile * GetFileForReadWriteW(const wchar_t * pszFilePath) override;
};
