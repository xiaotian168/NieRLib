
#pragma once

#include "../NieRLibConfig.h"

class NR_ILibraryManager;

#if defined NR_PLATFORM_WIN32

/**
** @brief ���� Win32 �������
** @return Win32 �������
*/
NR_CAPI NR_ILibraryManager * NR_MakeWin32LibraryManager(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨�������������
** @return �������
*/
NR_CAPI NR_ILibraryManager * NR_MakeLibraryManagerByOSPlatform(void);
