
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief ͼ��ӿ�
*/
class NR_IImage : public NR_IRefCount
{
public:

	/**
	** @brief ��ȡͼ���С
	*/
	virtual bool GetImageSize(unsigned int & uWidth, unsigned int & uHeight) = 0;
};
