
#pragma once

#include "IMultiFrameImage2D.h"

#if defined NIER_PLATFORM_WIN32

class CGDIPMultiFrameImage2D : public IMultiFrameImage2D
{
private:

	struct stFrameInfo
	{
		IImage2D * pImg{ 0 };
		unsigned int uFrameElapse{ 0 };
	};

public:

	static CGDIPMultiFrameImage2D * MakeFromFileW(const wchar_t * pszImageFilePath);

protected:

	CGDIPMultiFrameImage2D(const wchar_t * pszImageFilePath);

	~CGDIPMultiFrameImage2D();

public:

	unsigned int GetFrameNum(void) override;

	IImage2D * GetFrameImage(const unsigned int uFrameIndex) override;

	unsigned int GetFrameElapse(const unsigned int uFrameIndex) override;

private:

	Gdiplus::Image * m_pImg{ 0 };
	std::vector<stFrameInfo> m_FrameInfoList;
};

#endif
