#include"header.h"
#define RED "\033[31;1m"
#define GREEN "\033[32;1m"
#define RESET "\033[0m"
//#define BLACKBG "\033[42;31;1m"
void main()
{
	SLL *hptr=0;
	int op,c=0;
	while(1)
	{
		printf(RED"===============================================\n"RESET);
		printf(GREEN"1)add_begin 2)add_end 3) add_middle 4)print_rev 5)print_node 6)print_rec\n7)print_rec_rev 8)save_file 9)read_file 10)count_node 11)delete_node 12)delete_all\n13)search_node 14)sort_data 15)reverse_links 16)exit\n"RESET); 
		scanf("%d",&op);
		printf(RED"================================================\n"RESET);

		switch(op)
		{
			case 1:add_begin(&hptr);break;
			case 2:add_end(&hptr);break;
			case 3:add_middle(&hptr);break;
			case 4:print_rev(hptr);break;
			case 5:print_node(hptr);break;
			case 6:print_rec(hptr);break;
			case 7:print_rev_rec(hptr);break;
			case 8:save_file(hptr);break;
			case 9:read_file(&hptr);break;
			case 10:c=count_node(hptr);
				printf("total %d node is present\n",c);
				break;	
			case 11:delete_node(&hptr);break;
			case 12:delete_all(&hptr);break;
			case 13:search_node(hptr);break;
			case 14:sort_data(hptr);break;
			case 15:rev_links(&hptr);break;
			case 16:exit(0);
			default:printf(RED"SELECT PROPER OPTION\n"RESET);
		}
	}
}
void rev_links(SLL **ptr)
{
	if(*ptr==0)
	{
		printf(RED"NO DATA AVAILABLE"RESET);
		return;
	}
	int c=count_node(*ptr);
	if(c>1)
	{
		SLL **a=malloc(sizeof(SLL*)*c);
		SLL *temp=*ptr;
		int i=0;
			while(temp)
			{
				a[i++]=temp;
				temp=temp->next;
			}
		for(i=1;i<c;i++)
			a[i]->next=a[i-1];
		a[0]->next=0;
		*ptr=a[c-1];
		free(a);
	}
printf(RED"OPEARTION SUCSESSFULL\n"RESET);
}

void sort_data(SLL *ptr)
{ 
	if(ptr==0)
	{
		printf(RED"NO DATA AVAILABLE"RESET);
		return;
	}
	int op;
	printf("1)name wise sort 2) rollno wise sort\n");
	scanf("%d",&op);
	SLL *p1=ptr,*p2,temp,*t;
	int c=count_node(ptr);
	if(op==1)
	{
		for(int i=0;i<c-1;i++)
		{
			p2=p1->next;
			for(int j=0;j<c-1-i;j++)
			{
				if(strcmp(p1->name,p2->name)>0)
				{
					temp=*p1;//SLL varibale swap
					*p1=*p2;
					*p2=temp;

					t=p1->next;//node addresh swap
					p1->next=p2->next;
					p2->next=t;
				}
				p2=p2->next;
			}
			p1=p1->next;
		}
	}
	else if(op==2)
	{
		for(int i=0;i<c-1;i++)
		{
			p2=p1->next;
			for(int j=0;j<c-1-i;j++)
			{
				if(p1->rollno>p2->rollno)
				{
					temp=*p1;//SLL varibale swap
					*p1=*p2;
					*p2=temp;

					t=p1->next;//node addresh swap
					p1->next=p2->next;
					p2->next=t;
				}
				p2=p2->next;
			}
			p1=p1->next;
		}
		printf(RED"DATA SORT SUCSESSFULLY\n"RESET);
	}
}
void search_node(SLL *ptr)
{
	if(ptr==0)
	{
		printf(RED"NO DATA AVAILABLE\n"RESET);
		return;
	}
	int rollno,flag=0,op;
	char name[20];
	printf("1)rollno wise search\n2)name wise search\n");
	scanf("%d",&op);
	printf(RED"=========================="RESET);
	if(op==1)
	{
		printf("enter rollno\n");
		scanf("%d",&rollno);
		while(ptr)
		{
			if(ptr->rollno == rollno)
			{
				flag=1;
				printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
			}
			ptr=ptr->next;
		}
	}	
	else if(op==2)
	{
		printf("enter name\n");
		scanf("%s",name);
		while(ptr)
		{
			if(strcmp(ptr->name,name)==0)
			{
				flag=1;
				printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
			}
			ptr=ptr->next;
		}
	}
	if(flag==0)
		printf(RED"MATCH NOT FOUND\n"RESET);
}

void delete_all(SLL **ptr)
{
	if(*ptr==0)
	{
		printf(RED"NO DATA AVAILABLE\n"RESET);
		return;
	}
	SLL *del;
	while(*ptr)
	{
		del=*ptr;
		*ptr=del->next;
		free(del);
	}
	printf(RED"ALL NODE DELETE SUCSESSFULLY\n"RESET);
}

void delete_node(SLL **ptr)
{
	if(*ptr==0)
	{
		printf(RED"NO DATA AVAILABLE"RESET);
		return;
	}
	SLL *del=*ptr,*prev;
	int num;
	printf("entere roll no for delete purpose\n");
	scanf("%d",&num);
	while(del)
	{
		if(del->rollno==num)
		{
			if(*ptr==del)
				*ptr=del->next;
			else
				prev->next=del->next;
			printf(RED"DELETE SUCSESSFULLY\n"RESET);
			free(del);
			return;
		}
		prev=del;
		del=prev->next;
	}
	printf(RED"NO ROLLNO AVAILABLE\n"RESET);
}


void print_rev_rec(SLL *ptr)
{
	if(ptr)
	{
		if(ptr->next!=0)
			print_rev_rec(ptr->next);
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
	}
	else
		printf(RED"NO RECORD FOUND\n"RESET);

}
void print_rec(SLL *ptr)
{
	if(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		if(ptr->next!=0)
			print_rec(ptr->next);
	}
	else
		printf(RED"NO RECORD FOUND\n"RESET);
}


void print_rev(SLL *ptr)
{
	int c=count_node(ptr);
	if(c==0)
	{
		printf(RED"NO RECORD FOUND\n"RESET);
		return;
	}
	SLL *temp=ptr;
	for(int i=0;i<c;i++)
	{
		temp=ptr;
		for(int j=0;j<c-1-i;j++)
			temp=temp->next;
		printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
	}
}




void read_file(SLL **ptr)
{
	char s[20];
	printf("enter file name\n");
	scanf("%s",s);
	FILE *fp=fopen(s,"r");
	if(fp==0)
	{
		perror("fopen");
		return;
	}
SLL *new,*temp;
	while(1)
	{
		 new=malloc(sizeof(SLL));
		if((fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks))!=EOF)
		{
			if(*ptr==0)
			{
				new->next=*ptr;
				*ptr=new;
			}
			else
			{
				 temp=*ptr;
				while(temp->next)
					temp=temp->next;
				temp->next=new;
				new->next=0;
			}
		}
		else
			break;
	}
	printf(RED"READING SUCSESSFULLY\n"RESET);
}
int count_node(SLL *ptr)
{
	int c=0;
	while(ptr)
	{
		ptr=ptr->next;
		c++;
	}
	return c;
}
void save_file(SLL *ptr)
{
	if(ptr==0)
	{
		printf(RED"NO RECORD\n"RESET);
		return;
	}
	FILE *fp=fopen("student","r");
	int op;
	char s[20];
	if(fp!=0)
	{
		printf("fill is already presnet do you want erase data\n1)yes 2)no");
		scanf("%d",&op);
	}
		if(op==2)
		{
			printf("enter new file name\n");
			scanf("%s",s);
			fp=fopen(s,"w");
		}
		else
			fp=fopen("student","w");
				
	while(ptr)
	{
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	printf(RED"SAVE SUCSESSFULLY\n"RESET);
	fclose(fp);
}





void add_middle(SLL **ptr)
{
	SLL *new=malloc(sizeof(SLL));
	printf("enter rollno name marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	if(*ptr==0 || (*ptr)->rollno>new->rollno )
	{
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		SLL *temp=*ptr;
		while((temp->next !=0) && (new->rollno>temp->next->rollno))
			temp=temp->next;
		new->next=temp->next;
		temp->next=new;
	}
}

void add_end(SLL **ptr)
{
	SLL *new=malloc(sizeof(SLL));
	printf("enter rollno name marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	if(*ptr==0)
	{
		*ptr=new;
		new->next=0;
	}
	else
	{
		SLL *temp=*ptr;
		while(temp->next)
			temp=temp->next;
		temp->next=new;
		new->next=0;
	}
}


void add_begin(SLL **ptr)
{
	SLL *new=malloc(sizeof(SLL));
	printf("enter rollno name marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	new->next=*ptr;
	*ptr=new;
}
void print_node(SLL *ptr)
{
	printf(RED"=====================================\n"RESET);
	if(ptr==0)
	{
		printf(RED"NO RECORD AVAILABLE\n"RESET);
		return;
	}
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	printf(RED"=======================================\n"RESET);
}












