
#pragma once

#include "../NieRLibConfig.h"

class IFileEnumerator;

/**
** @brief ���� Win32 �ļ�ö����
** @return Win32 �ļ�ö����
*/
NIER_CAPI IFileEnumerator * MakeWin32FileEnumerator(void);

/**
** @brief �Զ����ݵ���������ƽ̨�������ļ�ö����
** @return �ļ�ö����
*/
NIER_CAPI IFileEnumerator * MakeFileEnumeratorByOSPlatform(void);
