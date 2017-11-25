
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

IRenderDevice * MakeGDIRenderDeviceFromHDC(const HDC hDC)
{
	return CGDIRenderDevice::Make(hDC);
}

IRenderDevice * MakeGDIRenderDeviceFromHWND(const HWND hWnd)
{
	return CGDIRenderDevice::Make(hWnd);
}

IRenderDevice * MakeGDIPRenderDeviceFromHDC(const HDC hDC)
{
	static CGDIPStartupHelper GDIPStartupHelper;
	return CGDIPRenderDevice::Make(hDC);
}

IRenderDevice * MakeGDIPRenderDeviceFromHWND(const HWND hWnd)
{
	static CGDIPStartupHelper GDIPStartupHelper;
	return CGDIPRenderDevice::Make(hWnd);
}

#endif
