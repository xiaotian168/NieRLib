
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IFileEnumResult;

/**
** @brief 文件枚举器接口
*/
class NR_IFileEnumerator : public NR_IRefCount
{
public:

	/**
	** @brief 枚举指定目录下拥有指定后缀名的所有文件
	** @param pszDirectory 要进行枚举的目录
	** @param pszFileExt 要进行枚举的文件后缀名
	** @param bEnumSubDir 是否枚举子目录
	** @param ResultList 保存枚举结果
	** @return true 表示成功，false 表示失败
	*/
	virtual bool EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList) = 0;

	/**
	** @brief 枚举指定目录下的所有文件目录
	** @param pszDirectory 要进行枚举的目录
	** @param bEnumSubDir 是否枚举子目录
	** @param ResultList 保存枚举结果
	** @return true 表示成功，false 表示失败
	*/
	virtual bool EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList) = 0;
};
