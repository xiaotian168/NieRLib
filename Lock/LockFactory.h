
#pragma once

#include "../NieRLibConfig.h"

class ILock;

/**
** @brief ������ Win32 ������
** @return �� Win32 ������
*/
NIER_CAPI ILock * MakeSimpleWin32Lock(void);

/**
** @brief �Զ����ݵ���������ƽ̨������������
** @return ������
*/
NIER_CAPI ILock * MakeLockByOSPlatform(void);
