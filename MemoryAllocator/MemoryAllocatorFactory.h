
#pragma once

#include "../NieRLibConfig.h"

class IMemoryAllocator;

/**
** @brief ����Ĭ���ڴ������
** @return Ĭ���ڴ������
*/
NIER_CAPI IMemoryAllocator * MakeDefaultMemoryAllocator(void);

/**
** @brief �Զ����ݵ���������ƽ̨�������ڴ������
** @return �ڴ������
*/
NIER_CAPI IMemoryAllocator * MakeMemoryAllocatorByOSPlatform(void);
