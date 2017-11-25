
#pragma once

/**
** @file NieRLib.h
** @brief ͨ�ýӿڹ��߿�
** @author ��Զ��
** @remark
**
** �ÿ�ּ��Ϊÿһ�ֹ��ܳ�����ӿڣ���Ϊ���ֽӿ��ṩһ��Ĭ��ʵ�֣�ͬʱ�����ֹ����ṩһ�ݸ߼��ӿ�
** �󲿷�����£�ͨ���߼��ӿھͿ��Դﵽ��Ҫ��Ч������Щ�߼��ӿڱ���������Щ�� Tool ��β�� .h �ļ���
**
** �ÿ��ǿ�ƽ̨�ģ������ƻ�֧�� Win32 ƽ̨�� GCC ƽ̨�����������ұ���û�� GCC ƽ̨��������
** ���Ը�������ʱ�������ÿ�Ϊÿһ�ֹ����ṩһ�׹����ӿڣ��û������и����Լ���ƽ̨��ѡ�񹤳��ӿ�����ȡ�ӿ�
** ��Щ�����ӿڱ���������Щ�� Factory ��β�� .h �ļ��У�һ��������Win32 ƽ̨�ӿڿ���ͨ�� MakeWin32 ��ͷ�Ĺ���
** �ӿ�����ȡ�ӿڣ���Щ�� ByOSPlatform ��β�Ĺ����ӿ����Զ������û�����ϵͳƽ̨��ѡ��ӿڣ����˽���ʹ�ú���
** ���и��ߵĿ���ֲ��
**
** �ÿ�����нӿڶ��ǻ������ü����ģ�����ǵ� Release����Щ�ӿڻ᷵�ؽӿڣ����걻���صĽӿں�Ҫ��Ҫ Release
** �����в鿴�ĵ�
**
** ��������������� HelperLib �õģ�HelperLib ���ҽ���乫˾���Լ���װ�ĵ�һ������⣬ͬʱҲ����̤�뿪����ҵ
** ���Լ���װ�ĵ�һ������⣬�������Ҳ�����û��Ӧ���κι���˼ά����϶ȷǳ��ߣ���������չ��ά��
** ��Ȼ���ⲻ������ NieRLib ��ǳ���£��෴��NieRLib �ǳ��׶�����Ϊ NieRLib ��Ŀ��֮һ��������չ������ά��
** ����Ҫ��������ʹ�ã����ң���Ϊһ�����߿⣬��ע�� NieRLib �������ʲô�Ӵ��ӵ��ڲ����죬��Ϊ���߿ⲻ�ǿ�ܿ�
**
** NieRLibConfig.h �ļ�������һЩ������ѡ���Щѡ���Ӱ�� NieRLib ����Ϊ�������в鿴�ĵ�
**
** �����ұ����� Win32 ƽ̨�𲽵ģ����ֽӿ��漰�ַ��������ķ����У������Ҫ���� UNICODE �Ͷ��ֽڵĻ�����Щ����
** ��ֱ��� A�����ֽڰ汾���� W��UNICODE �汾����ĸ��β�����ú� Win32 SDK API �е��ַ��� API һ�£��������ַ���
** ���������ַ����룬��Ҫע�⣬���������漰�ַ����ķ�������ѭ�������
**
** ��󣬽��Դ˿⣬����ȫ���� NieR:Automata ��ң�Ը���� NieR:Automata ����������� :)
**
** @history ver0.1 2017-11-22
**
** ��������Ŀ
**
** @history ver0.2 2017-11-23
**
** ��������ӿ� ITask���������ӿ� IWorkflow��������������ӿ� IWorkflowDesigner�����ӿ�ƽ̨�߳��� CThread
**
** @history ver0.3 2017-11-24
**
** ���ӹ鵵�ļ��ӿ� IArchiver���鵵�ļ�����ӿ� IArchiverUnpacker���鵵�ļ�Ԫ��ö�����ӿ� IArchiverItemEnumerator��
** �鵵�ļ�Ԫ�ؽӿ� IArchiverItem�����ӹ������Ƚӿ� IWorkProgress
** Ϊ�鵵�ļ��ӿ��ṩһ�� Win32 Zip ʵ��
**
*/

/**
** @addgroup �����ӿ�
*/
#include "Base/IRefCount.h"
#include "Base/IWorkProgress.h"

/**
** @addgroup �ļ�ö����
*/
#include "FileEnumerator/IFileEnumerator.h"
#include "FileEnumerator/IFileEnumResult.h"
#include "FileEnumerator/FileEnumeratorFactory.h"
#include "FileEnumerator/FileEnumTool.h"

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
** @addgroup ������
*/
#include "Lock/ILock.h"
#include "Lock/LockFactory.h"

/**
** @addgroup ������
*/
#include "Workflow/ITask.h"
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
