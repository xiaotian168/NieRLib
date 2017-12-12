
#define _NR_API

#include "NR_NetAdapterTool.h"
#include "NR_NetAdapterManagerFactory.h"
#include "NR_INetAdapterManager.h"
#include "NR_INetAdapter.h"

class NR_CNetAdapterToolHelper
{
public:

	inline NR_CNetAdapterToolHelper()
	{
		if (!pNetAdapterManager)
		{
			pNetAdapterManager = NR_MakeNetAdapterManagerByOSPlatform();
		}
	}

	inline ~NR_CNetAdapterToolHelper()
	{
		NR_SAFE_RELEASE(pNetAdapterManager);
	}

public:

	static NR_INetAdapterManager * pNetAdapterManager;
};

NR_INetAdapterManager * NR_CNetAdapterToolHelper::pNetAdapterManager = 0;
NR_CNetAdapterToolHelper NetAdapterToolHelper;

bool NR_DisconnectAllNetAdapter(void)
{
	bool bRet = false;
	std::list<NR_INetAdapter *> NetAdapterList;
	unsigned int uSucceededDisconnectNetAdapterNum = 0;

	if (NR_CNetAdapterToolHelper::pNetAdapterManager)
	{
		if (NR_CNetAdapterToolHelper::pNetAdapterManager->QueryAdapterList(NetAdapterList))
		{
			for (auto pNetAdapter : NetAdapterList)
			{
				if (pNetAdapter)
				{
					if (pNetAdapter->Disconnect())
					{
						++uSucceededDisconnectNetAdapterNum;
					}

					NR_SAFE_RELEASE(pNetAdapter);
				}
			}

			if (uSucceededDisconnectNetAdapterNum == NetAdapterList.size())
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool NR_ConnectAllNetAdapter(void)
{
	bool bRet = false;
	std::list<NR_INetAdapter *> NetAdapterList;
	unsigned int uSucceededConnectNetAdapterNum = 0;

	if (NR_CNetAdapterToolHelper::pNetAdapterManager)
	{
		if (NR_CNetAdapterToolHelper::pNetAdapterManager->QueryAdapterList(NetAdapterList))
		{
			for (auto pNetAdapter : NetAdapterList)
			{
				if (pNetAdapter)
				{
					if (pNetAdapter->Connect())
					{
						++uSucceededConnectNetAdapterNum;
					}

					NR_SAFE_RELEASE(pNetAdapter);
				}
			}

			if (uSucceededConnectNetAdapterNum == NetAdapterList.size())
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool NR_IsConnectedNetAdapterExist(void)
{
	bool bRet = false;
	std::list<NR_INetAdapter *> NetAdapterList;

	if (NR_CNetAdapterToolHelper::pNetAdapterManager)
	{
		if (NR_CNetAdapterToolHelper::pNetAdapterManager->QueryAdapterList(NetAdapterList))
		{
			for (auto pNetAdapter : NetAdapterList)
			{
				if (pNetAdapter)
				{
					if (pNetAdapter->IsConnected())
					{
						bRet = true;
						NR_SAFE_RELEASE(pNetAdapter);
						break;
					}

					NR_SAFE_RELEASE(pNetAdapter);
				}
			}
		}
	}

	return bRet;
}
