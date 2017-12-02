
#pragma once

#include "../NieRLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define NR_EnumAllFile NR_EnumAllFileW
#	define NR_EnumAllDirectory NR_EnumAllDirectoryW
#else
#	define NR_EnumAllFile NR_EnumAllFileA
#	define NR_EnumAllDirectory NR_EnumAllDirectoryA
#endif

class NR_IFileEnumResult;

/**
** @brief 枚举指定目录下拥有指定后缀名的所有文件
** @param pszDirectory 要进行枚举的目录
** @param pszFileExt 要进行枚举的文件后缀名
** @param bEnumSubDir 是否枚举子目录
** @param ResultList 保存枚举结果
** @return true 表示成功，false 表示失败
*/
NR_CAPI bool NR_EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList);
NR_CAPI bool NR_EnumAllFileA(const char * pszDirectory, const char * pszFileExt, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList);

/**
** @brief 枚举指定目录下的所有文件目录
** @param pszDirectory 要进行枚举的目录
** @param bEnumSubDir 是否枚举子目录
** @param ResultList 保存枚举结果
** @return true 表示成功，false 表示失败
*/
NR_CAPI bool NR_EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList);
NR_CAPI bool NR_EnumAllDirectoryA(const char * pszDirectory, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList);
