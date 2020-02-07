#include"iostream.h"
#include"stdlib.h"
#include"head.h"
int memory_count;
void filesys_exit()
{
	close_();
	fd=fopen("d:\\filesystem","r+");
	fwrite(&filesystem,1,sizeof(struct file_system),fd);
	//for(memory_count=0;memory_count<512;memory_count++)
	   // fwrite(filesystem.fat_memory[memory_count],1,512,fd);
    
	fclose(fd);
	exit(0);
}
