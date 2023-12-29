#include"header.h"
void main()
{
	char ch;
	SLL *headptr=0;
	while(1)
	{
		printf("*****STUDENT RECORD MENU*****\n");
		printf(" a/A :add new record\n d/D :delete a record\n s/S :show the list\n m/M :modify a record\n v/V :save\n e/E :exit\n t/T :sort the list\n l/L :delete all the records\n r/R :revrese the list\n Enter your choice:\t");
		scanf(" %c",&ch);
		ch=toupper(ch);
		switch(ch)
		{

			case 'A': stud_add(&headptr); break;
			case 'S': stud_show(headptr); break;
			case 'E': stud_exit(&headptr); break;
			case 'V': stud_save_file(headptr);break;
			case 'D': stud_del(&headptr);break;
			case 'M': stud_mod(headptr);break;
			case 'L': stud_del_all(&headptr);break;
			case 'R': stud_rev_list(headptr);break;
			case 'T': stud_sort_list(headptr);break;
			default: printf("Warning wrong option entered\n");
		}

	}
}

void stud_add(SLL **ptr)
{
	SLL *new=malloc(sizeof(SLL));
	static int rn=0;
	printf("Enter\nName:");
	scanf(" %[^\n]",new->name);
	printf("Percentage:");
	scanf("%f",&new->marks);
	new->rn=++rn;
	if(*ptr==0)
	{
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		SLL *last=*ptr;
		while((last->next!=0) && (new->rn > last->next->rn))
			last=last->next;
		new->next=last->next;
		last->next=new;
	}
}

void stud_show(SLL *ptr)
{

	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}
	SLL *p=ptr;
	//printf("Roll No\t\tName\t\tMarks\n");
	printf("=====================\n");
	do
	{
		printf("%d\t%s\t%f\n",p->rn,p->name,p->marks);
		p=p->next;
	}while(p);
	printf("=====================\n");
}


void stud_del(SLL **ptr)
{

	if(*ptr==0)
	{
		printf("There are no records to delete\n");
		return;
	}
	else
	{
		char ch;
		printf(" R/r: enter rollno to del\tN/n: enter name to del\t C/c: cancel\n");
		scanf(" %c",&ch);
		ch=toupper(ch);
		switch(ch)
		{
			case 'R': del_rn(&ptr); break;
			case 'N': del_name(&ptr);break;
			case 'C': return;
			default: printf("Warning: Wrong option entered\n");
		}
	}
}

void del_rn(SLL ***p)
{
	int rn=0,c=count_node(**p);
	printf("node=%d\n",c);
	SLL *del=**p,*prev;
	printf("Enter the roll number to delete\n");
	scanf("%d",&rn);
	while(del)
	{
		if(del->rn ==rn)
		{
			if(del==**p)
			{
				**p=del->next;			
			}
			else
			{			
				prev->next=del->next;
			}
			printf("**********************\n");
			printf("Roll number=%d record deleted\n",del->rn);
			printf("**********************\n");
			free(del);
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("Roll no not present\n");
}
void del_name(SLL ***p)
{
	char n[30];
	int nc=0;
	printf("Enter the name to delete\n");
	scanf(" %[^\n]",n);
	SLL *del=**p;
	while(del)
	{
		if(strcmp(del->name,n)==0)
			nc++;
		del=del->next;
	}
	if(nc==0)
	{
		printf("Name not present\n");
		return;
	}

	else if(nc==1)
	{
		SLL *prev;
		del=**p;
		while(del)
		{
			if(strcmp(del->name,n)==0)
			{
				if(del==**p)
				{
					**p=del->next;			
				}
				else
				{			
					prev->next=del->next;
				}
				printf("**********************\n");
				printf("%s Named record deleted\n",del->name);
				free(del);
				return;
			}
			prev=del;
			del=del->next;
		}
	}

	else
	{	
		del=**p;
		printf("These are the records with same name\n");
		printf("*************************\n");
		while(del)
		{
			if(strcmp(del->name,n)==0)
			{

				printf("%d %s %f\n",del->rn,del->name,del->marks);
			}
			del=del->next;
		}
		printf("*************************\n");
		del_rn(p);
	}
}


void stud_mod(SLL *ptr)
{
	if(ptr==0)
	{
		printf("There are no records to modify\n");
		return;
	}
	else
	{
		char ch;
		printf("Enter which record to search for modification\n");
		printf(" R/r: enter rollno to del\tN/n: enter name to del\t P/p: Percentage\n");
		scanf(" %c",&ch);
		ch=toupper(ch);
		switch(ch)
		{
			case 'R': mod_rn(ptr); break;
			case 'N': mod_name(ptr);break;
			case 'P': mod_perc(ptr);break;
			default: printf("Warning: Wrong option entered\n");
		}
	}

}
void mod_rn(SLL *p)
{
	SLL *mod=p;
	int rn;
	printf("Enter the roll number to modify\n");
	scanf("%d",&rn);
	while(mod)
	{
		if(mod->rn == rn)
		{
			printf("Enter\nName:");
			scanf(" %[^\n]",mod->name);
			printf("Percentage:");
			scanf("%f",&mod->marks);
			return;
		}
		mod=mod->next;
	}
	printf("Roll no not found\n");
}

void mod_name(SLL *p)
{
	char n[30];
	int nc=0;
	printf("Enter the name to modify\n");
	scanf(" %[^\n]",n);
	SLL *mod=p;
	while(mod)
	{
		if(strcmp(mod->name,n)==0)
			nc++;
		mod=mod->next;
	}
	if(nc==0)
	{
		printf("Name not present\n");
		return;
	}

	else if(nc==1)
	{
		mod=p;
		while(mod)
		{
			if(strcmp(mod->name,n)==0)
			{
				printf("Enter\nName:");
				scanf(" %[^\n]",mod->name);
				printf("Percentage:");
				scanf("%f",&mod->marks);
				return;
			}
			mod=mod->next;
		}
	}

	else
	{	
		mod=p;
		printf("These are the records with same name\n");
		printf("*************************\n");
		while(mod)
		{
			if(strcmp(mod->name,n)==0)
			{

				printf("%d %s %f\n",mod->rn,mod->name,mod->marks);
			}
			mod=mod->next;
		}
		printf("*************************\n");
		mod_rn(p);
	}

}

void mod_perc(SLL *p)
{

	float f;
	int nc=0;
	printf("Enter the percentage to modify\n");
	scanf("%f",&f);
	SLL *mod=p;
	while(mod)
	{
		if(mod->marks == f)
			nc++;
		mod=mod->next;
	}
	if(nc==0)
	{
		printf("Percentage not present\n");
		return;
	}

	else if(nc==1)
	{
		mod=p;
		while(mod)
		{
			if(mod->marks == f)
			{
				printf("Enter\nName:");
				scanf(" %[^\n]",mod->name);
				printf("Percentage:");
				scanf("%f",&mod->marks);
				return;
			}
			mod=mod->next;
		}
	}

	else
	{	
		mod=p;
		printf("These are the records with same percentage\n");
		printf("*************************\n");
		while(mod)
		{
			if(mod->marks == f)
			{

				printf("%d %s %f\n",mod->rn,mod->name,mod->marks);
			}
			mod=mod->next;
		}
		printf("*************************\n");
		mod_rn(p);
	}
}

void stud_del_all(SLL **ptr)
{
	if(*ptr==0)
	{
		printf("No records found\n");
		return;
	}
	SLL *del=*ptr;
	int c=1;
	while(del)
	{
		*ptr=del->next;
		sleep(1);
		printf("node: %d deleted\n",c++);
		free(del);
		del=*ptr;
	}
	printf("All records deleted\n");
}


void stud_exit(SLL **ptr)
{
	char ch;
	printf("Enter\n");
	printf(" S/s: save and exit\n E/e: exit without saving: ");
	scanf(" %c",&ch);
	ch=toupper(ch);
	switch(ch)
	{
		case 'S':stud_save_file(*ptr); exit(0);
		case 'E':stud_del_all(ptr);exit(0);
		default: printf("Warning: Wrong option entered\n");
	}
}


void stud_save_file(SLL *ptr)
{
	if(ptr==0)
	{
		printf("No Contents to save in the file\n");
		return;
	}

	FILE *fp;
	fp=fopen("student.dat","w");
	while(ptr)
	{
		fprintf(fp,"%d\t%s\t%f\n",ptr->rn,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	printf("Data is saved in the file\n");
	fclose(fp);

}


void stud_rev_list(SLL *ptr)
{
	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}
	int i,j,c=count_node(ptr);
	if(c==1)
	{
		printf("Warning: cannot reverse only 1 record present\n");
		return;
	}
	//printf("%d\n",c);
	SLL *p1,*p2,temp;
	p1=ptr;
	for(i=0;i<c/2;i++)
	{
		p2=ptr;
		for(j=0;j<c-1-i;j++)
			p2=p2->next;
		
		strcpy(temp.name,p1->name);
		temp.marks=p1->marks;

		
		strcpy(p1->name,p2->name);
		p1->marks=p2->marks;
		
		
		strcpy(p2->name,temp.name);
		p2->marks=temp.marks;
		
		p1=p1->next;
	}
	stud_show(ptr);
}

void stud_sort_list(SLL *ptr)
{
	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}
	int i,j,c=count_node(ptr);
	if(c==1)
	{
		printf("Warning: cannot sort only 1 record present\n");
		return;
	}
	printf("%d\n",c);
	SLL *p1,*p2,temp;
	p1=ptr;
	for(i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(j=0;j<c-1-i;j++)
		{
			if(p1->marks < p2->marks)
			{
				
				strcpy(temp.name,p1->name);
				temp.marks=p1->marks;

		
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;
		
		
				strcpy(p2->name,temp.name);
				p2->marks=temp.marks;

			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	stud_show(ptr);
	
}

int count_node(SLL *ptr)
{
	int c=0;
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}


