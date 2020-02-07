#include"iostream.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"head.h"
FILE *fd;
int m_count;
int install()
{
	
	fd=fopen("d:\\filesystem","r");
	if(fd==NULL)
	{
		cout<<"磁盘还未格式化,请输入Y字符或y字符,进行格式化!\n";
		return 0;
	}
	fread(&filesystem,1,sizeof(struct file_system),fd);
	current_direct=&filesystem.direct_team[0];
	current_file=&empty;
    strcpy(visable_direct.direct_visable[0],"home");
	visable_direct.point=0;
	fclose(fd);
	cout<<"登陆系统成功，欢迎你\n\n";
	//cout<<filesystem.user_team[0].user_name<<"   "<<filesystem.user_team[0].login_password<<endl;
	return 1;
}
