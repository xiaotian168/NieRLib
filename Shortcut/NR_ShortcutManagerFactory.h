
#pragma once

#include "../NieRLibConfig.h"

class NR_IShortcutManager;

#if defined NR_PLATFORM_WIN32

/**
** @brief ���� Win32 ��ݷ�ʽ������
** @return Win32 ��ݷ�ʽ������
*/
NR_CAPI NR_IShortcutManager * MakeWin32ShortcutManager(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨��������ݷ�ʽ������
** @return ��ݷ�ʽ������
*/
NR_CAPI NR_IShortcutManager * MakeShortcutManagerByOSPlatform(void);
