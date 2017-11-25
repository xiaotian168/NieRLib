
#include "NetAdapterTool.h"
#include "NetAdapterManagerFactory.h"
#include "INetAdapterManager.h"
#include "INetAdapter.h"

bool DisconnectAllNetAdapter(void)
{
	bool bRet = false;
	std::list<INetAdapter *> NetAdapterList;
	unsigned int uSucceededDisconnectNetAdapterNum = 0;

	auto pNetAdapterMgr = MakeWin32NetAdapterManager();
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

bool ConnectAllNetAdapter(void)
{
	bool bRet = false;
	std::list<INetAdapter *> NetAdapterList;
	unsigned int uSucceededConnectNetAdapterNum = 0;

	auto pNetAdapterMgr = MakeWin32NetAdapterManager();
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
