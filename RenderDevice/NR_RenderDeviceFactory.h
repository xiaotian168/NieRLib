
#pragma once

#include "../NieRLibConfig.h"

class NR_IRenderDevice;

#if defined NIER_PLATFORM_WIN32

/**
** @brief 通过窗口 DC 句柄创建 Win32 GDI 渲染设备
** @return Win32 GDI 渲染设备
*/
NIER_CAPI NR_IRenderDevice * NR_MakeGDIRenderDeviceFromHDC(const HDC hDC);

/**
** @brief 通过窗口句柄创建 Win32 GDI 渲染设备
** @return Win32 GDI 渲染设备
*/
NIER_CAPI NR_IRenderDevice * NR_MakeGDIRenderDeviceFromHWND(const HWND hWnd);

/**
** @brief 通过窗口 DC 句柄创建 Win32 GDI+ 渲染设备
** @return Win32 GDI+ 渲染设备
*/
NIER_CAPI NR_IRenderDevice * NR_MakeGDIPRenderDeviceFromHDC(const HDC hDC);

/**
** @brief 通过窗口句柄创建 Win32 GDI+ 渲染设备
** @return Win32 GDI+ 渲染设备
*/
NIER_CAPI NR_IRenderDevice * NR_MakeGDIPRenderDeviceFromHWND(const HWND hWnd);

#endif
