
#pragma once

#include "../NieRLibConfig.h"
#include <list>

#if defined UNICODE || defined _UNICODE
#	define EnumAllFile EnumAllFileW
#	define EnumAllDirectory EnumAllDirectoryW
#else
#	define EnumAllFile EnumAllFileA
#	define EnumAllDirectory EnumAllDirectoryA
#endif

class IFileEnumResult;

/**
** @brief 枚举指定目录下拥有指定后缀名的所有文件
** @param pszDirectory 要进行枚举的目录
** @param pszFileExt 要进行枚举的文件后缀名
** @param bEnumSubDir 是否枚举子目录
** @param ResultList 保存枚举结果
** @return true 表示成功，false 表示失败
*/
NIER_CAPI bool EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList);
NIER_CAPI bool EnumAllFileA(const char * pszDirectory, const char * pszFileExt, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList);

/**
** @brief 枚举指定目录下的所有文件目录
** @param pszDirectory 要进行枚举的目录
** @param bEnumSubDir 是否枚举子目录
** @param ResultList 保存枚举结果
** @return true 表示成功，false 表示失败
*/
NIER_CAPI bool EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList);
NIER_CAPI bool EnumAllDirectoryA(const char * pszDirectory, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList);
