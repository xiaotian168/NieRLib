
#pragma once

#include "../NieRLibConfig.h"

class NR_ILibraryManager;

#if defined NIER_PLATFORM_WIN32

/**
** @brief ���� Win32 �������
** @return Win32 �������
*/
NIER_CAPI NR_ILibraryManager * NR_MakeWin32LibraryManager(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨�������������
** @return �������
*/
NIER_CAPI NR_ILibraryManager * NR_MakeLibraryManagerByOSPlatform(void);
