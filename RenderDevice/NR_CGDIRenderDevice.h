#pragma once

#include "NR_IRenderDevice.h"

#if defined NR_PLATFORM_WIN32

class NR_CGDIRenderDevice : public NR_IRenderDevice
{
public:

	static NR_CGDIRenderDevice * Make(const HDC hDC);

	static NR_CGDIRenderDevice * Make(const HWND hWnd);

protected:

	NR_CGDIRenderDevice(const HDC hDC);

	NR_CGDIRenderDevice(const HWND hWnd);

	~NR_CGDIRenderDevice();

public:

	bool SetClipRect(const int nX, const int nY, const int nWidth, const int nHeight) override;

	bool GetClipRect(int & nX, int & nY, int & nWidth, int & nHeight) override;

	NR_IImage * CreateImageFromFileW(const wchar_t * pszFilePath) override;

	NR_IImage * CreateImageFromMemory(const void * pBuffer, const unsigned int uSize) override;

	NR_IFont * CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic) override;

	bool RenderImage(NR_IImage * pImage, const int nPosX, const int nPosY) override;

	bool RenderImage(NR_IImage * pImage, const int nDestPosX, const int nDestPosY, const int nDestWidth, const int nDestHeight, const int nSrcX, const int nSrcY, const int nSrcWidth, const int nSrcHeight) override;

	bool RenderTextW(NR_IFont * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat) override;

	bool CalcTextSizeW(NR_IFont * pFont, const wchar_t * pszText, const int nLen, const int nFormat, unsigned int & uWidth, unsigned int & uHeight) override;

	bool RenderLine(const int nX1, const int nY1, const int nX2, const int nY2, const unsigned int uColor) override;

	bool RenderQuad(const int nX, const int nY, const int nWidth, const int nHeight, const unsigned int uColor) override;

private:

	int ConvertTextFormat(const int nFormat) const;

private:

	HDC m_hDC{ 0 };
	HWND m_hWnd{ 0 };
};

#endif
