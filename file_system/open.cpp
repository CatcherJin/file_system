#include"iostream.h"
#include"head.h"
#include"stdlib.h"
#include"string.h"
int file_open_count;
int m_open;
int i_file;
int open(char filename[8])
{

    for(file_open_count=0;file_open_count<8;file_open_count++)//���Ҹ�Ŀ¼���Ƿ��и��ļ�
	{
		if((*current_direct).file_point_use_state[file_open_count]==1)
		{
		  if(strcmp((*(*current_direct).point_to_file[file_open_count]).file_name,filename)==0)break;
		}
	}
    if(file_open_count>=8)
	{
		cout<<"���ļ����ڴ�Ŀ¼�����ļ�������!\n";
		return 0;
	}
   
		
	if(strcmp((*(*current_direct).point_to_file[file_open_count]).file_owner,(*current_user).user_name)!=0)//�ж��Ƿ�Ϊ��ǰ�û�����
	{
		cout<<(*(*current_direct).point_to_file[file_open_count]).file_name<<"�������û�����������Ȩ��!\n";
		return 0;
	}

	close_();
	current_file=(*current_direct).point_to_file[file_open_count];//��ǰ�ļ�


	m_open=(*current_file).point_to_FAT;
    fd=fopen("d:\\filesystem","r");
	for(i_file=0;i_file<(*current_file).file_length;i_file++)//�ҵ��ļ����ڴ��ַ
	{
		
        fseek(fd,sizeof(struct file_system)+m_open*512,0);//ͷ��Ϣ��������Ϣ��ĵ�ַ
		fread(memory[i_file],1,512,fd);//����
		m_open=filesystem.FAT[m_open].file_in_FAT;
	}
	fclose(fd);
	return 1;
}

