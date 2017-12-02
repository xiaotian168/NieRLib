
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief 字体创建参数结构体
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
** @brief 字体接口
*/
class IFont2D : public IRefCount
{
public:

	/**
	** @brief 获取字体创建参数信息
	*/
	virtual bool GetFontCreateParamW(FONTCREATEPARAMW & FontInfo) = 0;
};
