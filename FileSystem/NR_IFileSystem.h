
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IFile;

/**
** @brief 文件系统接口
*/
class NR_IFileSystem : public NR_IRefCount
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
	virtual NR_IFile * GetFileForReadW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief 获取只写文件接口
	*/
	virtual NR_IFile * GetFileForWriteW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief 获取读写文件接口
	*/
	virtual NR_IFile * GetFileForReadWriteW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief 创建目录
	*/
	virtual bool CreateDirectoryW(const wchar_t * pszDirectory) = 0;

	/**
	** @brief 创建目录链
	*/
	virtual bool CreateDirectoryPathW(const wchar_t * pszDirectory) = 0;
};
