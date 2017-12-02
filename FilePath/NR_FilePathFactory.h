
#pragma once

#include "../NieRLibConfig.h"

class NR_IFilePath;

#if defined NR_PLATFORM_WIN32

/**
** @brief ���� Win32 �ļ�·������
** @return Win32 �ļ�·������
*/
NR_CAPI NR_IFilePath * MakeWin32FilePath(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨�������ļ�·������
** @return �ļ�·������
*/
NR_CAPI NR_IFilePath * MakeFilePathByOSPlatform(void);
