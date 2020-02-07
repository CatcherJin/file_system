#include"iostream.h"
#include"head.h"
#include"stdlib.h"
#include"string.h"
#include"stdio.h"

struct direct * root_direct;
char *disk_file;
int count_1;
int file_count; 


void format()
{   

	
	   
	strcpy(filesystem.user_team[0].user_name,"jin1");
	strcpy(filesystem.user_team[0].login_password,"123");
	 
	strcpy(filesystem.user_team[1].user_name,"jin2");
	strcpy(filesystem.user_team[1].login_password,"123");

	strcpy(filesystem.user_team[2].user_name,"jin3");
	strcpy(filesystem.user_team[2].login_password,"123");

	strcpy(filesystem.user_team[3].user_name,"jin4");
	strcpy(filesystem.user_team[3].login_password,"123");

	strcpy(filesystem.user_team[4].user_name,"jin5");
	strcpy(filesystem.user_team[4].login_password,"123");

	strcpy(filesystem.user_team[5].user_name,"jin6");
	strcpy(filesystem.user_team[5].login_password,"123");

	strcpy(filesystem.user_team[6].user_name,"jin7");
	strcpy(filesystem.user_team[6].login_password,"123");

	strcpy(filesystem.user_team[7].user_name,"jin8");
	strcpy(filesystem.user_team[7].login_password,"123");
  
	fd=fopen("d:\\filesystem","w+");
	if(fd==NULL)
	{
		cout<<"打开文件失败!\n";
		return ;
	}
   

	//初始化
	for(file_count=1;file_count<8;file_count++)
	{
		filesystem.direct_team[file_count].direct_used_or_not=0;
		for(count_1=0;count_1<8;count_1++)
		{
			filesystem.direct_team[file_count].file_point_use_state[count_1]=0;//该目录下文件使用状态
            filesystem.direct_team[file_count].child_direct_use_state[count_1]=0;//子目录使用状态
		}
	}

	strcpy(filesystem.direct_team[0].direct_name,"home"); //根目录为home
	filesystem.direct_team[0].direct_used_or_not=1;

	for(file_count=0;file_count<64;file_count++)//所有文件都清空
	{
		filesystem.file_team[file_count].file_used_or_not=0;
		filesystem.file_team[file_count].file_length=0;

	}
	
	 filesystem.FAT[0].file_in_FAT=-2;
	 

	for(file_count=1;file_count<512;file_count++)//文件使用状态
	{   
		filesystem.FAT[file_count].file_in_FAT=0;
		filesystem.FAT[file_count].used_count=0;
	
	}
	fwrite(&filesystem,1,sizeof(struct file_system),fd);//写入文本中保存
    disk_file=(char*)malloc(512*512);
	//fseek(fd,sizeof(struct file_system),0);
	fwrite(disk_file,1,512*512,fd);
	free(disk_file);

    current_direct=&filesystem.direct_team[0];
	filesystem.direct_team[0].point_to_parent_direct=&filesystem.direct_team[0];
    current_file=&empty;
     strcpy(visable_direct.direct_visable[0],"home");
	 visable_direct.point=0;
	fclose(fd);
	cout<<"系统格式化成功，欢迎你\n\n";
}
