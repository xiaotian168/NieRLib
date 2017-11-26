
#pragma once

#include "../Base/IRefCount.h"

class IImage2D;

/**
** @brief 多帧图像接口
*/
class IMultiFrameImage2D : public IRefCount
{
public:

	/**
	** @brief 获取帧数量
	*/
	virtual unsigned int GetFrameNum(void) = 0;

	/**
	** @brief 获取指定帧图像
	*/
	virtual IImage2D * GetFrameImage(const unsigned int uFrameIndex) = 0;

	/**
	** @brief 获取指定帧时间间隔（单位：毫秒）
	*/
	virtual unsigned int GetFrameElapse(const unsigned int uFrameIndex) = 0;
};
