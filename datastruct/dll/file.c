#include"header.h"
void save_file(void)
{
	if(head==0)
	{
		printf("no record avilable\n");
		return;
	}
	FILE *fp=fopen("data","w");
	DLL *ptr=head;
	while(ptr)
	{
		fprintf(fp,"%d %s\n",ptr->rn,ptr->name);
		ptr=ptr->next;
	}
fclose(fp);
printf("SUCSESS FULLY READ\n");
}

void read_file(void)
{
	FILE *fp=fopen("data","r");
	if(fp==0)
	{
		perror("fopen");
		return;
	}
	DLL *head1=0;
	while(1)
	{
		DLL *new=calloc(1,sizeof(DLL));
		if(fscanf(fp,"%d %s",&new->rn,new->name)!=EOF)
		{
			if(head1==0)
				head1=new;
			else
			{
				DLL *last=head1;

				while(last->next)
					last=last->next;
				last->next=new;
				new->prev=last;
			}
		}
		else
			break;
	}

	if(head==0)
		head=head1;
	else
	{
		DLL *last=head;
		while(last->next)
			last=last->next;
		last->next=head1;
		head1->prev=last;
	}
if(head1==0)
printf("FILE IS EMPTY\n");
fclose(fp);
printf("SUCSESSFULL\n");
}








