#include"iostream.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"head.h"
int seek_file,seek_direct;
struct direct * current_direct;
struct file * current_file;
int fat_length; 
int check_file;
 
void create_(char filename[8])
{ 
   	
  if(strcmp(filename,"empty")==0)
  {
	  cout<<"empty为系统保留字，请使用其他名称作文件名!\n";
	  return;
  }
  for(check_file=0;check_file<8;check_file++)//判断文件名是否已经存在
	  if((*current_direct).file_point_use_state[check_file]==1)
	  {
	     if(strcmp((*(*current_direct).point_to_file[check_file]).file_name,filename)==0)
		 {
		  cout<<"文件名"<<filename<<"已存在于目录"<<(*current_direct).direct_name<<"中,请输入其他名称!\n";
		  return;
		 }
	  }
  



	 for(check_file=0;check_file<8;check_file++)
	  if((*current_direct).child_direct_use_state[check_file]==1)
	  {
	     if(strcmp((*(*current_direct).point_to_child_direct[check_file]).direct_name,filename)==0)
		 {
		  cout<<"名称"<<filename<<"已存在于目录"<<(*current_direct).direct_name<<"中,请输入其他名称!\n";
		  return;
		 }
	  }


  for(seek_file=0;seek_file<64;seek_file++)//查找一个空的文件区
    if(filesystem.file_team[seek_file].file_used_or_not==0)break;
  if(seek_file>=64)
  {
	  cout<<"系统已满,无法再建文件!\n";
	  return;
  }


 

  for(seek_direct=0;seek_direct<8;seek_direct++)//找到该目录下第一个未使用的文件序号
	  if((*current_direct).file_point_use_state[seek_direct]==0)break;
  if(seek_direct>=8)
  {
	  cout<<"目录"<<(*current_direct).direct_name<<"已满,请在其他目录建文件!\n";
	  return;
  }

  
  for(fat_length=0;fat_length<512;fat_length++)//查找第一个未使用的文件内容区（磁盘）
  {
	if(filesystem.FAT[fat_length].file_in_FAT==0)
	  break;
  }
  if(fat_length>=512)
  {
	  cout<<"磁盘已满,无法再建文件!\n";
	  return;
  }
   strcpy(filesystem.file_team[seek_file].file_owner,(*current_user).user_name);//文件区赋予用户信息
   close_();
   current_file=&(filesystem.file_team[seek_file]);//指向文件区
   (*current_file).point_to_FAT=fat_length;//指向一个磁盘空间
   filesystem.FAT[fat_length].file_in_FAT=-1;
   
   (*current_direct).point_to_file[seek_direct]=&(filesystem.file_team[seek_file]);//该目录下指向该文件的序号指向文件区序号
   (*current_direct).file_point_use_state[seek_direct]=1; //该目录下该文件的使用状态置1
   filesystem.file_team[seek_file].file_used_or_not=1;//文件区使用状态置1
   strcpy(filesystem.file_team[seek_file].file_name,filename);//文件名赋值
   
  memory[0][0]=2;

   filesystem.file_team[seek_file].file_length=1;
   

  
}
  
 