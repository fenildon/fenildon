#include<stdio.h>
#include<stdlib.h>
char *q;
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage:./my_prepro filename\n");
		return;
	}
	FILE *fp=fopen(argv[1],"r");
	char ch;
	int len=0,i;
	if(fp==0)
	{
		perror("fopen");
		return;
	}
	while(fgetc(fp)!=EOF)
		len++;
	rewind(fp);
	q=malloc(len+1);
	if(q==0)
	{
		perror("malloc");
		return;
	}
	i=0;
	while((ch=fgetc(fp))!=EOF)
		q[i++]=ch;
	q[i]=0;
	rewind(fp);

//	com_remove(q);
//	macro(q);
//	header_include();

printf("%s\n",q);
	i=0;
	while(argv[1][i]!='.')
		i++;
	argv[1][i+1]='i';
printf("%s\n",argv[1]);
	fp=fopen(argv[1],"w");
	for(i=0;q[i];i++)
	fputc(q[i],fp);

}




















