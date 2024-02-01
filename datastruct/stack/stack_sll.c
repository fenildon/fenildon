#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
	int num;
	struct stack *next;
}stk;
stk *hptr=0;
void push();
void pop();
void display();
int top=-1;
int max=4;
void main()
{
	int op;
	while(1)
	{
		printf("1)push 2)pop 3)display 4)exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3:display();break;
			case 4:exit(0);
			default:printf("unknown option\n");
		}
	}
}
void push()
{
	if(top>=max)
	{
		printf("stk is full\n");
		return;
	}
	stk *new=malloc(sizeof(stk));//newaly created node add at end
	printf("enter num\n");
	scanf("%d",&new->num);
	if(hptr==0)//if hptr is zero need to update hptr
	{
		hptr=new;
		new->next=0;
	}
	else
	{
		stk *temp=hptr;
		while(temp->next)//finding last node because of add at end
			temp=temp->next;

		temp->next=new;
		new->next=0;
	}
	top++;
}
void pop()
{
	if(top==-1)
	{
		printf("stack is underflow\n");
		return;
	}
	stk *last=hptr,*prev=hptr;
	if(hptr->next==0)//if there is only one node we need to modify hptr
	{
		free(hptr);
		hptr=0;
		top--;
		printf("POP SUCSESSFULLY\n");
		return;
	}
	//1) 1st method
	/*
	   while(last->next->next)
	   last=last->next;
	   free(last->next);
	   last->next=0;
	 */
	//2) 2nd method find last and prev node(easy to understand)

	while(last->next != 0)//last node
		last=last->next;
	while(prev->next != last)//prev node
		prev=prev->next;

	free(last);
	prev->next=0;

	printf("POP SUCSESSFULLY\n");
	top--;
}
void display()
{
	if(hptr==0)
	{
		printf("stak is empty\n");
		return;
	}
	stk *temp=hptr;
	while(temp)
	{
		printf("%d ",temp->num);
		temp=temp->next;
	}
	printf("\n");
}









