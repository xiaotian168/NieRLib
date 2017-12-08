
#pragma once

#include "../NieRLibConfig.h"

class NR_ITaskBarInfo;

#if defined NR_PLATFORM_WIN32

/**
** @brief ���� Win32 ��������Ϣ�ӿ�
** @return Win32 ��������Ϣ�ӿ�
*/
NR_CAPI NR_ITaskBarInfo * NR_MakeWin32TaskBarInfo(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨��������������Ϣ�ӿ�
** @return ��������Ϣ�ӿ�
*/
NR_CAPI NR_ITaskBarInfo * NR_MakeTaskBarInfoByOSPlatform(void);
