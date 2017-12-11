
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief �����л���Сͼ��ģʽ����������Ϣ�ӿ�
*/
class NR_IIconSizeableTaskBarInfo : public NR_IRefCount
{
public:

	/**
	** @brief ��ȡ�������Ƿ�����Ϊ��ͼ��ģʽ
	*/
	virtual bool IsLargeIcon(bool & bIsLargeIcon) = 0;
};
