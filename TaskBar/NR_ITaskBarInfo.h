
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief ��������Ϣ�ӿ�
*/
class NR_ITaskBarInfo : public NR_IRefCount
{
public:

	/**
	** @brief �������������еı�Եλ��
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
	** @brief ��ȡ�������������еľ�������
	*/
	virtual bool GetBoundBoxRectInDesktop(int & nPosX, int & nPosY, int & nWidth, int & nHeight) = 0;

	/**
	** @brief ��ȡ�������������еı�Եλ��
	*/
	virtual bool GetEdge(NR_TaskBarEdge & Edge) = 0;
};
