#include"iostream.h"
#include"stdio.h"
#include"string.h"
#include"head.h"
#include"stdlib.h"
int data_length;
int count;
int write_count;
int seek_last;
int mcount_file;
void write(char filename_[8],char filename[16])
{  

	 for(mcount_file=0;mcount_file<8;mcount_file++)
		if((*current_direct).file_point_use_state[mcount_file]==1)
			if(strcmp((*(*current_direct).point_to_file[mcount_file]).file_name,filename_)==0)
				break;
	if(mcount_file>=8)//�ж��Ƿ�����ļ�
	{
		cout<<"��ǰĿ¼�����ļ�"<<filename_<<endl;
		return;
	}


	if(strcmp((*current_file).file_name,filename_)!=0)//�ж��Ƿ��
	{
		cout<<filename_<<"δ��,�򿪺���ܽ��ж�д����!\n";
		return;
	}
	
	while(true)
	{
	   file_fat=(*current_file).point_to_FAT;
	   if(filesystem.FAT[file_fat].file_in_FAT==-1)//ָ����ļ����ļ����ݴ�����
		break;
	    file_fat=filesystem.FAT[file_fat].file_in_FAT;
	}

	data_length=strlen(filename);

	for(count=0;count<data_length+1;count++)
	{    
		
		 
		

	     if(filesystem.FAT[file_fat].used_count<512)
		 {
			 if(count==data_length)
			 {
				 memory[(*current_file).file_length-1][filesystem.FAT[file_fat].used_count]=' ';
				  filesystem.FAT[file_fat].used_count++;
				 memory[(*current_file).file_length-1][filesystem.FAT[file_fat].used_count]=2;//���ڵ���2����Ϊ���
				 return;
			 }
			 
			
			 memory[(*current_file).file_length-1][filesystem.FAT[file_fat].used_count]=filename[count];//д��
			 filesystem.FAT[file_fat].used_count++;
		 }
	    else 
		{   
			if((*current_file).file_length>=10)
			{
				cout<<"�ļ��ѳ�����󳤶�,�޷�д��!\n";
				return;
			}


			for(write_count=0;write_count<512;write_count++)
			   if(filesystem.FAT[write_count].file_in_FAT==0)
				  break;
			
			
			if(write_count>=512)
			{
				cout<<"��������!\n";
				return;
			}
			else
			{
				filesystem.FAT[file_fat].file_in_FAT=write_count;
		        filesystem.FAT[write_count].file_in_FAT=-1;
				(*current_file).file_length++;
				
			}
        }
	}
}

