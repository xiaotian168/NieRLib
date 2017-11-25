
#pragma once

#include "../Base/IRefCount.h"

class IArchiverItem;

/**
** @brief �鵵�ļ�Ԫ��ö�����ӿ�
*/
class IArchiverItemEnumerator : public IRefCount
{
public:

	/**
	** @brief ��ʼö��
	*/
	virtual bool BeginEnum(void) = 0;

	/**
	** @brief ֹͣö��
	*/
	virtual bool EndEnum(void) = 0;

	/**
	** @brief ��һ��Ԫ��
	*/
	virtual bool NextItem(void) = 0;

	/**
	** @brief ��ȡ��ǰԪ��
	*/
	virtual IArchiverItem * GetCurrentItem(void) = 0;
};
