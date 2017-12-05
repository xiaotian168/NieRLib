
#pragma once

#include "../NieRLibConfig.h"

class NR_IArchiver;

/**
** @brief 解包指定归档文件中的所有 Item
** @return true 表示成功，false 表示失败
*/
NR_API bool NR_UnpackAllArchiverItemW(NR_IArchiver * pArchiver, std::list<std::wstring> & ItemPathList);

/**
** @brief 自动根据调用者所在平台，使用对应的 zip 归档接口将指定的 zip 归档文件解包到指定目录
** @param pszArchiverPath zip 归档文件路径
** @param pszPassword 归档文件密码
** @param pszUnpackDirectory 解包目标目录路径
** @return true 表示成功，false 表示失败
*/
NR_API bool NR_UnpackZipArchiverW(const wchar_t * pszArchiverPath, const char * pszPassword, const wchar_t * pszUnpackDirectory);
