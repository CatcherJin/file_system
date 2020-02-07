#include"stdio.h"
struct direct
{
	char direct_name[8];  //Ŀ¼����
    struct file *point_to_file[8];  //ÿ��ָ��ָ��һ���ļ���
    struct direct *point_to_parent_direct;  //ָ��Ŀ¼��
	struct direct *point_to_child_direct[8]; //ָ����Ŀ¼�������ڵ�ǰĿ¼������Ŀ¼
	char direct_used_or_not;  //Ŀ¼ʹ�ñ�־��0����δʹ�ã�1������ʹ��
	char file_point_use_state[8];  //�ļ�����ָ��ʹ�����,0����δʹ�ã�1������ʹ��,��ʼʱ����δʹ�ã���ĿΪ8
	char child_direct_use_state[8]; //��Ŀ¼����ָ��ʹ���������ʼʱ����δʹ�ã���ĿΪ8
};


struct file
{
	char file_name[8];   //�ļ���
    int point_to_FAT;    //ָ��FAT���һ��������ļ��Ŀ�ʼ���̿�
	char file_owner[8];   //�ļ�������
	char file_used_or_not;  //�ļ�ʹ�ñ�־��0����δʹ�ã�1������ʹ��
	int file_length; //�ļ���ռ�Ĵ��̿���
};


struct user_info
{
	char user_name[8];
	char login_password[8];
};


struct fat
{   
	int used_count;
	int file_in_FAT;
};



struct file_system 
{
	struct direct direct_team[8];
	struct file file_team[64];
	struct fat FAT[512];
	struct user_info user_team[8];
	//char fat_memory[512][512];
};



struct visable
{
	char direct_visable[8][8];
	int point;
};




extern char memory[10][512];
extern struct visable  visable_direct;
extern struct file empty;
extern struct file * current_file;
extern int file_fat;
extern FILE* fd;
extern struct direct * root_direct;
extern struct direct * current_direct;
extern struct user_info * current_user;
extern struct file_system filesystem;
extern void create_(char filename[8]);
extern void delete_(char filename[8]);
extern int open(char filename[8]);
extern void close_();
extern void read(char filename[8]);
extern void write(char filename[8],char command_data_[16]);
extern void mkdir(char filename[8]);
extern void chdir(char filename[8]);
extern void dir();
extern void filesys_exit();
extern void format();
extern int install();
