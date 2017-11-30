
#define _NIER_API

#include "RenderDeviceFactory.h"
#include "CGDIRenderDevice.h"
#include "CGDIPRenderDevice.h"

#if defined NIER_PLATFORM_WIN32

class CGDIPStartupHelper
{
public:

	inline CGDIPStartupHelper()
	{
		Gdiplus::GdiplusStartupInput GDIPSI;

		if (!uToken)
		{
			Gdiplus::GdiplusStartup(&uToken, &GDIPSI, 0);
		}
	}

	inline ~CGDIPStartupHelper()
	{
		if (uToken)
		{
			Gdiplus::GdiplusShutdown(uToken);
			uToken = 0;
		}
	}

private:

	static ULONG_PTR uToken;
};

ULONG_PTR CGDIPStartupHelper::uToken = 0;

#endif

IRenderDevice * MakeGDIRenderDeviceFromHDC(const HDC hDC)
{
#if defined NIER_PLATFORM_WIN32
	return CGDIRenderDevice::Make(hDC);
#endif

	return 0;
}

IRenderDevice * MakeGDIRenderDeviceFromHWND(const HWND hWnd)
{
#if defined NIER_PLATFORM_WIN32
	return CGDIRenderDevice::Make(hWnd);
#endif

	return 0;
}

IRenderDevice * MakeGDIPRenderDeviceFromHDC(const HDC hDC)
{
#if defined NIER_PLATFORM_WIN32
	static CGDIPStartupHelper GDIPStartupHelper;
	return CGDIPRenderDevice::Make(hDC);
#endif

	return 0;
}

IRenderDevice * MakeGDIPRenderDeviceFromHWND(const HWND hWnd)
{
#if defined NIER_PLATFORM_WIN32
	static CGDIPStartupHelper GDIPStartupHelper;
	return CGDIPRenderDevice::Make(hWnd);
#endif

	return 0;
}
