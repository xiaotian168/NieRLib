
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief �ļ��ӿ�
*/
class NR_IFile : public NR_IRefCount
{
public:

	/**
	** @brief �ر��ļ�
	*/
	virtual bool Close(void) = 0;

	/**
	** @brief �ƶ��ļ�ָ�뵽ָ��λ��
	*/
	virtual bool SeekTo(const long nPos) = 0;

	/**
	** @brief �ƶ��ļ�ָ�뵽�ļ�ͷ��
	*/
	virtual bool SeekToBegin(void) = 0;

	/**
	** @brief �ƶ��ļ�ָ�뵽�ļ�β��
	*/
	virtual bool SeekToEnd(void) = 0;

	/**
	** @brief ƫ���ļ�ָ��ָ������
	*/
	virtual bool SeekOffset(const long nOffset) = 0;

	/**
	** @brief ��ȡ��ǰ�ļ�ָ��λ��
	*/
	virtual long Tell(void) = 0;

	/**
	** @brief ���ļ���ȡ����
	*/
	virtual bool Read(void * pBuffer, const unsigned int uBytes) = 0;

	/**
	** @brief ������д�뵽�ļ�
	*/
	virtual bool Write(const void * pBuffer, const unsigned int uBytes) = 0;
};
