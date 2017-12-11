
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IFile;

/**
** @brief �ļ�ϵͳ�ӿ�
*/
class NR_IFileSystem : public NR_IRefCount
{
public:

	/**
	** @brief �����ļ�
	*/
	virtual bool CreateFileW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief ɾ���ļ�
	*/
	virtual bool DeleteFileW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief �ж�ָ���ļ��Ƿ����
	*/
	virtual bool IsFileExistW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief ��ȡֻ���ļ��ӿ�
	*/
	virtual NR_IFile * GetFileForReadW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief ��ȡֻд�ļ��ӿ�
	*/
	virtual NR_IFile * GetFileForWriteW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief ��ȡ��д�ļ��ӿ�
	*/
	virtual NR_IFile * GetFileForReadWriteW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief ����Ŀ¼
	*/
	virtual bool CreateDirectoryW(const wchar_t * pszDirectory) = 0;

	/**
	** @brief ����Ŀ¼��
	*/
	virtual bool CreateDirectoryPathW(const wchar_t * pszDirectory) = 0;
};
