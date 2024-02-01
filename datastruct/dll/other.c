#include"header.h"
int count_node(void)
{
	DLL *ptr=head;
	int c=0;
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}

void sort_data()
{
	int c=count_node();
	if(c==0)
	{
		printf("no data avilable\n");
		return;
	}
	DLL *p1=head,*p2;
	DLL *ptr,obj;
	for(int i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(int j=0;j<c-1-i;j++)
		{
			if(p1->rn>p2->rn)
			{
				obj=*p1;
				*p1=*p2;
				*p2=obj;

				ptr=p1->next;
				p1->next=p2->next;
				p2->next=ptr;

				ptr=p1->prev;
				p1->prev=p2->prev;
				p2->prev=ptr;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
}

void rev_links(void)
{
	if(head==0)
	{
		printf("no data avilable\n");
		return;
	}
	DLL *ptr=head,*temp,*q;
	while(ptr)
	{
		temp=ptr;
		ptr=ptr->next;
		q=temp->next;
		temp->next=temp->prev;
		temp->prev=q;
	}
	head=temp;
}

void rev_data()
{
	if(head==0)
	{
		printf("no data avilable\n");
		return;
	}
	int c=count_node();
	char buf[20];
	DLL *first=head,*last=head;
	while(last->next)
		last=last->next;
	for(int i=0;i<(c/2);i++)
	{
		first->rn=first->rn + last->rn -(last->rn=first->rn);
		strcpy(buf,first->name);
		strcpy(first->name,last->name);
		strcpy(last->name,buf);
		first=first->next;
		last=last->prev;

	}
}



























