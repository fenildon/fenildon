#include"header.h"
CSLL *hptr=0;
void main()
{
	int op,c;
	while(1)
	{
printf(GREEN"=============================================\n"RESET);
		printf(MEG"1)add_begin 2)add_end 3)add_middle 4)print_node 5)print_rev 6)print_rec\n7)print_rev_rec 8)save_file 9)read_file 10)sort_data 11)search_node 12)delete_node\n13)delete_all 14)rev_links 15)count_node 16)delete_pos 17)rev_lins_dma 18)exit\n"RESET);
printf(GREEN"=============================================\n"RESET);
		scanf("%d",&op);
		switch(op)
		{

			case 1:add_begin();break;
			case 2:add_end();break;
			case 3:add_middle();break;
			case 4:print_node();break;
			case 5:print_rev();break;
			case 6:print_rec(hptr);break;
			case 7:print_rev_rec(hptr);break;
			case 8:save_file();break;
			case 9:read_file();break;
			case 10:sort_data();break;
			case 11:search_node();break;
			case 12:delete_node();break;
			case 13:delete_all();break;
			case 14:rev_links();break;
			case 15:c=count_node();
				printf("total node:=%d\n",c);break;
			case 16:delete_pos();break;
                        case 17:rev_links_dma();break;
			case 18:exit(0);
		    default:printf(RED"WARNING::CHOOSE CORRCT OPTION\n"RESET);
		}
	}
}
