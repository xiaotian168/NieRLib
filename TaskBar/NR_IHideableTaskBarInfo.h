
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 可隐藏任务栏信息接口
*/
class NR_IHideableTaskBarInfo : public NR_IRefCount
{
public:

	/**
	** @brief 获取任务栏是否被设置为自动隐藏
	*/
	virtual bool IsAutoHide(bool & bAutoHide) = 0;
};
