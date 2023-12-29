#include"header.h"
char *q;
void main(int argc,char **argv)
{
	FILE *fp;
	fp=fopen(argv[1],"r");
	char ch;
	int i=0,c=0;

	while((ch=fgetc(fp))!=EOF)
	{
		c++;
	}
	rewind(fp);
	q=malloc(sizeof(char)*(c));
	while((ch=fgetc(fp))!=EOF)
	{
		q[i]=ch;
		i++;
	}
	q[i]=0;
	com_rmv(q);
	macro(q);
	include_header();


	char wow[30];
	int len;
	strcpy(wow,argv[1]);
	len=strlen(wow);
	wow[len-1]='i';
	FILE *dp;
	dp=fopen(wow,"a");

	for(i=0;q[i];i++)
	{
		fputc(q[i],dp);
	}
}



