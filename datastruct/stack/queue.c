#include<stdio.h>
#include<stdlib.h>
#define size 5
void enq();
void deq();
void display();
int q[size];
int top=-1;
void main()
{
	int op;
	while(1)
	{
		printf("1)enqueue 2)dequeue 3)display 4)exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:enq();break;
			case 2:deq();break;
			case 3:display();break;
			case 4:exit(0);
		}
	}
}
void enq()
{
	if(top>=4)
	{
		printf("queue is overflow\n");
		return;
	}
	int num;
	printf("enter the num\n");
	scanf("%d",&num);
	q[++top]=num;
	printf("ADDED\n");
}
void deq()
{
	if(top==-1)
	{
		printf("que is underflow\n");
		return;
	}
	int i;
	for(i=0;i<top;i++)
		q[i]=q[i+1];
	top--;
}
void display()
{
	if(top==-1)
	{
		printf("queue is empty\n");
		return;
	}
int i;
	for(i=0;i<=top;i++)
		printf("%d ",q[i]);
	printf("\n");
}


