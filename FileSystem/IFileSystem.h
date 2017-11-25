
#pragma once

#include "../Base/IRefCount.h"

class IFile;

/**
** @brief �ļ�ϵͳ�ӿ�
*/
class IFileSystem : public IRefCount
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
	virtual IFile * GetFileForReadW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief ��ȡֻд�ļ��ӿ�
	*/
	virtual IFile * GetFileForWriteW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief ��ȡ��д�ļ��ӿ�
	*/
	virtual IFile * GetFileForReadWriteW(const wchar_t * pszFilePath) = 0;
};
