#include"header.h"
void add_begin()
{
	CSLL *new=malloc(sizeof(CSLL)),*temp=hptr;
	printf("enter rollno name marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);

	if(hptr==0)
		new->next=new;
	else
	{
		new->next=hptr;
		while(temp->next!=hptr)
			temp=temp->next;
		temp->next=new;
	}
	hptr=new;
	printf(RED"SUCSSESS\n"RESET);
}
void add_end()
{
	CSLL *new=malloc(sizeof(CSLL)),*temp=hptr;
	printf("enter rollno name marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	if(hptr==0)
	{
		new->next=new;
		hptr=new;
	}
	else
	{
		new->next=hptr;
		while(temp->next!=hptr)
			temp=temp->next;
		temp->next=new;
	}
}
void add_middle()
{
	CSLL *new=malloc(sizeof(CSLL)),*temp=hptr;
	printf("enter rollno name marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	if(hptr==0)
	{
		new->next=new;
		hptr=new;
	}
	else if(hptr->rollno > new->rollno)
	{
		new->next=hptr;
		while(temp->next!=hptr)
			temp=temp->next;
		temp->next=new;
		hptr=new;
	}
	else
	{
		while((temp->next != hptr) && (new->rollno>temp->next->rollno))
			temp=temp->next;
		if(hptr==temp->next)	
		{
			new->next=hptr;
			temp->next=new;
		}
		else
		{
		new->next=temp->next;
		temp->next=new;
		}

	}
}
