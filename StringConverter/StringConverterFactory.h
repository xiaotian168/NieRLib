
#pragma once

#include "../NieRLibConfig.h"

class IStringConverter;

/**
** @brief ���� Win32 �ַ���ת����
** @return Win32 �ַ���ת����
*/
NIER_CAPI IStringConverter * MakeWin32StringConverter(void);

/**
** @brief �Զ����ݵ���������ƽ̨�������ַ�ת����
** @return �ַ�ת����
*/
NIER_CAPI IStringConverter * MakeStringConverterByOSPlatform(void);
