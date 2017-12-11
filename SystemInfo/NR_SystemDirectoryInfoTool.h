
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief 获取系统临时目录路径
*/
NR_CAPI bool NR_GetTempDirectoryW(wchar_t * pszDirectory, const unsigned int uSize);

/**
** @brief 获取系统目录路径
*/
NR_CAPI bool NR_GetSystemDirectoryW(wchar_t * pszDirectory, const unsigned int uSize);

/**
** @brief 在系统临时目录中创建一个临时文件名
*/
NR_CAPI bool NR_MakeTempFilePathW(wchar_t * pszFilePath, const unsigned int uSize);
