
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IImage;
class NR_IFont;

/**
** @brief 渲染设备接口
*/
class NR_IRenderDevice : public NR_IRefCount
{
public:

	/**
	** @brief 字符串绘制格式
	*/
	enum
	{
		eTextFmt_Left = 1,
		eTextFmt_Right = 2,
		eTextFmt_Top = 4,
		eTextFmt_Bottom = 8,
		eTextFmt_HCenter = 16,
		eTextFmt_VCenter = 32,
		eTextFmt_SingleLine = 64,
		eTextFmt_PathEllipsis = 128,
		eTextFmt_WordEllipsis = 256,
		eTextFmt_WordBreak = 512,
	};

public:

	/**
	** @brief 设置裁剪矩形区域
	*/
	virtual bool SetClipRect(const int nX, const int nY, const int nWidth, const int nHeight) = 0;

	/**
	** @brief 获取裁剪矩形区域
	*/
	virtual bool GetClipRect(int & nX, int & nY, int & nWidth, int & nHeight) = 0;

	/**
	** @brief 从文件创建图像
	*/
	virtual NR_IImage * CreateImageFromFileW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief 从内存创建图像
	*/
	virtual NR_IImage * CreateImageFromMemory(const void * pBuffer, const unsigned int uSize) = 0;

	/**
	** @brief 创建字体
	*/
	virtual NR_IFont * CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic) = 0;

	/**
	** @brief 绘制图像
	*/
	virtual bool RenderImage(NR_IImage * pImage, const int nPosX, const int nPosY) = 0;

	/**
	** @brief 绘制图像
	*/
	virtual bool RenderImage(NR_IImage * pImage, const int nDestPosX, const int nDestPosY, const int nDestWidth, const int nDestHeight, const int nSrcX, const int nSrcY, const int nSrcWidth, const int nSrcHeight) = 0;

	/**
	** @brief 绘制字符串
	*/
	virtual bool RenderTextW(NR_IFont * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat) = 0;

	/**
	** @brief 计算字符串大小
	*/
	virtual bool CalcTextSizeW(NR_IFont * pFont, const wchar_t * pszText, const int nLen, const int nFormat, unsigned int & uWidth, unsigned int & uHeight) = 0;

	/**
	** @brief 绘制线段
	*/
	virtual bool RenderLine(const int nX1, const int nY1, const int nX2, const int nY2, const unsigned int uColor) = 0;

	/**
	** @brief 填充矩形
	*/
	virtual bool RenderQuad(const int nX, const int nY, const int nWidth, const int nHeight, const unsigned int uColor) = 0;
};
