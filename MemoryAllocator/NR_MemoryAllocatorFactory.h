
#pragma once

#include "../NieRLibConfig.h"

class NR_IMemoryAllocator;

/**
** @brief ����Ĭ���ڴ������
** @return Ĭ���ڴ������
*/
NIER_CAPI NR_IMemoryAllocator * NR_MakeDefaultMemoryAllocator(void);

/**
** @brief �Զ����ݵ���������ƽ̨�������ڴ������
** @return �ڴ������
*/
NIER_CAPI NR_IMemoryAllocator * NR_MakeMemoryAllocatorByOSPlatform(void);
