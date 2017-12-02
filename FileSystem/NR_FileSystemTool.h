
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief 判断指定文件是否存在
** @param pszFilePath 要判断的文件路径
** @return true 表示存在，false 表示不存在
*/
NR_CAPI bool NR_IsFileExistW(const wchar_t * pszFilePath);

/**
** @brief 读取指定文件的所有内容 
** @param pszFilePath 要读取的文件路径
** @param ppFileData 保存读取的文件内容
** @param uFileSize 保存文件内容大小（单位：字节）
** @return true 成功，false 表示失败
*/
NR_CAPI bool NR_ReadFileDataW(const wchar_t * pszFilePath, void ** ppFileData, unsigned int & uFileSize);

/**
** @brief 释放通过 ReadFileData 系列函数分配的内存
** @param pFileData 要释放的内存指针
** @return true 成功，false 表示失败
*/
NR_CAPI bool NR_FreeFileData(void * pFileData);

/**
** @brief 将数据写入到指定文件
** @param pszFilePath 要写入的文件路径
** @param pData 要写入的数据
** @param uDataSize 要写入的数据大小（单位：字节）
** @return true 成功，false 表示失败
*/
NR_CAPI bool NR_WriteFileDataW(const wchar_t * pszFilePath, const void * pData, const unsigned int uDataSize);
