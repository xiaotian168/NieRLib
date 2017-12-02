
#pragma once

/**
** @brief ID ����ӿ�
*/
class NR_IIDObject
{
public:

	typedef unsigned long long IDType;

public:

	/**
	** @brief ���� ID
	*/
	virtual bool SetID(const IDType & ID) = 0;

	/**
	** @brief ��ȡ ID
	*/
	virtual IDType GetID(void) const = 0;
};
