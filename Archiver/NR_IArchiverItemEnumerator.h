
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IArchiverItem;

/**
** @brief �鵵�ļ�Ԫ��ö�����ӿ�
*/
class NR_IArchiverItemEnumerator : public NR_IRefCount
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
	virtual NR_IArchiverItem * GetCurrentItem(void) = 0;
};
