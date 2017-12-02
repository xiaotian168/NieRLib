
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief 将 Unicode 字符串转换为 MultiByte 字符串
** @remark
**
** 用完后记得用 NR_FreeMultiByteString() 释放字符串
*/
NR_CAPI char * NR_Unicode2MultiByte(const wchar_t * pszUnicodeString);

/**
** @brief 将 Unicode 字符串转换为 UTF-8 MultiByte 字符串
** @remark
**
** 用完后记得用 NR_FreeMultiByteString() 释放字符串
*/
NR_CAPI char * NR_Unicode2UTF8MultiByte(const wchar_t * pszUnicodeString);

/**
** @brief 将 MultiByte 字符串转换为 Unicode 字符串
** @remark
**
** 用完后记得用 NR_FreeUnicodeString() 释放字符串
*/
NR_CAPI wchar_t * NR_MultiByte2Unicode(const char * pszMultiByteString);

/**
** @brief 将 MultiByte 字符串转换为 UTF-8 Unicode 字符串
** @remark
**
** 用完后记得用 NR_FreeUnicodeString() 释放字符串
*/
NR_CAPI wchar_t * NR_MultiByte2UTF8Unicode(const char * pszMultiByteString);

/**
** @brief 释放 Unicode 字符串
*/
NR_CAPI void NR_FreeUnicodeString(const wchar_t * pszUnicodeString);

/**
** @brief 释放 MultiByte 字符串
*/
NR_CAPI void NR_FreeMultiByteString(const char * pszMultiByteString);
