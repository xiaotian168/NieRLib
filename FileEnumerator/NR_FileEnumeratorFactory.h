
#pragma once

#include "../NieRLibConfig.h"

class NR_IFileEnumerator;

#if defined NR_PLATFORM_WIN32

/**
** @brief ���� Win32 �ļ�ö����
** @return Win32 �ļ�ö����
*/
NR_CAPI NR_IFileEnumerator * NR_MakeWin32FileEnumerator(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨�������ļ�ö����
** @return �ļ�ö����
*/
NR_CAPI NR_IFileEnumerator * NR_MakeFileEnumeratorByOSPlatform(void);
