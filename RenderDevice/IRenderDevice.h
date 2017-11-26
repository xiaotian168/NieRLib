
#pragma once

#include "../Base/IRefCount.h"

class IImage2D;
class IFont2D;

/**
** @brief ѡ���豸�ӿ�
*/
class IRenderDevice : public IRefCount
{
public:

	/**
	** @brief �ַ������Ƹ�ʽ
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
	** @brief ���ļ�����ͼ��
	*/
	virtual IImage2D * CreateImageFromFileW(const wchar_t * pszFilePath) = 0;

	/**
	** @brief ��������
	*/
	virtual IFont2D * CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight) = 0;

	/**
	** @brief ����ͼ��
	*/
	virtual bool RenderImage(IImage2D * pImage, const int nPosX, const int nPosY) = 0;

	/**
	** @brief �����ַ���
	*/
	virtual bool RenderTextW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat) = 0;

	/**
	** @brief �����߶�
	*/
	virtual bool RenderLine(const int nX1, const int nY1, const int nX2, const int nY2, const unsigned int uColor) = 0;
};
