
#pragma once

/**
** @brief ��������ӿ�
*/
class INameObject
{
public:

	/**
	** @brief ��������
	*/
	virtual bool SetNameW(const wchar_t * pszName) = 0;

	/**
	** @brief ��ȡ����
	*/
	virtual const wchar_t * GetNameW(void) const = 0;
};
