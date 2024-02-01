#include"header.h"
void print_node(void)
{
if(head==0)
{
printf("no data avilable\n");
return;
}
DLL *ptr=head;
while(ptr)
{
printf("%d %s\n",ptr->rn,ptr->name);
ptr=ptr->next;
}
}

void print_rev(void)
{
if(head==0)
{
printf("no data avilable\n");
return;
}
if(head->next==0)
{
printf("%d %s\n",head->rn,head->name);
return;
}
DLL *last=head;
while(last->next)
last=last->next;
while(last)
{
printf("%d %s\n",last->rn,last->name);
last=last->prev;
}
}

