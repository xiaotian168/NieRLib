
#pragma once

/**
** @file NieRLib.h
** @brief 通用接口工具库
*/

/**
** @addgroup 基础接口
*/
#include "Base/NR_IRefCount.h"
#include "Base/NR_IWorkProgress.h"
#include "Base/NR_ITask.h"
#include "Base/NR_IIDObject.h"
#include "Base/NR_INameObject.h"

/**
** @addgroup 文件枚举器
*/
#include "FileEnumerator/NR_IFileEnumerator.h"
#include "FileEnumerator/NR_IFileEnumResult.h"
#include "FileEnumerator/NR_FileEnumeratorFactory.h"
#include "FileEnumerator/NR_FileEnumTool.h"

/**
** @addgroup 文件路径
*/
#include "FilePath/NR_IFilePath.h"
#include "FilePath/NR_FilePathFactory.h"
#include "FilePath/NR_FilePathTool.h"

/**
** @addgroup 文件系统
*/
#include "FileSystem/NR_IFile.h"
#include "FileSystem/NR_IFileSystem.h"
#include "FileSystem/NR_FileSystemFactory.h"
#include "FileSystem/NR_FileSystemTool.h"

/**
** @addgroup 内存分配器
*/
#include "MemoryAllocator/NR_IMemoryAllocator.h"
#include "MemoryAllocator/NR_MemoryAllocatorFactory.h"

/**
** @addgroup 字符串转换器
*/
#include "StringConverter/NR_IStringConverter.h"
#include "StringConverter/NR_StringConverterFactory.h"
#include "StringConverter/NR_StringConverterTool.h"

/**
** @addgroup 快捷方式
*/
#include "Shortcut/NR_IShortcut.h"
#include "Shortcut/NR_IShortcutManager.h"
#include "Shortcut/NR_ShortcutManagerFactory.h"
#include "Shortcut/NR_ShortcutTool.h"

/**
** @addgroup 进程
*/
#include "Process/NR_IProcess.h"
#include "Process/NR_IProcessManager.h"
#include "Process/NR_ProcessManagerFactory.h"
#include "Process/NR_ProcessTool.h"

/**
** @addgroup 线程
*/
#include "Thread/NR_CThread.h"
#include "Thread/NR_IThread.h"
#include "Thread/NR_IThreadManager.h"
#include "Thread/NR_ThreadManagerFactory.h"
#include "Thread/NR_ThreadTool.h"

/**
** @addgroup 网络适配器
*/
#include "NetAdapter/NR_INetAdapter.h"
#include "NetAdapter/NR_INetAdapterManager.h"
#include "NetAdapter/NR_NetAdapterManagerFactory.h"
#include "NetAdapter/NR_NetAdapterTool.h"

/**
** @brief 应用程序接口
*/
#include "Application/NR_IApplication.h"
#include "Application/NR_IApplicationStartupParam.h"
#include "Application/NR_ApplicationFactory.h"
#include "Application/NR_ApplicationStartupParamFactory.h"

/**
** @brief 窗口接口
*/
#include "Window/NR_IWindow.h"

/**
** @addgroup 日志
*/
#include "Log/NR_ILog.h"
#include "Log/NR_LogFactory.h"

/**
** @brief 库
*/
#include "Library/NR_ILibrary.h"
#include "Library/NR_ILibraryManager.h"
#include "Library/NR_LibraryManagerFactory.h"
#include "Library/NR_LibraryTool.h"

/**
** @addgroup 互斥锁
*/
#include "Lock/NR_ILock.h"
#include "Lock/NR_LockFactory.h"

/**
** @addgroup 工作流
*/
#include "Workflow/NR_IWorkflow.h"
#include "Workflow/NR_IWorkflowDesigner.h"
#include "Workflow/NR_WorkflowFactory.h"

/**
** @addgroup 归档文件
*/
#include "Archiver/NR_IArchiver.h"
#include "Archiver/NR_IArchiverItem.h"
#include "Archiver/NR_IArchiverItemEnumerator.h"
#include "Archiver/NR_IArchiverUnpacker.h"
#include "Archiver/NR_ArchiverFactory.h"
#include "Archiver/NR_ArchiverTool.h"

/**
** @addgroup 图像
*/
#include "Image/NR_IImage.h"
#include "Image/NR_IMultiFrameImage2D.h"

/**
** @addgroup 字体
*/
#include "Font/NR_IFont.h"

/**
** @addgroup 渲染设备
*/
#include "RenderDevice/NR_ARGB.h"
#include "RenderDevice/NR_IRenderDevice.h"
#include "RenderDevice/NR_IMultiFrameImageRenderDevice.h"
#include "RenderDevice/NR_RenderDeviceFactory.h"
 