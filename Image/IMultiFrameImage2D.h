
#pragma once

#include "../Base/IRefCount.h"

class IImage2D;

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
	** @brief ��ȡָ��֡ͼ��
	*/
	virtual IImage2D * GetFrameImage(const unsigned int uFrameIndex) = 0;

	/**
	** @brief ��ȡָ��֡ʱ��������λ�����룩
	*/
	virtual unsigned int GetFrameElapse(const unsigned int uFrameIndex) = 0;
};
