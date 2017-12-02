
#define _NR_API

#include "NR_RenderDeviceFactory.h"
#include "NR_CGDIRenderDevice.h"
#include "NR_CGDIPRenderDevice.h"

#if defined NR_PLATFORM_WIN32

class NR_CGDIPStartupHelper
{
public:

	inline NR_CGDIPStartupHelper()
	{
		Gdiplus::GdiplusStartupInput GDIPSI;

		if (!uToken)
		{
			Gdiplus::GdiplusStartup(&uToken, &GDIPSI, 0);
		}
	}

	inline ~NR_CGDIPStartupHelper()
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

ULONG_PTR NR_CGDIPStartupHelper::uToken = 0;

NR_IRenderDevice * NR_MakeGDIRenderDeviceFromHDC(const HDC hDC)
{
	return NR_CGDIRenderDevice::Make(hDC);
}

NR_IRenderDevice * NR_MakeGDIRenderDeviceFromHWND(const HWND hWnd)
{
	return NR_CGDIRenderDevice::Make(hWnd);
}

NR_IRenderDevice * NR_MakeGDIPRenderDeviceFromHDC(const HDC hDC)
{
	static NR_CGDIPStartupHelper GDIPStartupHelper;
	return NR_CGDIPRenderDevice::Make(hDC);
}

NR_IRenderDevice * NR_MakeGDIPRenderDeviceFromHWND(const HWND hWnd)
{
	static NR_CGDIPStartupHelper GDIPStartupHelper;
	return NR_CGDIPRenderDevice::Make(hWnd);
}

#endif
