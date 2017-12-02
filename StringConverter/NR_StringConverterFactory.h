
#pragma once

#include "../NieRLibConfig.h"

class NR_IStringConverter;

#if defined NR_PLATFORM_WIN32

/**
** @brief ���� Win32 �ַ���ת����
** @return Win32 �ַ���ת����
*/
NR_CAPI NR_IStringConverter * MakeWin32StringConverter(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨�������ַ�ת����
** @return �ַ�ת����
*/
NR_CAPI NR_IStringConverter * MakeStringConverterByOSPlatform(void);
