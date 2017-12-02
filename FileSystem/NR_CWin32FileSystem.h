
#pragma once

#include "NR_IFileSystem.h"

#if defined NIER_PLATFORM_WIN32

class NR_CWin32FileSystem : public NR_IFileSystem
{
public:

	static NR_CWin32FileSystem * Make(void);

protected:

	NR_CWin32FileSystem();

	~NR_CWin32FileSystem();

public:

	bool CreateFileW(const wchar_t * pszFilePath) override;

	bool DeleteFileW(const wchar_t * pszFilePath) override;

	bool IsFileExistW(const wchar_t * pszFilePath) override;

	NR_IFile * GetFileForReadW(const wchar_t * pszFilePath) override;

	NR_IFile * GetFileForWriteW(const wchar_t * pszFilePath) override;

	NR_IFile * GetFileForReadWriteW(const wchar_t * pszFilePath) override;
};

#endif
