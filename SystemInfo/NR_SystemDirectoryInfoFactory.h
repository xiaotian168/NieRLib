
#pragma once

#include "../NieRLibConfig.h"

class NR_ISystemDirectoryInfo;

#if defined NR_PLATFORM_WIN32

/**
** @brief ���� Win32 ϵͳĿ¼��Ϣ
** @return Win32 ϵͳĿ¼��Ϣ
*/
NR_CAPI NR_ISystemDirectoryInfo * MakeWin32SystemDirectoryInfo(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨������ϵͳĿ¼��Ϣ
** @return ϵͳĿ¼��Ϣ
*/
NR_CAPI NR_ISystemDirectoryInfo * MakeSystemDirectoryInfoByOSPlatform(void);
