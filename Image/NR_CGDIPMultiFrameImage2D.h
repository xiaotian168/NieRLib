
#pragma once

#include "NR_IMultiFrameImage2D.h"

#if defined NR_PLATFORM_WIN32

class NR_CGDIPMultiFrameImage2D : public NR_IMultiFrameImage2D
{
private:

	struct stFrameInfo
	{
		unsigned int uFrameElapse{ 0 };
	};

public:

	friend class NR_CGDIPRenderDevice;

	static NR_CGDIPMultiFrameImage2D * MakeFromFileW(const wchar_t * pszImageFilePath);

	static NR_CGDIPMultiFrameImage2D * MakeFromMemory(const void * pBuffer, const unsigned int uSize);

protected:

	NR_CGDIPMultiFrameImage2D(const wchar_t * pszImageFilePath);

	NR_CGDIPMultiFrameImage2D(const void * pBuffer, const unsigned int uSize);

	~NR_CGDIPMultiFrameImage2D();

public:

	unsigned int GetFrameNum(void) override;

	bool GetFrameElapse(const unsigned int uFrameIndex, unsigned int & uElapse) override;

private:

	bool PrepareImageFrameInfo(void);

	inline Gdiplus::Bitmap * GetGDIPImage(void) const
	{
		return m_pImg;
	}

	inline GUID GetGUIDFirstDimension(void) const
	{
		return m_GUIDFirstDimension;
	}

private:

	Gdiplus::Bitmap * m_pImg{ 0 };
	GUID m_GUIDFirstDimension;
	std::vector<stFrameInfo> m_FrameInfoList;
};

#endif
