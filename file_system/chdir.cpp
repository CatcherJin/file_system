#include"iostream.h"
#include"head.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
int select_direct;
void chdir(char filename[8])
{   
	if(strcmp(filename,"..")==0)//�����ϼ�Ŀ¼
	{
		if(strcmp((*current_direct).direct_name,"home")==0)
			return;
		
	    strcpy(visable_direct.direct_visable[ visable_direct.point],"        ");
		visable_direct.point--;
		current_direct=(*current_direct).point_to_parent_direct;
	
	    close_();
	}
	else
	{
	  for(select_direct=0;select_direct<8;select_direct++)//ת����Ŀ¼��
	  {
		if((*current_direct).child_direct_use_state[select_direct]==1)
		{
			if(strcmp((*(*current_direct).point_to_child_direct[select_direct]).direct_name,filename)==0)
			  break;
		}
	  }
	  if(select_direct>=8)
	  {
		  cout<<"Ŀ¼"<<filename<<"�����ڣ��޷�����!\n";
		  return;
	  }
	    close_();
	   current_direct=(*current_direct).point_to_child_direct[select_direct];
	   
	    visable_direct.point++;
	    strcpy(visable_direct.direct_visable[ visable_direct.point],(*current_direct).direct_name);//��ǰĿ¼���
	   
	}
	
   
}
