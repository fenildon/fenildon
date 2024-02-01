#include"header.h"
void sort_data()
{
	if(hptr==0)
	{
		printf(RED"NO DATA AVILABLE\n"RESET);
		return;
	}
	int c=count_node();
	CSLL *p1=hptr,*p2=hptr,t,*ptr;
	for(int i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(int j=0;j<c-1-i;j++)
		{
			if(p1->rollno > p2->rollno)
			{
				t=*p1;
				*p1=*p2;
				*p2=t;

				ptr=p1->next;
				p1->next=p2->next;
				p2->next=ptr;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
}

void search_node()
{
if(hptr==0)
{
printf(RED"NO DATA AVILABLE"RESET);
return;
}
CSLL *temp=hptr;
int num,flag=0;
printf("enter roll no\n");
scanf("%d",&num);
do
{
if(temp->rollno == num)
{
flag=1;
printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
}
temp=temp->next;
}while(temp!=hptr);
if(flag==0)
printf(RED"NO RECORED AVILABLE\n"RESET);

}



  
