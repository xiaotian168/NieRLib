
#define _NR_API

#include "NR_FileSystemTool.h"
#include "NR_IFileSystem.h"
#include "NR_IFile.h"
#include "NR_FileSystemFactory.h"
#include "../MemoryAllocator/NR_IMemoryAllocator.h"
#include "../MemoryAllocator/NR_MemoryAllocatorFactory.h"

class NR_CFileSystemHelper
{
public:

	inline NR_CFileSystemHelper()
	{
		pFileSystem = NR_MakeFileSystemByOSPlatform();
		pMemAllocator = NR_MakeMemoryAllocatorByOSPlatform();
	}

	inline ~NR_CFileSystemHelper()
	{
		NR_SAFE_RELEASE(pFileSystem);
		NR_SAFE_RELEASE(pMemAllocator);
	}

public:

	static NR_IFileSystem * pFileSystem;
	static NR_IMemoryAllocator * pMemAllocator;
};

NR_IFileSystem * NR_CFileSystemHelper::pFileSystem = 0;
NR_IMemoryAllocator * NR_CFileSystemHelper::pMemAllocator = 0;
NR_CFileSystemHelper FileSystemHelper;

bool IsFileExistW(const wchar_t * pszFilePath)
{
	bool bRet = false;
	
	if (NR_CFileSystemHelper::pFileSystem && pszFilePath)
	{
		if (NR_CFileSystemHelper::pFileSystem->IsFileExistW(pszFilePath))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_ReadFileDataW(const wchar_t * pszFilePath, void ** ppFileData, unsigned int & uFileSize)
{
	bool bRet = false;

	if (NR_CFileSystemHelper::pFileSystem && NR_CFileSystemHelper::pMemAllocator && pszFilePath && ppFileData)
	{
		auto pFile = NR_CFileSystemHelper::pFileSystem->GetFileForReadW(pszFilePath);
		if (pFile)
		{
			if (pFile->SeekToEnd())
			{
				uFileSize = static_cast<unsigned int>(pFile->Tell());
				if (uFileSize)
				{
					if (pFile->SeekToBegin())
					{
						*ppFileData = NR_CFileSystemHelper::pMemAllocator->Alloc(uFileSize);
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
			NR_SAFE_RELEASE(pFile);
		}
	}

	return bRet;
}

bool NR_FreeFileData(void * pFileData)
{
	bool bRet = false;

	if (NR_CFileSystemHelper::pMemAllocator && pFileData)
	{
		NR_CFileSystemHelper::pMemAllocator->Free(pFileData);

		bRet = true;
	}

	return bRet;
}

bool NR_WriteFileDataW(const wchar_t * pszFilePath, const void * pData, const unsigned int uDataSize)
{
	bool bRet = false;

	if (NR_CFileSystemHelper::pFileSystem && pszFilePath && pData && uDataSize)
	{
		auto pFile = NR_CFileSystemHelper::pFileSystem->GetFileForWriteW(pszFilePath);
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
			NR_SAFE_RELEASE(pFile);
		}
	}

	return bRet;
}
