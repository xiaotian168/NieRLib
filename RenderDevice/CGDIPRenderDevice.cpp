
#include "CGDIPRenderDevice.h"
#include "../Image/CGDIPImage.h"
#include "../Font/CGDIPFont.h"

#if defined NIER_PLATFORM_WIN32

CGDIPRenderDevice * CGDIPRenderDevice::Make(const HDC hDC)
{
	return new CGDIPRenderDevice(hDC);
}

CGDIPRenderDevice * CGDIPRenderDevice::Make(const HWND hWnd)
{
	return new CGDIPRenderDevice(hWnd);
}

CGDIPRenderDevice::CGDIPRenderDevice(const HDC hDC)
{
	m_pGraph = Gdiplus::Graphics::FromHDC(hDC);
}

CGDIPRenderDevice::CGDIPRenderDevice(const HWND hWnd)
{
	if (IsWindow(hWnd))
	{
		m_pGraph = Gdiplus::Graphics::FromHWND(hWnd);
	}
}

CGDIPRenderDevice::~CGDIPRenderDevice()
{
	if (m_pGraph)
	{
		delete m_pGraph;
		m_pGraph = 0;
	}
}

IImage * CGDIPRenderDevice::CreateImageFromFileW(const wchar_t * pszFilePath)
{
	return 0;
}

IFont2D * CGDIPRenderDevice::CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight)
{
	return 0;
}

bool CGDIPRenderDevice::RenderImage(IImage * pImage, const int nPosX, const int nPosY)
{
	bool bRet = false;

	return bRet;
}

bool CGDIPRenderDevice::RenderTextW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat)
{
	bool bRet = false;

	return bRet;
}

Gdiplus::StringFormat * CGDIPRenderDevice::ConvertTextFormat(const int nFormat) const
{
	Gdiplus::StringFormat * pFmt = 0;

	return pFmt;
}

#endif
