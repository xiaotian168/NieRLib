
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief ��������������Ϣ�ӿ�
*/
class NR_IHideableTaskBarInfo : public NR_IRefCount
{
public:

	/**
	** @brief ��ȡ�������Ƿ�����Ϊ�Զ�����
	*/
	virtual bool IsAutoHide(bool & bAutoHide) = 0;
};
