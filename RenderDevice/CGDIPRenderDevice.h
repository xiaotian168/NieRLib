
#pragma once

#include "IRenderDevice.h"

#if defined NIER_PLATFORM_WIN32

class CGDIPRenderDevice : public IRenderDevice
{
public:

	static CGDIPRenderDevice * Make(const HDC hDC);

	static CGDIPRenderDevice * Make(const HWND hWnd);

protected:

	CGDIPRenderDevice(const HDC hDC);

	CGDIPRenderDevice(const HWND hWnd);

	~CGDIPRenderDevice();

public:

	IImage * CreateImageFromFileW(const wchar_t * pszFilePath) override;

	IFont2D * CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight) override;

	bool RenderImage(IImage * pImage, const int nPosX, const int nPosY) override;

	bool RenderTextW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat) override;

private:

	Gdiplus::StringFormat * ConvertTextFormat(const int nFormat) const;

private:

	Gdiplus::Graphics * m_pGraph{ 0 };
};

#endif
