#include"header.h"
DLL *head;
void main()
{
	int op,c;
	while(1)
	{
		printf(MEG"1)add_begin 2)add_end 3)add_middle 4)print_node\n 5)print_rev 6)count_node 7)rev_links 8)save_file\n 9)read_file 10)delete_all 11)delete_node 12)delete_pos 13)sort_data 14)rev_data 15)exit\n"RESET);
		scanf("%d",&op);
		switch(op)
		{
			case 1:add_begin();break;
			case 2:add_end();break;
			case 3:add_middle();break;
			case 4:print_node();break;
			case 5:print_rev();break;
			case 6:c=count_node();
				printf("total node = %d\n",c);
				break;
			case 7:rev_links();break;
			case 8:save_file();break;
			case 9:read_file();break;
			case 10:delete_all();break;
			case 11:delete_node();break;
			case 12:delete_pos();break;
			case 13:sort_data();break;
                        case 14:rev_data();break;
			case 15:exit(0);
			default:printf(GREEN"UNKNOWN OPTION\n"RESET);
		}
	}
}
