
#pragma once

#include "../NieRLibConfig.h"

#if defined NIER_PLATFORM_WIN32

/**
** @brief 从内存创建 GDI+ 位图对象
** @param pBuffer 内存指针
** @param uSize 内存大小（单位：字节）
** @return 成功返回 GDI+ 位图对象，失败返回 0
*/
NIER_CAPI Gdiplus::Bitmap * NR_LoadGDIPImageFromBuffer(const void * pBuffer, const unsigned int uSize);

#endif
