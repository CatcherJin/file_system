#include"iostream.h"
#include"head.h"
#include"string.h"
int file_delete;
int file_fat;
int mux;
void delete_(char filename[8])
{
	for(file_delete=0;file_delete<8;file_delete++)
	{
		if((*current_direct).file_point_use_state[file_delete]==1)
		{
		if(strcmp((*(*current_direct).point_to_file[file_delete]).file_name,filename)==0)break;
		}
	}//找文件
    if(file_delete>=8)
	{
		cout<<"文件"<<filename<<"不在此目录，或文件不存在,或者已删除!\n";
		return;
	}
    file_fat=(*(*current_direct).point_to_file[file_delete]).point_to_FAT;//指向当前块号
    (*current_direct).file_point_use_state[file_delete]=0;//目录使用标志,指针设为0
	(*(*current_direct).point_to_file[file_delete]).file_used_or_not=0;//文件使用标志设为0
	(*(*current_direct).point_to_file[file_delete]).file_length=0;//块数设置为0
	while(true)
	{
	      mux=filesystem.FAT[file_fat].file_in_FAT;//下一个块号
		  filesystem.FAT[file_fat].file_in_FAT=0;//块号使用情况设置为0
		  filesystem.FAT[file_fat].used_count=0;//块号内容设置为0
		  if(mux!=-1)//文件最后一个快
			file_fat=mux; 
		  
		  else
			  break;
		  
	}
	cout<<"删除成功!\n";
}	 
             