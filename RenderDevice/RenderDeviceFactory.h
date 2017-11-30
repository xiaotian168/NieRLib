
#pragma once

#include "../NieRLibConfig.h"

class IRenderDevice;

/**
** @brief ͨ������ DC ������� Win32 GDI ��Ⱦ�豸
** @return Win32 GDI ��Ⱦ�豸
*/
NIER_CAPI IRenderDevice * MakeGDIRenderDeviceFromHDC(const HDC hDC);

/**
** @brief ͨ�����ھ������ Win32 GDI ��Ⱦ�豸
** @return Win32 GDI ��Ⱦ�豸
*/
NIER_CAPI IRenderDevice * MakeGDIRenderDeviceFromHWND(const HWND hWnd);

/**
** @brief ͨ������ DC ������� Win32 GDI+ ��Ⱦ�豸
** @return Win32 GDI+ ��Ⱦ�豸
*/
NIER_CAPI IRenderDevice * MakeGDIPRenderDeviceFromHDC(const HDC hDC);

/**
** @brief ͨ�����ھ������ Win32 GDI+ ��Ⱦ�豸
** @return Win32 GDI+ ��Ⱦ�豸
*/
NIER_CAPI IRenderDevice * MakeGDIPRenderDeviceFromHWND(const HWND hWnd);
