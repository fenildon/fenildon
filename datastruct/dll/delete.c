#include"header.h"
void delete_all()
{
	if(head == 0)
	{
		printf("no data is avilable\n");
		return;
	}
	DLL *ptr=head,*prev;
	while(ptr)
	{
		prev=ptr;
		ptr=ptr->next;
		free(prev);
	}
	head=0;
}

void delete_node()
{
	if(head==0)
	{
		printf("no data avilable\n");
		return;
	}
	int num;
	DLL *ptr=head;
	printf("enter the roll number \n");
	scanf("%d",&num);
	if(ptr->rn == num)
	{
		head=ptr->next;
		if(head != 0)
			head->prev=0;
		free(ptr);
		return;
	}
	while(ptr->next && ptr->rn != num)
		ptr=ptr->next;
	if(ptr->rn != num)
		printf("NO ROLL NO FOUND\n");
	else if(ptr->next == 0)
	{
		ptr->prev->next=0;
		free(ptr);
	}
	else
	{
		DLL *del_next=ptr->next,*del_prev=ptr->prev;
		del_prev->next=del_next;
		del_next->prev=del_prev;
		free(ptr);
	}
}

void delete_pos()
{
	if(head==0)
	{
		printf("NO DATA AVILABLE\n");
		return;
	}
	int pos,c=count_node();
	DLL *ptr=head;
	printf("enter pos\n");
	scanf("%d",&pos);
	if(pos>c || pos<=0)
	{
		printf("PROVIDE PROPER POS\n");
		return;
	}
	if(pos == 1)
	{
		head=ptr->next;
		if(head != 0)
			head->prev=0;
		free(ptr);
		ptr=0;
	}
	else if(pos==c)
	{
		DLL *last=head;
		while(last->next)
			last=last->next;
		last->prev->next=0;
		free(last);
		last=0;
	}
	else
	{
		int i=1;
		while(i<pos)
		{
			ptr=ptr->next;
			i++;
		}
		DLL *p=ptr->prev,*n=ptr->next;
		p->next=n;
		n->prev=p;
		free(ptr);
		ptr=0;
	}
}





































