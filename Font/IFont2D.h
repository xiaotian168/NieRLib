
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief ���崴�������ṹ��
*/
struct FONTCREATEPARAMW
{
public:

	static const unsigned int MaxFaceNameSize = 64;

	inline FONTCREATEPARAMW()
	{
		memset(szFaceName, 0, sizeof(szFaceName));
	}

public:

	unsigned int uWidth{ 0 };
	unsigned int uHeight{ 0 };
	unsigned int uWeight{ 0 };
	wchar_t szFaceName[MaxFaceNameSize];
	bool bItalic{ false };
};

/**
** @brief ����ӿ�
*/
class IFont2D : public IRefCount
{
public:

	/**
	** @brief ��ȡ���崴��������Ϣ
	*/
	virtual bool GetFontCreateParamW(FONTCREATEPARAMW & FontInfo) = 0;
};
