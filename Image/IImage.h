
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief ͼ��ӿ�
*/
class IImage : public IRefCount
{
public:

	/**
	** @brief ��ȡͼ���С
	*/
	virtual bool GetImageSize(unsigned int & uWidth, unsigned int & uHeight) = 0;
};
