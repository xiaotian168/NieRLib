
#pragma once

#include "IRenderDevice.h"
#include "IMultiFrameImageRenderDevice.h"

#if defined NIER_PLATFORM_WIN32

class CGDIPRenderDevice : public IRenderDevice, public IMultiFrameImageRenderDevice
{
public:

	static CGDIPRenderDevice * Make(const HDC hDC);

	static CGDIPRenderDevice * Make(const HWND hWnd);

protected:

	CGDIPRenderDevice(const HDC hDC);

	CGDIPRenderDevice(const HWND hWnd);

	~CGDIPRenderDevice();

public:

	IImage2D * CreateImageFromFileW(const wchar_t * pszFilePath) override;

	IImage2D * CreateImageFromMemory(const void * pBuffer, const unsigned int uSize) override;

	IFont2D * CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic) override;

	bool RenderImage(IImage2D * pImage, const int nPosX, const int nPosY) override;

	bool RenderImage(IImage2D * pImage, const int nDestPosX, const int nDestPosY, const int nDestWidth, const int nDestHeight, const int nSrcX, const int nSrcY, const int nSrcWidth, const int nSrcHeight) override;

	bool RenderTextW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat) override;

	bool CalcTextSizeW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nFormat, unsigned int & uWidth, unsigned int & uHeight) override;

	bool RenderLine(const int nX1, const int nY1, const int nX2, const int nY2, const unsigned int uColor) override;
	
	bool RenderQuad(const int nX, const int nY, const int nWidth, const int nHeight, const unsigned int uColor) override;

public:
	
	IMultiFrameImage2D * CreateMultiFrameImageFromFileW(const wchar_t * pszFile) override;
	
	IMultiFrameImage2D * CreateMultiFrameImageFromMemory(const void * pBuffer, const unsigned uSize) override;

	bool RenderMultiFrameImage(IMultiFrameImage2D * pImage, const unsigned int uFrameIndex, const int nPosX, const int nPosY) override;

private:

	Gdiplus::StringFormat * ConvertTextFormat(const int nFormat) const;

private:

	Gdiplus::Graphics * m_pGraph{ 0 };
};

#endif
