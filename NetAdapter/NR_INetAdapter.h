
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief �����������ӿ�
*/
class NR_INetAdapter : public NR_IRefCount
{
public:

	/**
	** @brief ��ȡ����������
	*/
	virtual bool GetAdapterNameW(wchar_t * pszName, const unsigned int uSize) = 0;

	/**
	** @brief ����������������
	*/
	virtual bool RenameAdapterNameW(const wchar_t * pszName) = 0;

	/**
	** @brief �Ͽ�����������
	*/
	virtual bool Disconnect(void) = 0;

	/**
	** @brief ��������������
	*/
	virtual bool Connect(void) = 0;

	/**
	** @brief ɾ��������
	*/
	virtual bool Delete(void) = 0;

	/**
	** @brief �Ƿ�������
	*/
	virtual bool IsConnected(void) = 0;

	/**
	** @brief �Ƿ��ѶϿ�����
	*/
	virtual bool IsDisconnected(void) = 0;

	/**
	** @brief �Ƿ�������
	*/
	virtual bool IsConnecting(void) = 0;

	/**
	** @brief �Ƿ�Ͽ�������
	*/
	virtual bool IsDisconnecting(void) = 0;
};
