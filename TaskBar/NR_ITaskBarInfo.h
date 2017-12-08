
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 任务栏信息接口
*/
class NR_ITaskBarInfo : public NR_IRefCount
{
public:

	/**
	** @brief 任务栏在桌面中的边缘位置
	*/
	enum NR_TaskBarEdge
	{
		eTaskBarEdge_Unknown,
		eTaskBarEdge_Left,
		eTaskBarEdge_Right,
		eTaskBarEdge_Top,
		eTaskBarEdge_Bottom,
	};

public:

	/**
	** @brief 获取任务栏在桌面中的矩形区域
	*/
	virtual bool GetBoundBoxRectInDesktop(int & nPosX, int & nPosY, int & nWidth, int & nHeight) = 0;

	/**
	** @brief 获取任务栏在桌面中的边缘位置
	*/
	virtual bool GetEdge(NR_TaskBarEdge & Edge) = 0;
};
