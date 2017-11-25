
#pragma once

/**
** @file NieRLib.h
** @brief ͨ�ýӿڹ��߿�
*/

/**
** @addgroup �����ӿ�
*/
#include "Base/IRefCount.h"
#include "Base/IWorkProgress.h"
#include "Base/ITask.h"

/**
** @addgroup �ļ�ö����
*/
#include "FileEnumerator/IFileEnumerator.h"
#include "FileEnumerator/IFileEnumResult.h"
#include "FileEnumerator/FileEnumeratorFactory.h"
#include "FileEnumerator/FileEnumTool.h"

/**
** @addgroup �ļ�ϵͳ
*/
#include "FileSystem/IFile.h"
#include "FileSystem/IFileSystem.h"
#include "FileSystem/FileSystemFactory.h"
#include "FileSystem/FileSystemTool.h"

/**
** @addgroup �ڴ������
*/
#include "MemoryAllocator/IMemoryAllocator.h"
#include "MemoryAllocator/MemoryAllocatorFactory.h"

/**
** @addgroup �ַ���ת����
*/
#include "StringConverter/IStringConverter.h"
#include "StringConverter/StringConverterFactory.h"
#include "StringConverter/StringConverterTool.h"

/**
** @addgroup ��ݷ�ʽ
*/
#include "Shortcut/IShortcut.h"
#include "Shortcut/IShortcutManager.h"
#include "Shortcut/ShortcutManagerFactory.h"
#include "Shortcut/ShortcutTool.h"

/**
** @addgroup ����
*/
#include "Process/IProcess.h"
#include "Process/IProcessManager.h"
#include "Process/ProcessManagerFactory.h"
#include "Process/ProcessTool.h"

/**
** @addgroup �߳�
*/
#include "Thread/CThread.h"

/**
** @addgroup ����������
*/
#include "NetAdapter/INetAdapter.h"
#include "NetAdapter/INetAdapterManager.h"
#include "NetAdapter/NetAdapterManagerFactory.h"
#include "NetAdapter/NetAdapterTool.h"

/**
** @brief ��
*/
#include "Library/ILibrary.h"
#include "Library/ILibraryManager.h"
#include "Library/LibraryManagerFactory.h"
#include "Library/LibraryTool.h"

/**
** @addgroup ������
*/
#include "Lock/ILock.h"
#include "Lock/LockFactory.h"

/**
** @addgroup ������
*/
#include "Workflow/IWorkflow.h"
#include "Workflow/IWorkflowDesigner.h"

/**
** @addgroup �鵵�ļ�
*/
#include "Archiver/IArchiver.h"
#include "Archiver/IArchiverItem.h"
#include "Archiver/IArchiverItemEnumerator.h"
#include "Archiver/IArchiverUnpacker.h"
#include "Archiver/ArchiverFactory.h"
