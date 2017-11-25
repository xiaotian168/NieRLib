

#include "CWin32NetAdapter.h"
#include "../Base/COMTool.h"
#include <ObjBase.h>
#pragma comment(lib, "Ole32.lib")

CWin32NetAdapter * CWin32NetAdapter::Make(INetConnection * pNetConnection)
{
	return new CWin32NetAdapter(pNetConnection);
}

CWin32NetAdapter::CWin32NetAdapter(INetConnection * pNetConnection)
{
	m_pConnection = pNetConnection;
}

CWin32NetAdapter::~CWin32NetAdapter()
{
	SAFE_RELEASE(m_pConnection);
}

bool CWin32NetAdapter::GetAdapterNameW(wchar_t * pszName, const unsigned int uSize)
{
	bool bRet = false;
	NETCON_PROPERTIES * pProperties = 0;

	if (m_pConnection && pszName && uSize)
	{
		if (SUCCEEDED(m_pConnection->GetProperties(&pProperties)))
		{
			if (pProperties->pszwName)
			{
				wcscpy_s(pszName, uSize, pProperties->pszwName);
				bRet = true;
			}

			CoTaskMemFree(pProperties);
			pProperties = 0;
		}
	}

	return bRet;
}

bool CWin32NetAdapter::RenameAdapterNameW(const wchar_t * pszName)
{
	bool bRet = false;

	if (m_pConnection && pszName)
	{
		if (SUCCEEDED(m_pConnection->Rename(pszName)))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool CWin32NetAdapter::Disconnect(void)
{
	bool bRet = false;

	if (m_pConnection)
	{
		if (SUCCEEDED(m_pConnection->Disconnect()))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool CWin32NetAdapter::Connect(void)
{
	bool bRet = false;

	if (m_pConnection)
	{
		if (SUCCEEDED(m_pConnection->Connect()))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool CWin32NetAdapter::Delete(void)
{
	bool bRet = false;

	if (m_pConnection)
	{
		if (SUCCEEDED(m_pConnection->Delete()))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool CWin32NetAdapter::IsConnected(void)
{
	bool bRet = false;
	NETCON_PROPERTIES * pProperties = 0;

	if (m_pConnection)
	{
		if (SUCCEEDED(m_pConnection->GetProperties(&pProperties)))
		{
			if (NCS_CONNECTED == pProperties->Status)
			{
				bRet = true;
			}

			CoTaskMemFree(pProperties);
			pProperties = 0;
		}
	}

	return bRet;
}

bool CWin32NetAdapter::IsDisconnected(void)
{
	bool bRet = false;
	NETCON_PROPERTIES * pProperties = 0;

	if (m_pConnection)
	{
		if (SUCCEEDED(m_pConnection->GetProperties(&pProperties)))
		{
			if (NCS_DISCONNECTED == pProperties->Status)
			{
				bRet = true;
			}

			CoTaskMemFree(pProperties);
			pProperties = 0;
		}
	}

	return bRet;
}

bool CWin32NetAdapter::IsConnecting(void)
{
	bool bRet = false;
	NETCON_PROPERTIES * pProperties = 0;

	if (m_pConnection)
	{
		if (SUCCEEDED(m_pConnection->GetProperties(&pProperties)))
		{
			if (NCS_CONNECTING == pProperties->Status)
			{
				bRet = true;
			}

			CoTaskMemFree(pProperties);
			pProperties = 0;
		}
	}

	return bRet;
}

bool CWin32NetAdapter::IsDisconnecting(void)
{
	bool bRet = false;
	NETCON_PROPERTIES * pProperties = 0;

	if (m_pConnection)
	{
		if (SUCCEEDED(m_pConnection->GetProperties(&pProperties)))
		{
			if (NCS_DISCONNECTING == pProperties->Status)
			{
				bRet = true;
			}

			CoTaskMemFree(pProperties);
			pProperties = 0;
		}
	}

	return bRet;
}
