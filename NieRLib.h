
#pragma once

/**
** @file NieRLib.h
** @brief 通用接口工具库
*/

/**
** @addgroup 基础接口
*/
#include "Base/IRefCount.h"
#include "Base/IWorkProgress.h"
#include "Base/ITask.h"

/**
** @addgroup 文件枚举器
*/
#include "FileEnumerator/IFileEnumerator.h"
#include "FileEnumerator/IFileEnumResult.h"
#include "FileEnumerator/FileEnumeratorFactory.h"
#include "FileEnumerator/FileEnumTool.h"

/**
** @addgroup 文件系统
*/
#include "FileSystem/IFile.h"
#include "FileSystem/IFileSystem.h"
#include "FileSystem/FileSystemFactory.h"
#include "FileSystem/FileSystemTool.h"

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
