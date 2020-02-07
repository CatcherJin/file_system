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
	if(mcount_file>=8)//判断是否存在文件
	{
		cout<<"当前目录中无文件"<<filename_<<endl;
		return;
	}


	if(strcmp((*current_file).file_name,filename_)!=0)//判断是否打开
	{
		cout<<filename_<<"未打开,打开后才能进行读写操作!\n";
		return;
	}
	
	while(true)
	{
	   file_fat=(*current_file).point_to_FAT;
	   if(filesystem.FAT[file_fat].file_in_FAT==-1)//指向该文件的文件内容磁盘区
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
				 memory[(*current_file).file_length-1][filesystem.FAT[file_fat].used_count]=2;//最后节点置2，作为标记
				 return;
			 }
			 
			
			 memory[(*current_file).file_length-1][filesystem.FAT[file_fat].used_count]=filename[count];//写入
			 filesystem.FAT[file_fat].used_count++;
		 }
	    else 
		{   
			if((*current_file).file_length>=10)
			{
				cout<<"文件已超过最大长度,无法写入!\n";
				return;
			}


			for(write_count=0;write_count<512;write_count++)
			   if(filesystem.FAT[write_count].file_in_FAT==0)
				  break;
			
			
			if(write_count>=512)
			{
				cout<<"磁盘已满!\n";
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

