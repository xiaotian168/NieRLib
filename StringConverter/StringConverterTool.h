
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief �� Unicode �ַ���ת��Ϊ MultiByte �ַ���
** @remark
**
** �����ǵ��� FreeMultiByteString() �ͷ��ַ���
*/
NIER_CAPI char * Unicode2MultiByte(const wchar_t * pszUnicodeString);

/**
** @brief �� MultiByte �ַ���ת��Ϊ Unicode �ַ���
** @remark
**
** �����ǵ��� FreeUnicodeString() �ͷ��ַ���
*/
NIER_CAPI wchar_t * MultiByte2Unicode(const char * pszMultiByteString);

/**
** @brief �ͷ� Unicode �ַ���
*/
NIER_CAPI void FreeUnicodeString(const wchar_t * pszUnicodeString);

/**
** @brief �ͷ� MultiByte �ַ���
*/
NIER_CAPI void FreeMultiByteString(const char * pszMultiByteString);
