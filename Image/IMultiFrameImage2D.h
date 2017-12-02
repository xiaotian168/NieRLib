
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief ��֡ͼ��ӿ�
*/
class IMultiFrameImage2D : public IRefCount
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
