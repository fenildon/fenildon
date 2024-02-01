#include"header.h"
void print_node()
{
	if(hptr==0)
	{
		printf(RED"NO DATA AVAILABLE\n"RESET);
		return;
	}
	CSLL *temp=hptr;
	do
	{
		printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
		temp=temp->next;
	}while(temp!=hptr);
}

void print_rev()
{
	if(hptr==0)
	{
		printf(RED"NO DATA AVAILABLE\n"RESET);
		return;
	}
	CSLL *temp;
	int c=count_node();
	if(c==1)
	{
		printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
		return;
	}
	else
	{
		int i,j;
		for(i=0;i<c;i++)
		{
			temp=hptr;
			for(j=0;j<c-1-i;j++)
				temp=temp->next;
			printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
		}
	}
}

void print_rec(CSLL *temp)
{
	if(hptr==0)
	{
		printf(RED"NO DATA AVAILABLE\n"RESET);
		return;
	}
	
	printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
	if(temp->next!=hptr)
	print_rec(temp->next);
	
}

void print_rev_rec(CSLL *temp)
{
	if(hptr==0)
	{
		printf(RED"NO DATA AVAILABLE\n"RESET);
		return;
	}
	
	if(temp->next!=hptr)
	print_rev_rec(temp->next);
	printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
        
}








