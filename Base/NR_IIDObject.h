
#pragma once

/**
** @brief ID 对象接口
*/
class NR_IIDObject
{
public:

	typedef unsigned long long IDType;

public:

	/**
	** @brief 设置 ID
	*/
	virtual bool SetID(const IDType & ID) = 0;

	/**
	** @brief 获取 ID
	*/
	virtual IDType GetID(void) const = 0;
};
