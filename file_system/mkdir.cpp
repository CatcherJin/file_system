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
		cout<<"homeΪϵͳ�����֣���ʹ������������Ŀ¼��!\n";
		return;
	}
	for(direct_count_1=0;direct_count_1<8;direct_count_1++)//�ҵ�δʹ�õ�Ŀ¼
	{
		if(filesystem.direct_team[direct_count_1].direct_used_or_not==0)
			break;
	}
	if(direct_count_1>=8)
	{
		cout<<"ϵͳĿ¼�������޷�������Ŀ¼!\n";
		return;
	}

   
	for(direct_count=0;direct_count<8;direct_count++)//�ж���Ŀ¼�Ƿ�����
	{
		if((*current_direct).child_direct_use_state[direct_count]==0)
			break;
	}
	if(direct_count>=8)
	{
		cout<<"��Ŀ¼�������޷��ٽ���Ŀ¼!\n";
		return;
	}
	
    
	for(direct_count_=0;direct_count_<8;direct_count_++)//�жϸ�Ŀ¼���Ƿ����
	{
     if((*current_direct).child_direct_use_state[direct_count_]==1)
	 {
       if(strcmp((*(*current_direct).point_to_child_direct[direct_count_]).direct_name,filename)==0)
		 break;
	 }
	}
	if(direct_count_<8)
	{
		cout<<"Ҫ����Ŀ¼���Ѵ��ڣ�������������!\n";
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
		cout<<"Ҫ����Ŀ¼��"<<filename<<"�뵱ǰĿ¼�е��ļ�������������������!\n";
		return;
	}


	(*current_direct).point_to_child_direct[direct_count]=&filesystem.direct_team[direct_count_1];//direct_count_1��һ��δ������Ŀ¼��
	filesystem.direct_team[direct_count_1].direct_used_or_not=1;
	(*current_direct).child_direct_use_state[direct_count]=1;//��Ŀ¼ʹ��״̬��1
	strcpy(filesystem.direct_team[direct_count_1].direct_name,filename);
	filesystem.direct_team[direct_count_1].point_to_parent_direct=current_direct;
}