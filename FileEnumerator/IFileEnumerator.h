
#pragma once

#include "../Base/IRefCount.h"

class IFileEnumResult;

/**
** @brief �ļ�ö�����ӿ�
*/
class IFileEnumerator : public IRefCount
{
public:

	/**
	** @brief ö��ָ��Ŀ¼��ӵ��ָ����׺���������ļ�
	** @param pszDirectory Ҫ����ö�ٵ�Ŀ¼
	** @param pszFileExt Ҫ����ö�ٵ��ļ���׺��
	** @param bEnumSubDir �Ƿ�ö����Ŀ¼
	** @param ResultList ����ö�ٽ��
	** @return true ��ʾ�ɹ���false ��ʾʧ��
	*/
	virtual bool EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList) = 0;

	/**
	** @brief ö��ָ��Ŀ¼�µ������ļ�Ŀ¼
	** @param pszDirectory Ҫ����ö�ٵ�Ŀ¼
	** @param bEnumSubDir �Ƿ�ö����Ŀ¼
	** @param ResultList ����ö�ٽ��
	** @return true ��ʾ�ɹ���false ��ʾʧ��
	*/
	virtual bool EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList) = 0;
};
