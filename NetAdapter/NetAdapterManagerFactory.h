
#pragma once

#include "../NieRLibConfig.h"

class INetAdapterManager;

/**
** @brief ���� Win32 ����������������
** @return Win32 ����������������
*/
NIER_CAPI INetAdapterManager * MakeWin32NetAdapterManager(void);

/**
** @brief �Զ����ݵ���������ƽ̨����������������������
** @return ����������������
*/
NIER_CAPI INetAdapterManager * MakeNetAdapterManagerByOSPlatform(void);
