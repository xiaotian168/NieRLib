
#define _NIER_API

#include "FileSystemTool.h"
#include "IFileSystem.h"
#include "IFile.h"
#include "FileSystemFactory.h"
#include "../MemoryAllocator/IMemoryAllocator.h"
#include "../MemoryAllocator/MemoryAllocatorFactory.h"

class CFileSystemHelper
{
public:

	inline CFileSystemHelper()
	{
		pFileSystem = MakeFileSystemByOSPlatform();
		pMemAllocator = MakeMemoryAllocatorByOSPlatform();
	}

	inline ~CFileSystemHelper()
	{
		SAFE_RELEASE(pFileSystem);
		SAFE_RELEASE(pMemAllocator);
	}

public:

	static IFileSystem * pFileSystem;
	static IMemoryAllocator * pMemAllocator;
};

IFileSystem * CFileSystemHelper::pFileSystem = 0;
IMemoryAllocator * CFileSystemHelper::pMemAllocator = 0;
CFileSystemHelper FileSystemHelper;

bool IsFileExistW(const wchar_t * pszFilePath)
{
	bool bRet = false;
	
	if (CFileSystemHelper::pFileSystem && pszFilePath)
	{
		if (CFileSystemHelper::pFileSystem->IsFileExistW(pszFilePath))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool ReadFileDataW(const wchar_t * pszFilePath, void ** ppFileData, unsigned int & uFileSize)
{
	bool bRet = false;

	if (CFileSystemHelper::pFileSystem && CFileSystemHelper::pMemAllocator && pszFilePath && ppFileData)
	{
		auto pFile = CFileSystemHelper::pFileSystem->GetFileForReadW(pszFilePath);
		if (pFile)
		{
			if (pFile->SeekToEnd())
			{
				uFileSize = static_cast<unsigned int>(pFile->Tell());
				if (uFileSize)
				{
					if (pFile->SeekToBegin())
					{
						*ppFileData = CFileSystemHelper::pMemAllocator->Alloc(uFileSize);
						if (*ppFileData)
						{
							if (pFile->Read(*ppFileData, uFileSize))
							{
								bRet = true;
							}
						}
					}
				}
			}

			pFile->Close();
			SAFE_RELEASE(pFile);
		}
	}

	return bRet;
}

bool FreeFileData(void * pFileData)
{
	bool bRet = false;

	if (CFileSystemHelper::pMemAllocator && pFileData)
	{
		CFileSystemHelper::pMemAllocator->Free(pFileData);

		bRet = true;
	}

	return bRet;
}

bool WriteFileDataW(const wchar_t * pszFilePath, const void * pData, const unsigned int uDataSize)
{
	bool bRet = false;

	if (CFileSystemHelper::pFileSystem && pszFilePath && pData && uDataSize)
	{
		auto pFile = CFileSystemHelper::pFileSystem->GetFileForWriteW(pszFilePath);
		if (pFile)
		{
			if (pFile->SeekToBegin())
			{
				if (pFile->Write(pData, uDataSize))
				{
					bRet = true;
				}
			}

			pFile->Close();
			SAFE_RELEASE(pFile);
		}
	}

	return bRet;
}
