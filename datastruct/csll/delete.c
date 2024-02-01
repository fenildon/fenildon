#include"header.h"
void delete_all()
{
	int c=1;
	if(hptr==0)
	{
		printf(RED"NO RECORD AVAILABLE\n"RESET);
		return;
	}
	CSLL *temp=hptr,*del=hptr;
	do
	{
		free(del);
		printf("node:%d delete sucsess fully\n",c++);	
		sleep(1);
		del=temp->next;
		temp=temp->next;
	}while(temp != hptr);

	hptr=0;
	printf(RED"ALL NODE DELETE SUCSESSFULLY\n"RESET);
}
void delete_node()
{
	if(hptr==0)
	{
		printf(RED"NO DATA AVAILABLE\n"RESET);
		return;
	}
	CSLL *del=hptr,*prev=hptr;
	int num;
	printf("enter roll no\n");
	scanf("%d",&num);
	if(del->next==hptr && del->rollno==num)//if there is one and only node
	{
		free(hptr);
		hptr=0;
		printf(RED"DELETE SUCSESSFULLY\n"RESET);
		return;
	}
	else
	{
		CSLL *last=hptr;
		while(last->next!=hptr)//finding last node
			last=last->next;
		if(del->rollno==num)//if fistt node is num
		{
			free(del);
			hptr=prev->next;
			last->next=hptr;
			printf(RED"DELETE SUCSESSFULLY\n"RESET);
			return;
		}
		else if(last->rollno == num)//if last node is num
		{
			while(prev->next != last)
				prev=prev->next;
			free(last);
			prev->next=hptr;
			printf(RED"DELETE SUCSESSFULLY\n"RESET);
			return;
		}
		else//if middle node is num
		{
			while(del->next !=hptr)
			{
				if(del->rollno == num)
				{
					prev->next=del->next;
					free(del);
					printf(RED"DELETE SUCSESSFULLY\n"RESET);
					return;
				}
				prev=del;
				del=del->next;
			}
		}

	}
	printf(RED"NO ROLLNO AVAILABLE\n"RESET);
}

void delete_pos()
{
	if(hptr==0)
	{
		printf(RED"NO DATA AVAILABLE\n"RESET);
		return;
	}
	int c=count_node();
	int pos;
	printf("enter position\n");
	scanf("%d",&pos);
	CSLL *del=hptr,*prev=hptr,*last=hptr;
	if(pos>=1 && pos<=c)
	{
		while(last->next!=hptr)
			last=last->next;
		if(pos==1 && c==1)//if one and only node //if 1 node is presnt
		{
			free(del);
			hptr=0;
			printf(RED"pos=%d is DELETE SUCSESSFULLY\n"RESET,pos);
			return;
		}
		else if(pos==c)//if it is last node //
		{
			while(prev->next!=last)//moving prev to before of last node
				prev=prev->next;
			free(last);
			prev->next=hptr;
			printf(RED"pos=%d is DELETE SUCSESSFULLY\n"RESET,pos);
			return;
		}
		else
		{
			if(pos==1)//if 1st node in delete between 3 node
			{
			hptr=prev->next;
			last->next=hptr;
			printf(RED"pos=%d is DELETE SUCSESSFULLY\n"RESET,pos);
			return;
			}	
			for(int i=1;i<c-3;i++)//moveing prev to before of position
				prev=prev->next;
			del=prev->next;//slect node which you want to delete
			prev->next=del->next;//crating link
//			last->next=hptr;//update last node
			free(del);
			printf(RED"pos=%d is DELETE SUCSESSFULLY\n"RESET,pos);
			return;
		}
	}
	else
		printf(RED"PROVIDE PROPER POSTION\n"RESET);
}












































