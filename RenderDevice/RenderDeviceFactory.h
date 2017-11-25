
#pragma once

#include "../NieRLibConfig.h"

class IRenderDevice;

#if defined NIER_PLATFORM_WIN32

NIER_CAPI IRenderDevice * MakeGDIRenderDeviceFromHDC(const HDC hDC);

NIER_CAPI IRenderDevice * MakeGDIRenderDeviceFromHWND(const HWND hWnd);

NIER_CAPI IRenderDevice * MakeGDIPRenderDeviceFromHDC(const HDC hDC);

NIER_CAPI IRenderDevice * MakeGDIPRenderDeviceFromHWND(const HWND hWnd);

#endif
