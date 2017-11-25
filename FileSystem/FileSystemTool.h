
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief �ж�ָ���ļ��Ƿ����
** @param pszFilePath Ҫ�жϵ��ļ�·��
** @return true ��ʾ���ڣ�false ��ʾ������
*/
NIER_CAPI bool IsFileExistW(const wchar_t * pszFilePath);

/**
** @brief ��ȡָ���ļ����������� 
** @param pszFilePath Ҫ��ȡ���ļ�·��
** @param ppFileData �����ȡ���ļ�����
** @param uFileSize �����ļ����ݴ�С����λ���ֽڣ�
** @return true �ɹ���false ��ʾʧ��
*/
NIER_CAPI bool ReadFileDataW(const wchar_t * pszFilePath, void ** ppFileData, unsigned int & uFileSize);

/**
** @brief �ͷ�ͨ�� ReadFileData ϵ�к���������ڴ�
** @param pFileData Ҫ�ͷŵ��ڴ�ָ��
** @return true �ɹ���false ��ʾʧ��
*/
NIER_CAPI bool FreeFileData(void * pFileData);
