
#pragma once

#include "../Base/IRefCount.h"

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
	** @brief 获取指定帧时间间隔（单位：毫秒）
	*/
	virtual bool GetFrameElapse(const unsigned int uFrameIndex, unsigned int & uElapse) = 0;
};
