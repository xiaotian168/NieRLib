
#pragma once

#include "../NieRLibConfig.h"

class NR_IShortcutManager;

#if defined NIER_PLATFORM_WIN32

/**
** @brief ���� Win32 ��ݷ�ʽ������
** @return Win32 ��ݷ�ʽ������
*/
NIER_CAPI NR_IShortcutManager * MakeWin32ShortcutManager(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨��������ݷ�ʽ������
** @return ��ݷ�ʽ������
*/
NIER_CAPI NR_IShortcutManager * MakeShortcutManagerByOSPlatform(void);
