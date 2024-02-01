#include<stdio.h>
#include<stdlib.h>
void main(int argc,char **argv)
{
	if(argc!=4)
	{
		printf("usage:./a.out filename oldchar newchar\n");
		return;
	}
	FILE *fp=fopen(argv[1],"r+");
	if(fp==0)
	{
		perror("fopen");
		return;
	}
	char *q,ch;
	int c=0,i;
	while(fgetc(fp)!=EOF)
		c++;
	q=malloc(c+1);
	rewind(fp);

	for(i=0;(ch=fgetc(fp))!=EOF;i++)
		q[i]=ch;
	q[i]=0;
	rewind(fp);
	for(i=0;q[i];i++)
		if(q[i]==argv[2][0])
			q[i]=argv[3][0];

        fputs(q,fp);
}























