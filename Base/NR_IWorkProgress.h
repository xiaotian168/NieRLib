
#pragma once

#include "NR_IRefCount.h"

/**
** @brief ���Ƚӿ�
*/
class NIER_API NR_IWorkProgress : public NR_IRefCount
{
public:

	typedef unsigned int ProgressType;

public:

	/**
	** @brief ����������
	*/
	virtual bool SetMaxProgress(const ProgressType & MaxProgress) = 0;

	/**
	** @brief ���ý���
	*/
	virtual bool SetProgress(const ProgressType & Progress) = 0;

	/**
	** @brief ��ȡ����
	*/
	virtual ProgressType GetProgress(void) const = 0;

	/**
	** @brief ����֪ͨ�ӿ�
	*/
	virtual void OnProgress(void) = 0;
};
