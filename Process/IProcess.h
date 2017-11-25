
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief ���̽ӿ�
*/
class IProcess : public IRefCount
{
public:

	typedef unsigned int IDType;

public:

	/**
	** @brief ��ȡ���� ID
	*/
	virtual bool GetProcessID(IDType & ID) = 0;

	/**
	** @brief ��ȡ������
	*/
	virtual bool GetProcessNameW(wchar_t * pszName, const unsigned int uSize) = 0;

	/**
	** @brief �رս���
	*/
	virtual bool ShutdownProcess(const unsigned int uExitCode) = 0;
};