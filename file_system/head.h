#include"stdio.h"
struct direct
{
	char direct_name[8];  //目录名；
    struct file *point_to_file[8];  //每个指针指向一个文件项
    struct direct *point_to_parent_direct;  //指向父目录名
	struct direct *point_to_child_direct[8]; //指向子目录，用于在当前目录创建子目录
	char direct_used_or_not;  //目录使用标志：0代表未使用，1代表已使用
	char file_point_use_state[8];  //文件创建指针使用情况,0代表未使用，1代表已使用,开始时，都未使用，数目为8
	char child_direct_use_state[8]; //子目录创建指针使用情况，开始时，都未使用，数目为8
};


struct file
{
	char file_name[8];   //文件名
    int point_to_FAT;    //指向FAT表的一个表项，既文件的开始磁盘块
	char file_owner[8];   //文件所有者
	char file_used_or_not;  //文件使用标志：0代表未使用，1代表已使用
	int file_length; //文件所占的磁盘块数
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
