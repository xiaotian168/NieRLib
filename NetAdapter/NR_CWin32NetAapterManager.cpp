
#include "NR_CWin32NetAapterManager.h"
#include "NR_CWin32NetAdapter.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32NetAapterManager * NR_CWin32NetAapterManager::Make(void)
{
	return new NR_CWin32NetAapterManager();
}

NR_CWin32NetAapterManager::NR_CWin32NetAapterManager()
{
	m_pConnectionManager = 0;

	Startup();
}

NR_CWin32NetAapterManager::~NR_CWin32NetAapterManager()
{
	Shutdown();
}

bool NR_CWin32NetAapterManager::QueryAdapterList(std::list<NR_INetAdapter *> & AdapterList)
{
	bool bRet = false;
	IEnumNetConnection * pEnumNetConnection = 0;
	INetConnection * pNetConnection = 0;
	ULONG ulCeltFetched = 0;
	unsigned int uEnumedNetAdapterNum = 0;
	unsigned int uSucceededMakeNetAdapterNum = 0;

	if (m_pConnectionManager)
	{
		if (SUCCEEDED(m_pConnectionManager->EnumConnections(NCME_DEFAULT, &pEnumNetConnection)))
		{
			ulCeltFetched = 0;

			while (S_OK == pEnumNetConnection->Next(1, &pNetConnection, &ulCeltFetched))
			{
				auto pNetAdapter = NR_CWin32NetAdapter::Make(pNetConnection);
				if (pNetAdapter)
				{
					AdapterList.push_back(pNetAdapter);

					++uSucceededMakeNetAdapterNum;
				}

				++uEnumedNetAdapterNum;
			}

			if (uEnumedNetAdapterNum == uSucceededMakeNetAdapterNum)
			{
				bRet = true;
			}

			SAFE_RELEASE(pEnumNetConnection);
		}
	}

	return bRet;
}

bool NR_CWin32NetAapterManager::Startup(void)
{
	bool bRet = false;

	if (!m_pConnectionManager)
	{
		if (SUCCEEDED(CoInitialize(0)))
		{
			if (SUCCEEDED(CoCreateInstance(CLSID_ConnectionManager, 0, CLSCTX_SERVER, IID_INetConnectionManager, (void **)&m_pConnectionManager)))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

void NR_CWin32NetAapterManager::Shutdown(void)
{
	SAFE_RELEASE(m_pConnectionManager);

	CoUninitialize();
}

#endif
