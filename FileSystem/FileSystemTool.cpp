
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
		pMemAllocator = MakeMemoryAllocatorByOSPlatform();
	}

	inline ~CFileSystemHelper()
	{
		SAFE_RELEASE(pMemAllocator);
	}

public:

	static IMemoryAllocator * pMemAllocator;
};

IMemoryAllocator * CFileSystemHelper::pMemAllocator = 0;
CFileSystemHelper FileSystemHelper;

bool IsFileExistW(const wchar_t * pszFilePath)
{
	bool bRet = false;

	if (pszFilePath)
	{
		auto pFileSystem = MakeFileSystemByOSPlatform();
		if (pFileSystem)
		{
			if (pFileSystem->IsFileExistW(pszFilePath))
			{
				bRet = true;
			}

			SAFE_RELEASE(pFileSystem);
		}
	}

	return bRet;
}

bool ReadFileDataW(const wchar_t * pszFilePath, void ** ppFileData, unsigned int & uFileSize)
{
	bool bRet = false;

	if (CFileSystemHelper::pMemAllocator && pszFilePath && ppFileData)
	{
		auto pFileSystem = MakeFileSystemByOSPlatform();
		if (pFileSystem)
		{
			auto pFile = pFileSystem->GetFileForReadW(pszFilePath);
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

				SAFE_RELEASE(pFile);
			}

			SAFE_RELEASE(pFileSystem);
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
