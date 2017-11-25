
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief 将 Unicode 字符串转换为 MultiByte 字符串
** @remark
**
** 用完后记得用 FreeMultiByteString() 释放字符串
*/
NIER_CAPI char * Unicode2MultiByte(const wchar_t * pszUnicodeString);

/**
** @brief 将 Unicode 字符串转换为 UTF-8 MultiByte 字符串
** @remark
**
** 用完后记得用 FreeMultiByteString() 释放字符串
*/
NIER_CAPI char * Unicode2UTF8MultiByte(const wchar_t * pszUnicodeString);

/**
** @brief 将 MultiByte 字符串转换为 Unicode 字符串
** @remark
**
** 用完后记得用 FreeUnicodeString() 释放字符串
*/
NIER_CAPI wchar_t * MultiByte2Unicode(const char * pszMultiByteString);

/**
** @brief 将 MultiByte 字符串转换为 UTF-8 Unicode 字符串
** @remark
**
** 用完后记得用 FreeUnicodeString() 释放字符串
*/
NIER_CAPI wchar_t * MultiByte2UTF8Unicode(const char * pszMultiByteString);

/**
** @brief 释放 Unicode 字符串
*/
NIER_CAPI void FreeUnicodeString(const wchar_t * pszUnicodeString);

/**
** @brief 释放 MultiByte 字符串
*/
NIER_CAPI void FreeMultiByteString(const char * pszMultiByteString);
