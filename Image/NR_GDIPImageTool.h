
#pragma once

#include "../NieRLibConfig.h"

#if defined NR_PLATFORM_WIN32

/**
** @brief ���ڴ洴�� GDI+ λͼ����
** @param pBuffer �ڴ�ָ��
** @param uSize �ڴ��С����λ���ֽڣ�
** @return �ɹ����� GDI+ λͼ����ʧ�ܷ��� 0
*/
NR_CAPI Gdiplus::Bitmap * NR_LoadGDIPImageFromBuffer(const void * pBuffer, const unsigned int uSize);

#endif
