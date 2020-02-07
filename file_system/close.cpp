#include"head.h"
#include"stdio.h"
struct file empty;
int file_close;
int file_close_count;
void close_()
{    
	fd=fopen("d:\\filesystem","r+");//打开文件
	file_close_count=(*current_file).point_to_FAT;//指向当前块号
    for(file_close=0;file_close<(*current_file).file_length;file_close++)
	{ 
		fseek(fd,sizeof(struct file_system)+512*file_close_count,0);//设置文件读写指针
		fwrite(memory[file_close],1,512,fd);//内存中写入磁盘
        file_close_count=filesystem.FAT[file_close_count].file_in_FAT;//指向下一快号
	}
	fclose(fd);//关闭文件
    
    current_file=&empty;//当前文件指针指向系统保留文件的节点，不指向刚刚打开的文件
	                    //完成不打开不能读的功能
   
}
