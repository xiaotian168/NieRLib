
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 图像接口
*/
class NR_IImage : public NR_IRefCount
{
public:

	/**
	** @brief 获取图像大小
	*/
	virtual bool GetImageSize(unsigned int & uWidth, unsigned int & uHeight) = 0;
};
