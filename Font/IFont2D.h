
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief ������Ϣ
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
** @brief ����ӿ�
*/
class IFont2D : public IRefCount
{
public:

	/**
	** @brief ��ȡ������Ϣ
	*/
	virtual bool GetFontInfoW(FONTINFOW & FontInfo) = 0;
};
