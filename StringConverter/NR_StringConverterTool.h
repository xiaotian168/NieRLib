
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief �� Unicode �ַ���ת��Ϊ MultiByte �ַ���
** @remark
**
** �����ǵ��� NR_FreeMultiByteString() �ͷ��ַ���
*/
NIER_CAPI char * NR_Unicode2MultiByte(const wchar_t * pszUnicodeString);

/**
** @brief �� Unicode �ַ���ת��Ϊ UTF-8 MultiByte �ַ���
** @remark
**
** �����ǵ��� NR_FreeMultiByteString() �ͷ��ַ���
*/
NIER_CAPI char * NR_Unicode2UTF8MultiByte(const wchar_t * pszUnicodeString);

/**
** @brief �� MultiByte �ַ���ת��Ϊ Unicode �ַ���
** @remark
**
** �����ǵ��� NR_FreeUnicodeString() �ͷ��ַ���
*/
NIER_CAPI wchar_t * NR_MultiByte2Unicode(const char * pszMultiByteString);

/**
** @brief �� MultiByte �ַ���ת��Ϊ UTF-8 Unicode �ַ���
** @remark
**
** �����ǵ��� NR_FreeUnicodeString() �ͷ��ַ���
*/
NIER_CAPI wchar_t * NR_MultiByte2UTF8Unicode(const char * pszMultiByteString);

/**
** @brief �ͷ� Unicode �ַ���
*/
NIER_CAPI void NR_FreeUnicodeString(const wchar_t * pszUnicodeString);

/**
** @brief �ͷ� MultiByte �ַ���
*/
NIER_CAPI void NR_FreeMultiByteString(const char * pszMultiByteString);
