#pragma once

#include <vector>
#include <string>

typedef std::vector<std::string> PaVfiles;

#define PAFileBlockPart			(12 * 1024 * 1024)

enum PaFindFileType
{
	PaFindFileType_File,
	PaFindFileType_Directory
};

/*
    function:     paFileExists
	              �ļ��Ƿ����

        file:     �ļ�·��
      return:     ���ڷ���true�������ڷ���false
*/
bool paFileExists(const char* file);

/*
    function:     paGetFileSize
	              ��ȡ�ļ��ߴ�

        file:     �ļ�·��
      return:     �����ļ��ߴ�
*/
int paGetFileSize(const char* file);


/*
    function:     paFindFiles
	              Ѱ���ļ�

        path:     �ļ�·����·������������\������/,����û��
         out:     �ҵ����ļ�ȫ·�����������ִ�����������ʱ������out�е�����
      filter:     ����������������jpg������*.jpg
inc_sub_dirs:     �Ƿ������Ŀ¼��ָʾ�Ƿ���Ҫ������Ŀ¼�µ������ļ���
   clear_out:     ִ��ǰ�Ƿ������out�����е����ݣ��������Ҫ��Ѱ�ҵõ��Ķ������������뵽out
      return:     �����ҵ����ļ�����
*/
int paFindFiles(const std::string& path, PaVfiles& out, const char* filter = "*", bool inc_sub_dirs = true, bool clear_out = true, 
	PaFindFileType type = PaFindFileType_File, unsigned int nFilePerDir = 0);


/*
    function:     paFindFiles
	              Ѱ���ļ�

        path:     �ļ�·����·������������\������/,����û��
         out:     �ҵ����ļ�ȫ·�����������ִ�����������ʱ������out�е�����
      filter:     ����������������jpg������*.jpg
inc_sub_dirs:     �Ƿ������Ŀ¼��ָʾ�Ƿ���Ҫ������Ŀ¼�µ������ļ���
   clear_out:     ִ��ǰ�Ƿ������out�����е����ݣ��������Ҫ��Ѱ�ҵõ��Ķ������������뵽out
      return:     �����ҵ����ļ�����
*/
int paFindFilesShort(const std::string& path, PaVfiles& out, const char* filter = "*", bool inc_sub_dirs = true, bool clear_out = true,
	PaFindFileType type = PaFindFileType_File, unsigned int nFilePerDir = 0);


/*
function:     paFileName
��ȡ·�����ļ�������׺���ļ���+��׺������3������Ϊ0��ʾ��ȡ��

full_path:     �ļ���ȫ·���������ǣ���c:/123.abc.txt��
name_suffix:     �ļ����ͺ�׺������ᱣ�浽������ȥ��ֻ����Ҫ�ṩ�㹻��Ļ���������, ���ｫ���룺��123.abc.txt��
name_buffer:     �ļ��������������ｫ���룺��123.abc��
suffix_buffer:    ��׺�����������ｫ���룺��txt��
dir_buffer:     �ļ�Ŀ¼�����������ｫ���룺��c:��
*/
void paFileName(const char* full_path, char* name_suffix = 0, char* name_buffer = 0, char* suffix_buffer = 0, char* dir_buffer = 0);
