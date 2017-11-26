#pragma once

#include "IRenderDevice.h"

#if defined NIER_PLATFORM_WIN32

class CGDIRenderDevice : public IRenderDevice
{
public:

	static CGDIRenderDevice * Make(const HDC hDC);

	static CGDIRenderDevice * Make(const HWND hWnd);

protected:

	CGDIRenderDevice(const HDC hDC);

	CGDIRenderDevice(const HWND hWnd);

	~CGDIRenderDevice();

public:

	IImage2D * CreateImageFromFileW(const wchar_t * pszFilePath) override;

	IFont2D * CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight) override;

	bool RenderImage(IImage2D * pImage, const int nPosX, const int nPosY) override;

	bool RenderTextW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat) override;

	bool RenderLine(const int nX1, const int nY1, const int nX2, const int nY2, const unsigned int uColor) override;

private:

	int ConvertTextFormat(const int nFormat) const;

private:

	HDC m_hDC{ 0 };
	HWND m_hWnd{ 0 };
};

#endif
