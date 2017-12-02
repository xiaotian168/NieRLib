
#pragma once

/**
** @brief 命名对象接口
*/
class NR_INameObject
{
public:

	/**
	** @brief 设置名称
	*/
	virtual bool SetNameW(const wchar_t * pszName) = 0;

	/**
	** @brief 获取名称
	*/
	virtual const wchar_t * GetNameW(void) const = 0;
};
