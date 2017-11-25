
#pragma once

/**
** @file NieRLib.h
** @brief 通用接口工具库
** @author 李远兵
** @remark
**
** 该库旨在为每一种功能抽象出接口，并为部分接口提供一份默认实现，同时，部分功能提供一份高级接口
** 大部分情况下，通过高级接口就可以达到想要的效果，这些高级接口被包含在那些以 Tool 结尾的 .h 文件中
**
** 该库是跨平台的，初步计划支持 Win32 平台和 GCC 平台，但是由于我本人没有 GCC 平台开发经验
** 所以该特性暂时保留，该库为每一种功能提供一套工厂接口，用户请自行根据自己的平台来选择工厂接口来获取接口
** 这些工厂接口被包含在那些以 Factory 结尾的 .h 文件中，一般来讲，Win32 平台接口可以通过 MakeWin32 开头的工厂
** 接口来获取接口，那些以 ByOSPlatform 结尾的工厂接口则自动根据用户操作系统平台来选择接口，个人建议使用后者
** 会有更高的可移植性
**
** 该库的所有接口都是基于引用计数的，用完记得 Release，有些接口会返回接口，用完被返回的接口后要不要 Release
** 请自行查看文档
**
** 这个库是用来抛弃 HelperLib 用的，HelperLib 是我进这间公司后自己封装的第一个代码库，同时也是我踏入开发行业
** 后自己封装的第一个代码库，代码杂乱不堪，没有应用任何构架思维，耦合度非常高，不易于扩展与维护
** 当然，这不代表着 NieRLib 会非常深奥，相反，NieRLib 非常易懂，因为 NieRLib 的目标之一是容易扩展、容易维护
** 最重要的是容易使用，而且，作为一个工具库，就注定 NieRLib 不会出现什么庞大复杂的内部构造，因为工具库不是框架库
**
** NieRLibConfig.h 文件包含了一些编译器选项，这些选项会影响 NieRLib 的行为，请自行查看文档
**
** 由于我本人是 Win32 平台起步的，部分接口涉及字符串参数的方法中，如果需要区分 UNICODE 和多字节的话，这些方法
** 会分别以 A（多字节版本）和 W（UNICODE 版本）字母结尾，作用和 Win32 SDK API 中的字符串 API 一致，用于区分方法
** 所依赖的字符编码，需要注意，并非所有涉及字符串的方法都遵循这个规则
**
** 最后，仅以此库，赠给全世界 NieR:Automata 玩家，愿所有 NieR:Automata 玩家永垂不朽 :)
**
** @history ver0.1 2017-11-22
**
** 创建该项目
**
** @history ver0.2 2017-11-23
**
** 增加任务接口 ITask、工作流接口 IWorkflow、工作流设计器接口 IWorkflowDesigner，增加跨平台线程类 CThread
**
** @history ver0.3 2017-11-24
**
** 增加归档文件接口 IArchiver、归档文件解包接口 IArchiverUnpacker、归档文件元素枚举器接口 IArchiverItemEnumerator、
** 归档文件元素接口 IArchiverItem，增加工作进度接口 IWorkProgress
** 为归档文件接口提供一份 Win32 Zip 实现
**
*/

/**
** @addgroup 基础接口
*/
#include "Base/IRefCount.h"
#include "Base/IWorkProgress.h"

/**
** @addgroup 文件枚举器
*/
#include "FileEnumerator/IFileEnumerator.h"
#include "FileEnumerator/IFileEnumResult.h"
#include "FileEnumerator/FileEnumeratorFactory.h"
#include "FileEnumerator/FileEnumTool.h"

/**
** @addgroup 内存分配器
*/
#include "MemoryAllocator/IMemoryAllocator.h"
#include "MemoryAllocator/MemoryAllocatorFactory.h"

/**
** @addgroup 字符串转换器
*/
#include "StringConverter/IStringConverter.h"
#include "StringConverter/StringConverterFactory.h"
#include "StringConverter/StringConverterTool.h"

/**
** @addgroup 快捷方式
*/
#include "Shortcut/IShortcut.h"
#include "Shortcut/IShortcutManager.h"
#include "Shortcut/ShortcutManagerFactory.h"
#include "Shortcut/ShortcutTool.h"

/**
** @addgroup 进程
*/
#include "Process/IProcess.h"
#include "Process/IProcessManager.h"
#include "Process/ProcessManagerFactory.h"
#include "Process/ProcessTool.h"

/**
** @addgroup 线程
*/
#include "Thread/CThread.h"

/**
** @addgroup 互斥锁
*/
#include "Lock/ILock.h"
#include "Lock/LockFactory.h"

/**
** @addgroup 工作流
*/
#include "Workflow/ITask.h"
#include "Workflow/IWorkflow.h"
#include "Workflow/IWorkflowDesigner.h"

/**
** @addgroup 归档文件
*/
#include "Archiver/IArchiver.h"
#include "Archiver/IArchiverItem.h"
#include "Archiver/IArchiverItemEnumerator.h"
#include "Archiver/IArchiverUnpacker.h"
#include "Archiver/ArchiverFactory.h"
