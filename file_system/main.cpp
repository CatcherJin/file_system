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

       cout<<"�Ƿ�Ҫ��ʽ��Ŀǰ���ݣ�(Y/N) Y:�� N:��  :";
    
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
			cout<<"�������Ѿ���������3�δ�����û��������룬��¼ʧ��!\n";
			exit(0);
		}
		cout<<"Ŀǰϵͳ�����û���:";
		for(int i=0;i<8;i++){
			cout<<filesystem.user_team[i].user_name<<"/";
		}
		cout<<"\n";
		cout<<"\n�������û���:";
		cin>>user_name_;
		cout<<"\n����������:";
		cin>>pass_word;
		cout<<endl;
	    if((strcmp(filesystem.user_team[0].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[0].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[0];
			 cout<<"��¼�ɹ�,��ǰ�û�Ϊ:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[1].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[1].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[1];
			 cout<<"��¼�ɹ�,��ǰ�û�Ϊ:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[2].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[2].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[2];
			 cout<<"��¼�ɹ�,��ǰ�û�Ϊ:"<<user_name_<<endl;
			 break;
		}


		if((strcmp(filesystem.user_team[3].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[3].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[3];
			 cout<<"��¼�ɹ�,��ǰ�û�Ϊ:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[4].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[4].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[4];
			 cout<<"��¼�ɹ�,��ǰ�û�Ϊ:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[5].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[5].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[5];
			 cout<<"��¼�ɹ�,��ǰ�û�Ϊ:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[6].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[6].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[6];
			 cout<<"��¼�ɹ�,��ǰ�û�Ϊ:"<<user_name_<<endl;
			 break;
		}

		if((strcmp(filesystem.user_team[7].user_name,user_name_)==0)&&(strcmp(filesystem.user_team[7].login_password,pass_word)==0))
		{
			 current_user=&filesystem.user_team[7];
			 cout<<"��¼�ɹ�,��ǰ�û�Ϊ:"<<user_name_<<endl;
			 break;
		}
		if(n<=3)
			cout<<"�û��������벻ƥ��,����������!\n";
	}
    
	    cout<<endl;
		cout<<"---------------����ѡ��-------------------------\n\n";
		cout<<"dir            ��ʾ��ǰĿ¼�е���Ŀ¼���ļ�\n";
		cout<<"mkdir          ����Ŀ¼\n";
		cout<<"cd             �ı䵱ǰĿ¼\n";
		cout<<"create         �����ļ�\n";
		cout<<"delete         ɾ���ļ�\n";
		cout<<"open           ���ļ�\n";
		cout<<"close          �ر��ļ�\n";
		cout<<"read           ���ļ�\n";
		cout<<"write          д�ļ�\n";
		cout<<"logout         ���������˳�ϵͳ\n\n";
		cout<<"------------------------------------------------\n";
	while(true)
	{  	
		cout<<endl;
		for(n=0;n<=visable_direct.point;n++)
			cout<<visable_direct.direct_visable[n]<<"/"; //�����ǰĿ¼
			
		   
		cout<<"\n$";
	//	cin>>command; 


		cin>>tempory_name;
		if(strlen(tempory_name)>8)
		{
			cout<<"��������ȷ����\n";
		
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
				cout<<"�ļ�������ӦС��8,�˴β���ʧ��!\n";
				
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
			   cin.ignore(1,32); //ɾ��������
		  
				
		
		       cin.getline(file_input,30,10);
               if(strlen(file_input)>=16)
			   {
			       cout<<"Ҫд������ݳ��ȳ���16��һ��д������ݳ���ӦС��16��д��ʧ��!\n";
			  
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
				cout<<"�ļ���ӦС��8,�˴β���ʧ��!\n";
				
				}
				else
					mkdir(command_data);

			}

		    else if(strcmp(command,"cd")==0)
			{
			   cin>>command_data;
			   if(strlen(command_data)>8)
				{
				cout<<"�ļ���ӦС��8,�˴β���ʧ��!\n";
				
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
				cout<<"���������!\n";
				cin.ignore(20,10);
			}
		}
		
	}
}
	     
           
