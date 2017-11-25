
#pragma once

#include "../Base/IRefCount.h"

class IFile;

class IFileSystem : public IRefCount
{
public:

	virtual bool CreateFileW(const wchar_t * pszFilePath) = 0;

	virtual bool DeleteFileW(const wchar_t * pszFilePath) = 0;

	virtual bool IsFileExistW(const wchar_t * pszFilePath) = 0;

	virtual IFile * GetFileForReadW(const wchar_t * pszFilePath) = 0;

	virtual IFile * GetFileForWriteW(const wchar_t * pszFilePath) = 0;

	virtual IFile * GetFileForReadWriteW(const wchar_t * pszFilePath) = 0;
};
