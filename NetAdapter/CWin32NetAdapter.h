
#pragma once

#include "INetAdapter.h"

#if defined NIER_PLATFORM_WIN32

class CWin32NetAdapter : public INetAdapter
{
public:

	static CWin32NetAdapter * Make(INetConnection * pNetConnection);

protected:

	CWin32NetAdapter(INetConnection * pNetConnection);

	~CWin32NetAdapter();

public:

	bool GetAdapterNameW(wchar_t * pszName, const unsigned int uSize) override;

	bool RenameAdapterNameW(const wchar_t * pszName) override;

	bool Disconnect(void) override;

	bool Connect(void) override;

	bool Delete(void) override;

	bool IsConnected(void) override;

	bool IsDisconnected(void) override;

	bool IsConnecting(void) override;

	bool IsDisconnecting(void) override;

private:

	INetConnection * m_pConnection;
};

#endif
