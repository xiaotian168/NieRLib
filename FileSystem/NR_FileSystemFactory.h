
#pragma once

#include "../NieRLibConfig.h"

class NR_IFileSystem;

#if defined NIER_PLATFORM_WIN32

/**
** @brief ���� Win32 �ļ�ϵͳ
** @return Win32 �ļ�ϵͳ
*/
NIER_CAPI NR_IFileSystem * NR_MakeWin32FileSystem(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨�������ļ�ϵͳ
** @return �ļ�ϵͳ
*/
NIER_CAPI NR_IFileSystem * NR_MakeFileSystemByOSPlatform(void);
