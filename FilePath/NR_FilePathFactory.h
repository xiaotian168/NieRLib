
#pragma once

#include "../NieRLibConfig.h"

class NR_IFilePath;

#if defined NIER_PLATFORM_WIN32

/**
** @brief ���� Win32 �ļ�·������
** @return Win32 �ļ�·������
*/
NIER_CAPI NR_IFilePath * MakeWin32FilePath(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨�������ļ�·������
** @return �ļ�·������
*/
NIER_CAPI NR_IFilePath * MakeFilePathByOSPlatform(void);
