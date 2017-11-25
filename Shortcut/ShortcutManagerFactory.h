
#pragma once

#include "../NieRLibConfig.h"

class IShortcutManager;

/**
** @brief ���� Win32 ��ݷ�ʽ������
** @return Win32 ��ݷ�ʽ������
*/
NIER_CAPI IShortcutManager * MakeWin32ShortcutManager(void);

/**
** @brief �Զ����ݵ���������ƽ̨��������ݷ�ʽ������
** @return ��ݷ�ʽ������
*/
NIER_CAPI IShortcutManager * MakeShortcutManagerByOSPlatform(void);
