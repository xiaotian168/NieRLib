
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief 字体信息
*/
struct FONTINFOW
{
public:

	static const unsigned int MaxFaceNameSize = 64;

	inline FONTINFOW()
	{
		memset(szFaceName, 0, sizeof(szFaceName));
	}

public:

	unsigned int uWidth{ 0 };
	unsigned int uHeight{ 0 };
	unsigned int uWeight{ 0 };
	unsigned int uAscent{ 0 };
	unsigned int uDescent{ 0 };
	wchar_t szFaceName[MaxFaceNameSize];
};

/**
** @brief 字体接口
*/
class IFont2D : public IRefCount
{
public:

	/**
	** @brief 获取字体信息
	*/
	virtual bool GetFontInfoW(FONTINFOW & FontInfo) = 0;
};
