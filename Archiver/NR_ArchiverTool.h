
#pragma once

#include "../NieRLibConfig.h"

class NR_IArchiver;

/**
** @brief ���ָ���鵵�ļ��е����� Item
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
NR_API bool NR_UnpackAllArchiverItemW(NR_IArchiver * pArchiver, std::list<std::wstring> & ItemPathList);

/**
** @brief �Զ����ݵ���������ƽ̨��ʹ�ö�Ӧ�� zip �鵵�ӿڽ�ָ���� zip �鵵�ļ������ָ��Ŀ¼
** @param pszArchiverPath zip �鵵�ļ�·��
** @param pszPassword �鵵�ļ�����
** @param pszUnpackDirectory ���Ŀ��Ŀ¼·��
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
NR_API bool NR_UnpackZipArchiverW(const wchar_t * pszArchiverPath, const char * pszPassword, const wchar_t * pszUnpackDirectory);
