
#pragma once

#include "../NieRLibConfig.h"
#include <list>

#if defined UNICODE || defined _UNICODE
#	define EnumAllFile EnumAllFileW
#	define EnumAllDirectory EnumAllDirectoryW
#else
#	define EnumAllFile EnumAllFileA
#	define EnumAllDirectory EnumAllDirectoryA
#endif

class IFileEnumResult;

/**
** @brief ö��ָ��Ŀ¼��ӵ��ָ����׺���������ļ�
** @param pszDirectory Ҫ����ö�ٵ�Ŀ¼
** @param pszFileExt Ҫ����ö�ٵ��ļ���׺��
** @param bEnumSubDir �Ƿ�ö����Ŀ¼
** @param ResultList ����ö�ٽ��
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
NIER_CAPI bool EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList);
NIER_CAPI bool EnumAllFileA(const char * pszDirectory, const char * pszFileExt, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList);

/**
** @brief ö��ָ��Ŀ¼�µ������ļ�Ŀ¼
** @param pszDirectory Ҫ����ö�ٵ�Ŀ¼
** @param bEnumSubDir �Ƿ�ö����Ŀ¼
** @param ResultList ����ö�ٽ��
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
NIER_CAPI bool EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList);
NIER_CAPI bool EnumAllDirectoryA(const char * pszDirectory, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList);
