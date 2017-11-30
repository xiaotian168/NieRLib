
#pragma once

#include "../NieRLibConfig.h"

class ILibraryManager;

/**
** @brief ���� Win32 �������
** @return Win32 �������
*/
NIER_CAPI ILibraryManager * MakeWin32LibraryManager(void);

/**
** @brief �Զ����ݵ���������ƽ̨�������������
** @return �������
*/
NIER_CAPI ILibraryManager * MakeLibraryManagerByOSPlatform(void);
