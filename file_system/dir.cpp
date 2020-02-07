#include"iostream.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"head.h"
int direct_count_sum;
void dir()
{
    for(direct_count_sum=0;direct_count_sum<8;direct_count_sum++)
		if((*current_direct).child_direct_use_state[direct_count_sum]==1)
			cout<<(*(*current_direct).point_to_child_direct[direct_count_sum]).direct_name
		    <<"-------------д©б╪"<<endl;
    for(direct_count_sum=0;direct_count_sum<8;direct_count_sum++)
		if((*current_direct).file_point_use_state[direct_count_sum]==1)
			cout<<(*(*current_direct).point_to_file[direct_count_sum]).file_name
			<<"-------------нд╪Ч"<<endl;
}