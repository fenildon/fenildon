#include"header.h"
int count_node()
{
	if(hptr==0)
		return 0;
	int c=0;
	CSLL *temp=hptr;
	do
	{
		c++;
		temp=temp->next;
	}while(temp!=hptr);
	return c;
}

void rev_links()
{
	if(hptr==0)
	{
		printf(RED"NO DATA AVAILABLE\n"RESET);
		return;
	}
	CSLL *first=hptr,*last=hptr,*p1,*p2;

	while(last->next != hptr)//last is pointing last node
		last=last->next;

	int c=count_node();
	if(c==1)
		return;
	if(c==2)
	{
		first->next=last;
		last->next=first;
		hptr=last;
		return;
	}
	for(int i=0;i<c-1;i++)
	{
		p1=hptr;
		p2=hptr;
		for(int j=0 ;j<c-1-i;j++)
			p1=p1->next;
		for(int j=0;j<c-2-i;j++)
			p2=p2->next;

		p1->next=p2;
	}
	hptr=last;
	first->next=last;

}

void rev_links_dma()
{
	if(hptr==0)
	{
		printf("NO DATA AVILABLE"RESET);
		return;
	}
	int c=count_node();
	if(c==1)
		return;
	else if(c==2)
	{
		CSLL *first=hptr,*last=first->next;
		first->next=last;
		last->next=first;
		hptr=last;
		return;
	}
	else
	{
		CSLL **p=malloc(sizeof(CSLL *)*c),*temp=hptr;
		int i=0;
		do//storing node addresh in dma
		{
			p[i++]=temp;
			temp=temp->next;
		}while(temp!= hptr);

		for(i=1;i<c;i++)//revesring node
			p[i]->next=p[i-1];

		p[0]->next=p[c-1];//change link of first node
		hptr=p[c-1];//hptr is pointing to last
	}
}

void save_file()
{
	if(hptr==0)
	{
		printf(RED"NO DATA AVILABLE"RESET);
		return;
	}
	FILE *fp=fopen("student","w");
	CSLL *temp=hptr;
	do
	{
		fprintf(fp,"%d %s %f\n",temp->rollno,temp->name,temp->marks);
		temp=temp->next;
	}while(temp!=hptr);
	printf(RED"FILE SAVE SUCSESSFULLY\n"RESET);
}

void read_file()
{
	FILE *fp=fopen("student","r");
	if(fp==0)
	{
		perror("fopen");
		return;
	}
	CSLL *last=hptr;

	while(1)
	{
		CSLL *new=malloc(sizeof(CSLL));
		if((fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks)) != -1)
		{
			if(hptr==0)
			{
				hptr=new;
				new->next=new;
			}
			else
			{
				CSLL *last=hptr;
				while(last->next != hptr)
					last =last->next;
				last->next=new;
				new->next=hptr;
			}
		}
		else
			break;
	}
}































































