#include"iostream.h"
#include"head.h"
#include"stdlib.h"
#include"string.h"
 
struct user_info * current_user;

struct file_system filesystem;  
 
struct visable  visable_direct;   
    
	char user_name_[8];
	char command[8];
	char command_data[8];
	char command_data_[16];
	char format_data;
	char pass_word[8];
	char circurt[8];
    char file_input[30];
    char tempory_name[30];

	int n=0;
	int count_=0;
	int input_count;



	char memory[10][512];
  
	
void main()
{   

       cout<<"是否要格式化目前内容？(Y/N) Y:是 N:否  :";
    
	   while(true)
	   {
		   
        cin.getline(circurt,8);
	    if((strlen(circurt)>1)||(strlen(circurt)==0))
		{
			if(install()==1)
				break;
				
		}
	    else
		{
	       format_data=circurt[0];
	       if((format_data=='Y')||(format_data=='y'))
		   {
		     format();
			 break;
		     
		   }
	     
	       else 
		   {
		      if(install()==1)
			     break;
	        
		   }
	   
		}
	   }
	 	 
	
	while(true)
	{   n++;  
	    if(n>3)
		{
			cout<<"由于你已经连续输入3次错误的用户名或密码，登录失败!\n";
			exit(0);
		}
		cout<<"目前系统已有用户名:";
		for(int i=0;i<8;i++){
			cout<<filesystem.user_team[i].user_name<<"/";
		}
		cout<<"\n";
		cout<<"\n请输入用户名:";
		cin>>user_name_;
		cout<<"\n请输入密码:";
		cin>>pass_word;
		cout<<endl;
	    if((strcmp(filesystem.user_team[0].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[0].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[0];
			 cout<<"登录成功,当前用户为:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[1].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[1].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[1];
			 cout<<"登录成功,当前用户为:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[2].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[2].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[2];
			 cout<<"登录成功,当前用户为:"<<user_name_<<endl;
			 break;
		}


		if((strcmp(filesystem.user_team[3].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[3].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[3];
			 cout<<"登录成功,当前用户为:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[4].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[4].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[4];
			 cout<<"登录成功,当前用户为:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[5].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[5].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[5];
			 cout<<"登录成功,当前用户为:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[6].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[6].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[6];
			 cout<<"登录成功,当前用户为:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[7].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[7].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[7];
			 cout<<"登录成功,当前用户为:"<<user_name_<<endl;
			 break;
		}
		if(n<=3)
			cout<<"用户名和密码不匹配,请重新输入!\n";
	}
    
	    cout<<endl;
		cout<<"---------------命令选择-------------------------\n\n";
		cout<<"dir            显示当前目录中的子目录和文件\n";
		cout<<"mkdir          创建目录\n";
		cout<<"cd             改变当前目录\n";
		cout<<"create         创建文件\n";
		cout<<"delete         删除文件\n";
		cout<<"open           打开文件\n";
		cout<<"close          关闭文件\n";
		cout<<"read           读文件\n";
		cout<<"write          写文件\n";
		cout<<"logout         保存结果并退出系统\n\n";
		cout<<"------------------------------------------------\n";
	while(true)
	{  	
		cout<<endl;
		for(n=0;n<=visable_direct.point;n++)
			cout<<visable_direct.direct_visable[n]<<"/"; //输出当前目录
			
		   
		cout<<"\n$";
	//	cin>>command; 


		cin>>tempory_name;
		if(strlen(tempory_name)>8)
		{
			cout<<"请输入正确命令\n";
		
		}
		else
		{
			for(n=0;n<8;n++)
                 command[n]=tempory_name[n];


       
	    
	    	if(strcmp(command,"create")==0)
			{   
			   cin>>command_data;
			    if(strlen(command_data)>8)
				{
				cout<<"文件名长度应小于8,此次操作失败!\n";
				
				}
		    	else
             	   create_(command_data);
		
			}

	    	else if(strcmp(command,"delete")==0)
			{   
		    	cin>>command_data;
		    	delete_(command_data);
			}
		    else if(strcmp(command,"open")==0)
			{
			   cin>>command_data;
			   open(command_data);
			
			}

		    else if(strcmp(command,"close")==0)
			{
			   // cin>>command_data;
        	    close_();
			
			}

	    	else if(strcmp(command,"read")==0)
			{
			    cin>>command_data;
			    read(command_data);
			
			}

		    else if(strcmp(command,"write")==0)
			{   
			   cin>>command_data; 
			   cin.ignore(1,32); //删除缓冲区
		  
				
		
		       cin.getline(file_input,30,10);
               if(strlen(file_input)>=16)
			   {
			       cout<<"要写入的数据长度超过16，一次写入的数据长度应小于16，写入失败!\n";
			  
			   }
		       else 
			   {
                  for(input_count=0;input_count<16;input_count++)
                      command_data_[input_count]=file_input[input_count];
		  
		
		    
                    write(command_data,command_data_);
			   }
		
			}

		    else if(strcmp(command,"mkdir")==0)
			{  
			   cin>>command_data;
			    if(strlen(command_data)>8)
				{
				cout<<"文件名应小于8,此次操作失败!\n";
				
				}
				else
					mkdir(command_data);

			}

		    else if(strcmp(command,"cd")==0)
			{
			   cin>>command_data;
			   if(strlen(command_data)>8)
				{
				cout<<"文件名应小于8,此次操作失败!\n";
				
				}
				else
					chdir(command_data);
			
		
			}

	    	else if(strcmp(command,"dir")==0)
			{
			  dir();
			
			}

		    else if(strcmp(command,"logout")==0)
			{
			   filesys_exit();
		
			}
	
		    else
			{
				cout<<"此命令不存在!\n";
				cin.ignore(20,10);
			}
		}
		
	}
}
	     
           
