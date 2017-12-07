
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 窗口接口
*/
class NR_IWindow : public NR_IRefCount
{
public:

	/**
	** @brief 隐藏窗口
	*/
	virtual bool Hide(void) = 0;

	/**
	** @brief 显示窗口
	*/
	virtual bool Show(void) = 0;

	/**
	** @brief 设置窗口文本
	*/
	virtual bool SetTitleW(const wchar_t * pszTitle) = 0;
};
