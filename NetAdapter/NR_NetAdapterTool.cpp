
#define _NR_API

#include "NR_NetAdapterTool.h"
#include "NR_NetAdapterManagerFactory.h"
#include "NR_INetAdapterManager.h"
#include "NR_INetAdapter.h"

bool NR_DisconnectAllNetAdapter(void)
{
	bool bRet = false;
	std::list<NR_INetAdapter *> NetAdapterList;
	unsigned int uSucceededDisconnectNetAdapterNum = 0;

	auto pNetAdapterMgr = NR_MakeWin32NetAdapterManager();
	if (pNetAdapterMgr)
	{
		if (pNetAdapterMgr->QueryAdapterList(NetAdapterList))
		{
			for (auto pNetAdapter : NetAdapterList)
			{
				if (pNetAdapter)
				{
					if (pNetAdapter->Disconnect())
					{
						++uSucceededDisconnectNetAdapterNum;
					}

					SAFE_RELEASE(pNetAdapter);
				}
			}

			if (uSucceededDisconnectNetAdapterNum == NetAdapterList.size())
			{
				bRet = true;
			}
		}

		SAFE_RELEASE(pNetAdapterMgr);
	}

	return bRet;
}

bool NR_ConnectAllNetAdapter(void)
{
	bool bRet = false;
	std::list<NR_INetAdapter *> NetAdapterList;
	unsigned int uSucceededConnectNetAdapterNum = 0;

	auto pNetAdapterMgr = NR_MakeWin32NetAdapterManager();
	if (pNetAdapterMgr)
	{
		if (pNetAdapterMgr->QueryAdapterList(NetAdapterList))
		{
			for (auto pNetAdapter : NetAdapterList)
			{
				if (pNetAdapter)
				{
					if (pNetAdapter->Connect())
					{
						++uSucceededConnectNetAdapterNum;
					}

					SAFE_RELEASE(pNetAdapter);
				}
			}

			if (uSucceededConnectNetAdapterNum == NetAdapterList.size())
			{
				bRet = true;
			}
		}

		SAFE_RELEASE(pNetAdapterMgr);
	}

	return bRet;
}
