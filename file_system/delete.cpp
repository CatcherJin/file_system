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
	}//���ļ�
    if(file_delete>=8)
	{
		cout<<"�ļ�"<<filename<<"���ڴ�Ŀ¼�����ļ�������,������ɾ��!\n";
		return;
	}
    file_fat=(*(*current_direct).point_to_file[file_delete]).point_to_FAT;//ָ��ǰ���
    (*current_direct).file_point_use_state[file_delete]=0;//Ŀ¼ʹ�ñ�־,ָ����Ϊ0
	(*(*current_direct).point_to_file[file_delete]).file_used_or_not=0;//�ļ�ʹ�ñ�־��Ϊ0
	(*(*current_direct).point_to_file[file_delete]).file_length=0;//��������Ϊ0
	while(true)
	{
	      mux=filesystem.FAT[file_fat].file_in_FAT;//��һ�����
		  filesystem.FAT[file_fat].file_in_FAT=0;//���ʹ���������Ϊ0
		  filesystem.FAT[file_fat].used_count=0;//�����������Ϊ0
		  if(mux!=-1)//�ļ����һ����
			file_fat=mux; 
		  
		  else
			  break;
		  
	}
	cout<<"ɾ���ɹ�!\n";
}	 
             