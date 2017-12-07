
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IWindow;
class NR_CWindowEvent;
class NR_CSystemEvent;

/**
** @brief 应用程序事件接受器接口
*/
class NR_IApplicationEventReceiver : public NR_IRefCount
{
public:

	/**
	** @brief 窗口事件回调函数
	*/
	virtual void OnWindowEvent(NR_IWindow * pWindow, NR_CWindowEvent * pEvent) { }

	/**
	** @brief 系统事件回调函数
	*/
	virtual void OnSystemEvent(NR_CSystemEvent * pEvent) { }
};
