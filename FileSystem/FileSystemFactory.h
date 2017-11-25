
#pragma once

#include "../NieRLibConfig.h"

class IFileSystem;

/**
** @brief ���� Win32 �ļ�ϵͳ
** @return Win32 �ļ�ϵͳ
*/
NIER_CAPI IFileSystem * MakeWin32FileSystem(void);

/**
** @brief �Զ����ݵ���������ƽ̨�������ļ�ϵͳ
** @return �ļ�ϵͳ
*/
NIER_CAPI IFileSystem * MakeFileSystemByOSPlatform(void);
