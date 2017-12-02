
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 文件路径接口
*/
class NR_IFilePath : public NR_IRefCount
{
public:

	/**
	** @brief 从路径中分割出目录成分
	*/
	virtual bool SplitDirectoryW(const wchar_t * pszPathToSplit, wchar_t * pszDirectory, const unsigned int uSize) = 0;

	/**
	** @brief 从路径中分割出文件名成分
	*/
	virtual bool SplitFileTitleW(const wchar_t * pszPathToSplit, wchar_t * pszFileTitle, const unsigned int uSize) = 0;

	/**
	** @brief 从路径中分割出文件名成分，不包含文件扩展名
	*/
	virtual bool SplitFileTitleWithNoExeW(const wchar_t * pszPathToSplit, wchar_t * pszFileTitle, const unsigned int uSize) = 0;

	/**
	** @brief 从路径中分割出文件扩展名
	*/
	virtual bool SplitFileExtW(const wchar_t * pszPathToSplit, wchar_t * pszFileExt, const unsigned int uSize) = 0;

	/**
	** @brief 自动在路径末尾添加斜杠字符
	*/
	virtual bool AppendBackslashW(wchar_t * pszPath, const unsigned int uSize) = 0;
};
