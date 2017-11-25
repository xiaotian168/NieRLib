
#pragma once

#include "../Base/IRefCount.h"

class IFile;

/**
** @brief 文件系统接口
*/
class IFileSystem : public IRefCount
{
public:

	/**
	** @brief 创建文件
	*/
	virtual bool CreateFileW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief 删除文件
	*/
	virtual bool DeleteFileW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief 判断指定文件是否存在
	*/
	virtual bool IsFileExistW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief 获取只读文件接口
	*/
	virtual IFile * GetFileForReadW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief 获取只写文件接口
	*/
	virtual IFile * GetFileForWriteW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief 获取读写文件接口
	*/
	virtual IFile * GetFileForReadWriteW(const wchar_t * pszFilePath) = 0;
};
