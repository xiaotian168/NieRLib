
#pragma once

#include "../NieRLibConfig.h"

class IRenderDevice;

/**
** @brief 通过窗口 DC 句柄创建 Win32 GDI 渲染设备
** @return Win32 GDI 渲染设备
*/
NIER_CAPI IRenderDevice * MakeGDIRenderDeviceFromHDC(const HDC hDC);

/**
** @brief 通过窗口句柄创建 Win32 GDI 渲染设备
** @return Win32 GDI 渲染设备
*/
NIER_CAPI IRenderDevice * MakeGDIRenderDeviceFromHWND(const HWND hWnd);

/**
** @brief 通过窗口 DC 句柄创建 Win32 GDI+ 渲染设备
** @return Win32 GDI+ 渲染设备
*/
NIER_CAPI IRenderDevice * MakeGDIPRenderDeviceFromHDC(const HDC hDC);

/**
** @brief 通过窗口句柄创建 Win32 GDI+ 渲染设备
** @return Win32 GDI+ 渲染设备
*/
NIER_CAPI IRenderDevice * MakeGDIPRenderDeviceFromHWND(const HWND hWnd);
