
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief ���崴�������ṹ��
*/
struct NR_FONTCREATEPARAMW
{
public:

	static const unsigned int MaxFaceNameSize = 64;

	inline NR_FONTCREATEPARAMW()
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
class NR_IFont : public NR_IRefCount
{
public:

	/**
	** @brief ��ȡ���崴��������Ϣ
	*/
	virtual bool GetFontCreateParamW(NR_FONTCREATEPARAMW & FontInfo) = 0;
};
