
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief ��֡ͼ��ӿ�
*/
class NR_IMultiFrameImage2D : public NR_IRefCount
{
public:

	/**
	** @brief ��ȡ֡����
	*/
	virtual unsigned int GetFrameNum(void) = 0;

	/**
	** @brief ��ȡָ��֡ʱ��������λ�����룩
	*/
	virtual bool GetFrameElapse(const unsigned int uFrameIndex, unsigned int & uElapse) = 0;
};
