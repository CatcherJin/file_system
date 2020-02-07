#include"iostream.h"
#include"head.h"
#include"stdlib.h"
#include"string.h"
int file_open_count;
int m_open;
int i_file;
int open(char filename[8])
{

    for(file_open_count=0;file_open_count<8;file_open_count++)//查找该目录下是否有该文件
	{
		if((*current_direct).file_point_use_state[file_open_count]==1)
		{
		  if(strcmp((*(*current_direct).point_to_file[file_open_count]).file_name,filename)==0)break;
		}
	}
    if(file_open_count>=8)
	{
		cout<<"此文件不在此目录，或文件不存在!\n";
		return 0;
	}
   
		
	if(strcmp((*(*current_direct).point_to_file[file_open_count]).file_owner,(*current_user).user_name)!=0)//判断是否为当前用户创建
	{
		cout<<(*(*current_direct).point_to_file[file_open_count]).file_name<<"是其他用户所建，你无权打开!\n";
		return 0;
	}

	close_();
	current_file=(*current_direct).point_to_file[file_open_count];//当前文件


	m_open=(*current_file).point_to_FAT;
    fd=fopen("d:\\filesystem","r");
	for(i_file=0;i_file<(*current_file).file_length;i_file++)//找到文件的内存地址
	{
		
        fseek(fd,sizeof(struct file_system)+m_open*512,0);//头信息加内容信息后的地址
		fread(memory[i_file],1,512,fd);//读出
		m_open=filesystem.FAT[m_open].file_in_FAT;
	}
	fclose(fd);
	return 1;
}

