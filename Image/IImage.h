
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief 图像接口
*/
class IImage : public IRefCount
{
public:

	/**
	** @brief 获取图像大小
	*/
	virtual bool GetImageSize(unsigned int & uWidth, unsigned int & uHeight) = 0;
};
