
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IWindow;
class NR_IApplicationStartupParam;

/**
** @brief 应用程序接口
*/
class NR_IApplication : public NR_IRefCount
{
public:

	/**
	** @brief 初始化应用程序
	*/
	virtual bool InitApplication(NR_IApplicationStartupParam * pStartupParam) = 0;

	/**
	** @brief 反始化应用程序
	*/
	virtual void UninitApplication(void) = 0;

	/**
	** @brief 创建窗口
	*/
	virtual NR_IWindow * MakeWindowW(const wchar_t * pszTitle, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight) = 0;
};
