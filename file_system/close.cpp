#include"head.h"
#include"stdio.h"
struct file empty;
int file_close;
int file_close_count;
void close_()
{    
	fd=fopen("d:\\filesystem","r+");//���ļ�
	file_close_count=(*current_file).point_to_FAT;//ָ��ǰ���
    for(file_close=0;file_close<(*current_file).file_length;file_close++)
	{ 
		fseek(fd,sizeof(struct file_system)+512*file_close_count,0);//�����ļ���дָ��
		fwrite(memory[file_close],1,512,fd);//�ڴ���д�����
        file_close_count=filesystem.FAT[file_close_count].file_in_FAT;//ָ����һ���
	}
	fclose(fd);//�ر��ļ�
    
    current_file=&empty;//��ǰ�ļ�ָ��ָ��ϵͳ�����ļ��Ľڵ㣬��ָ��ոմ򿪵��ļ�
	                    //��ɲ��򿪲��ܶ��Ĺ���
   
}
