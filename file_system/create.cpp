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
	  cout<<"emptyΪϵͳ�����֣���ʹ�������������ļ���!\n";
	  return;
  }
  for(check_file=0;check_file<8;check_file++)//�ж��ļ����Ƿ��Ѿ�����
	  if((*current_direct).file_point_use_state[check_file]==1)
	  {
	     if(strcmp((*(*current_direct).point_to_file[check_file]).file_name,filename)==0)
		 {
		  cout<<"�ļ���"<<filename<<"�Ѵ�����Ŀ¼"<<(*current_direct).direct_name<<"��,��������������!\n";
		  return;
		 }
	  }
  



	 for(check_file=0;check_file<8;check_file++)
	  if((*current_direct).child_direct_use_state[check_file]==1)
	  {
	     if(strcmp((*(*current_direct).point_to_child_direct[check_file]).direct_name,filename)==0)
		 {
		  cout<<"����"<<filename<<"�Ѵ�����Ŀ¼"<<(*current_direct).direct_name<<"��,��������������!\n";
		  return;
		 }
	  }


  for(seek_file=0;seek_file<64;seek_file++)//����һ���յ��ļ���
    if(filesystem.file_team[seek_file].file_used_or_not==0)break;
  if(seek_file>=64)
  {
	  cout<<"ϵͳ����,�޷��ٽ��ļ�!\n";
	  return;
  }


 

  for(seek_direct=0;seek_direct<8;seek_direct++)//�ҵ���Ŀ¼�µ�һ��δʹ�õ��ļ����
	  if((*current_direct).file_point_use_state[seek_direct]==0)break;
  if(seek_direct>=8)
  {
	  cout<<"Ŀ¼"<<(*current_direct).direct_name<<"����,��������Ŀ¼���ļ�!\n";
	  return;
  }

  
  for(fat_length=0;fat_length<512;fat_length++)//���ҵ�һ��δʹ�õ��ļ������������̣�
  {
	if(filesystem.FAT[fat_length].file_in_FAT==0)
	  break;
  }
  if(fat_length>=512)
  {
	  cout<<"��������,�޷��ٽ��ļ�!\n";
	  return;
  }
   strcpy(filesystem.file_team[seek_file].file_owner,(*current_user).user_name);//�ļ��������û���Ϣ
   close_();
   current_file=&(filesystem.file_team[seek_file]);//ָ���ļ���
   (*current_file).point_to_FAT=fat_length;//ָ��һ�����̿ռ�
   filesystem.FAT[fat_length].file_in_FAT=-1;
   
   (*current_direct).point_to_file[seek_direct]=&(filesystem.file_team[seek_file]);//��Ŀ¼��ָ����ļ������ָ���ļ������
   (*current_direct).file_point_use_state[seek_direct]=1; //��Ŀ¼�¸��ļ���ʹ��״̬��1
   filesystem.file_team[seek_file].file_used_or_not=1;//�ļ���ʹ��״̬��1
   strcpy(filesystem.file_team[seek_file].file_name,filename);//�ļ�����ֵ
   
  memory[0][0]=2;

   filesystem.file_team[seek_file].file_length=1;
   

  
}
  
 