
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 可以切换大小图标模式的任务栏信息接口
*/
class NR_IIconSizeableTaskBarInfo : public NR_IRefCount
{
public:

	/**
	** @brief 获取任务栏是否被设置为大图标模式
	*/
	virtual bool IsLargeIcon(bool & bIsLargeIcon) = 0;
};
