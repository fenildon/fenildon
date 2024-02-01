#include<stdio.h>
#include<stdlib.h>
#define size 5
void push();
void pop();
void display();

int stk[size];
int top=-1;
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
if(top>=4)
{
printf("STACK IS OVERFLOW\n");
return;
}
int num;
printf("enter the number\n");
scanf("%d",&num);
stk[++top]=num;
printf("ADDED\n");
}
void pop()
{
int num;
if(top==-1)
{
printf("STACK IS UNDERFLOW\n");
return;
}
top--;
printf("POP SUCSESFULLY\n");
}
void display()
{
if(top==-1)
{
printf("STACK IS EMPTY\n");
return;
}
for(int i=0;i<=top;i++)
printf("%d ",stk[i]);
printf("\n");
}






