#include"header.h"

DLL* rn_chack(int num);
void add_begin()
{
	DLL *ptr=head;
	DLL *new=calloc(1,sizeof(DLL));
	printf("enter rn and name\n");
	scanf("%d %s",&new->rn,new->name);
	if(ptr==0)
		head=new;
	else
	{
		new->next=head;
		head->prev=new;
		head=new;
	}
}
void add_middle(void)
{
	DLL *new=calloc(1,sizeof(DLL));
	printf("enter rn and name\n");
	scanf("%d %s",&new->rn,new->name);
	if(head==0)//no node
	{
		head=new;
		return;
	}
	DLL *rn_addr=rn_chack(new->rn);//it will return addresh of node 
	if(rn_addr->next==0 && rn_addr->rn < new ->rn)//if it is last node and add at end
	{
		rn_addr->next=new;
		new->prev=rn_addr;
	}
	else if(rn_addr==head && rn_addr->rn > new ->rn)//if it is first node add at begin
	{
		rn_addr->prev=new;
		new->next=rn_addr;
		head=new;
	}
	else//if add at middle
	{
		DLL *old_prev=rn_addr->prev;
		rn_addr->prev=new;
		new->next=rn_addr;
		new->prev=old_prev;
		old_prev->next=new;
	}
}



DLL* rn_chack(int num)
{
	DLL *ptr=head;
	while(ptr->next && ptr->rn<num)
		ptr=ptr->next;

	return ptr;
}

void add_end()
{
	DLL *new=calloc(1,sizeof(DLL));

	printf("enter rn and name\n");
	scanf("%d %s",&new->rn,new->name);
	if(head==0)
		head=new;
	else
	{
		DLL *last=head;
		while(last->next)
			last=last->next;
		last->next=new;
		new->prev=last;
	}
}












