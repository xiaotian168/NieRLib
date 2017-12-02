
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief �ж�ָ���ļ��Ƿ����
** @param pszFilePath Ҫ�жϵ��ļ�·��
** @return true ��ʾ���ڣ�false ��ʾ������
*/
NR_CAPI bool NR_IsFileExistW(const wchar_t * pszFilePath);

/**
** @brief ��ȡָ���ļ����������� 
** @param pszFilePath Ҫ��ȡ���ļ�·��
** @param ppFileData �����ȡ���ļ�����
** @param uFileSize �����ļ����ݴ�С����λ���ֽڣ�
** @return true �ɹ���false ��ʾʧ��
*/
NR_CAPI bool NR_ReadFileDataW(const wchar_t * pszFilePath, void ** ppFileData, unsigned int & uFileSize);

/**
** @brief �ͷ�ͨ�� ReadFileData ϵ�к���������ڴ�
** @param pFileData Ҫ�ͷŵ��ڴ�ָ��
** @return true �ɹ���false ��ʾʧ��
*/
NR_CAPI bool NR_FreeFileData(void * pFileData);

/**
** @brief ������д�뵽ָ���ļ�
** @param pszFilePath Ҫд����ļ�·��
** @param pData Ҫд�������
** @param uDataSize Ҫд������ݴ�С����λ���ֽڣ�
** @return true �ɹ���false ��ʾʧ��
*/
NR_CAPI bool NR_WriteFileDataW(const wchar_t * pszFilePath, const void * pData, const unsigned int uDataSize);
