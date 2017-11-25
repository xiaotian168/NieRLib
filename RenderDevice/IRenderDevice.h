
#pragma once

#include "../Base/IRefCount.h"

class IImage;
class IFont2D;

/**
** @brief 选人设备接口
*/
class IRenderDevice : public IRefCount
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
	** @brief 从文件创建图像
	*/
	virtual IImage * CreateImageFromFileW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief 创建字体
	*/
	virtual IFont2D * CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight) = 0;

	/**
	** @brief 绘制图像
	*/
	virtual bool RenderImage(IImage * pImage, const int nPosX, const int nPosY) = 0;

	/**
	** @brief 绘制字符串
	*/
	virtual bool RenderTextW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat) = 0;
};
