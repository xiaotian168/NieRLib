
#pragma once

#include "../NieRLibConfig.h"

class NR_IRenderDevice;

#if defined NR_PLATFORM_WIN32

/**
** @brief ͨ������ DC ������� Win32 GDI ��Ⱦ�豸
** @return Win32 GDI ��Ⱦ�豸
*/
NR_CAPI NR_IRenderDevice * NR_MakeGDIRenderDeviceFromHDC(const HDC hDC);

/**
** @brief ͨ�����ھ������ Win32 GDI ��Ⱦ�豸
** @return Win32 GDI ��Ⱦ�豸
*/
NR_CAPI NR_IRenderDevice * NR_MakeGDIRenderDeviceFromHWND(const HWND hWnd);

/**
** @brief ͨ������ DC ������� Win32 GDI+ ��Ⱦ�豸
** @return Win32 GDI+ ��Ⱦ�豸
*/
NR_CAPI NR_IRenderDevice * NR_MakeGDIPRenderDeviceFromHDC(const HDC hDC);

/**
** @brief ͨ�����ھ������ Win32 GDI+ ��Ⱦ�豸
** @return Win32 GDI+ ��Ⱦ�豸
*/
NR_CAPI NR_IRenderDevice * NR_MakeGDIPRenderDeviceFromHWND(const HWND hWnd);

#endif
