
#pragma once

#include "../NieRLibConfig.h"

class NR_IMemoryAllocator;

/**
** @brief 创建默认内存分配器
** @return 默认内存分配器
*/
NIER_CAPI NR_IMemoryAllocator * NR_MakeDefaultMemoryAllocator(void);

/**
** @brief 自动根据调用者所在平台，创建内存分配器
** @return 内存分配器
*/
NIER_CAPI NR_IMemoryAllocator * NR_MakeMemoryAllocatorByOSPlatform(void);
