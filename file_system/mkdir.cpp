#include"iostream.h"
#include"stdio.h"
#include"stdlib.h"
#include"head.h"
#include"string.h"
int child_direct_count;
int direct_count;
int direct_count_;
int direct_count_1;
void mkdir(char filename[8])
{   

    if(strcmp(filename,"home")==0)
	{
		cout<<"home为系统保留字，请使用其他名称作目录名!\n";
		return;
	}
	for(direct_count_1=0;direct_count_1<8;direct_count_1++)//找到未使用的目录
	{
		if(filesystem.direct_team[direct_count_1].direct_used_or_not==0)
			break;
	}
	if(direct_count_1>=8)
	{
		cout<<"系统目录已满，无法建立新目录!\n";
		return;
	}

   
	for(direct_count=0;direct_count<8;direct_count++)//判断子目录是否满了
	{
		if((*current_direct).child_direct_use_state[direct_count]==0)
			break;
	}
	if(direct_count>=8)
	{
		cout<<"此目录已满，无法再建子目录!\n";
		return;
	}
	
    
	for(direct_count_=0;direct_count_<8;direct_count_++)//判断该目录名是否存在
	{
     if((*current_direct).child_direct_use_state[direct_count_]==1)
	 {
       if(strcmp((*(*current_direct).point_to_child_direct[direct_count_]).direct_name,filename)==0)
		 break;
	 }
	}
	if(direct_count_<8)
	{
		cout<<"要建的目录名已存在，请用其他名称!\n";
		return;
	}



	for(direct_count_=0;direct_count_<8;direct_count_++)
	{
     if((*current_direct).file_point_use_state[direct_count_]==1)
	 {
       if(strcmp((*(*current_direct).point_to_file[direct_count_]).file_name,filename)==0)
		 break;
	 }
	}
	if(direct_count_<8)
	{
		cout<<"要建的目录名"<<filename<<"与当前目录中的文件重名，请用其他名称!\n";
		return;
	}


	(*current_direct).point_to_child_direct[direct_count]=&filesystem.direct_team[direct_count_1];//direct_count_1第一个未创建的目录处
	filesystem.direct_team[direct_count_1].direct_used_or_not=1;
	(*current_direct).child_direct_use_state[direct_count]=1;//子目录使用状态置1
	strcpy(filesystem.direct_team[direct_count_1].direct_name,filename);
	filesystem.direct_team[direct_count_1].point_to_parent_direct=current_direct;
}