
#pragma once

#include "NR_IRefCount.h"

/**
** @brief 进度接口
*/
class NIER_API NR_IWorkProgress : public NR_IRefCount
{
public:

	typedef unsigned int ProgressType;

public:

	/**
	** @brief 设置最大进度
	*/
	virtual bool SetMaxProgress(const ProgressType & MaxProgress) = 0;

	/**
	** @brief 设置进度
	*/
	virtual bool SetProgress(const ProgressType & Progress) = 0;

	/**
	** @brief 获取进度
	*/
	virtual ProgressType GetProgress(void) const = 0;

	/**
	** @brief 进度通知接口
	*/
	virtual void OnProgress(void) = 0;
};
