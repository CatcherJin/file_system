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
	if(mm_count_>=8)//判断文件不存在
	{
		cout<<"当前目录中无文件"<<filename<<endl;
		return;
	}
    if(strcmp((*current_file).file_name,filename)!=0)//判断是否打开
	{
		cout<<filename<<"未打开,打开后才能进行读写操作!\n";
		return;
	}
	mm_count=(*current_file).point_to_FAT;
   for(read_count=0;read_count<(*current_file).file_length;read_count++)
	{  
		if(memory[0][0]==2)
		{
			cout<<"文件"<<filename<<"是空文件!\n";
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
   