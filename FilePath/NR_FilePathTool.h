
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief 从路径中分割出目录成分
*/
NR_CAPI bool NR_SplitDirectoryW(const wchar_t * pszPathToSplit, wchar_t * pszDirectory, const unsigned int uSize);

/**
** @brief 从路径中移除文件名部分
*/
NR_CAPI bool NR_RemoveFileSpecW(wchar_t * pszPath);

/**
** @brief 自动在路径末尾添加斜杠字符
*/
NR_CAPI bool NR_AppendBackslashW(wchar_t * pszPath, const unsigned int uSize);
