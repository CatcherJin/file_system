#include"iostream.h"
#include"stdio.h"
#include"head.h"
#include"string.h"
char file_read;
int read_count1;
int mm_count;
int mm_count_;
int read_count;
void read(char filename[8])
{   
    for(mm_count_=0;mm_count_<8;mm_count_++)
		if((*current_direct).file_point_use_state[mm_count_]==1)
			if(strcmp((*(*current_direct).point_to_file[mm_count_]).file_name,filename)==0)
				break;
	if(mm_count_>=8)//�ж��ļ�������
	{
		cout<<"��ǰĿ¼�����ļ�"<<filename<<endl;
		return;
	}
    if(strcmp((*current_file).file_name,filename)!=0)//�ж��Ƿ��
	{
		cout<<filename<<"δ��,�򿪺���ܽ��ж�д����!\n";
		return;
	}
	mm_count=(*current_file).point_to_FAT;
   for(read_count=0;read_count<(*current_file).file_length;read_count++)
	{  
		if(memory[0][0]==2)
		{
			cout<<"�ļ�"<<filename<<"�ǿ��ļ�!\n";
			return;
		}
	   for(read_count1=0;read_count1<512;read_count1++)
	   {
         file_read=memory[read_count][read_count1];
          if(file_read!=2)
	        cout<<file_read;
	      else 
		  {
			  cout<<endl;
			  return;
		  }
	   }
       mm_count=filesystem.FAT[mm_count].file_in_FAT;
	
	}

}
   