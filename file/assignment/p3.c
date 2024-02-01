#include<stdio.h>
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage:./a.out filename\n");
		return;
	}
	FILE *fp=fopen(argv[1],"r");
	if(fp==0)
	{
		perror("fopen");
		return;
	}
	int c=0,i=0;
	char s[30];
	while(fscanf(fp,"%s",s)!=-1)
	{
		while(s[i])
		{
			c++;
			i++;
		}

		printf("%d ",c);
		c=0;
		i=0;
	}
printf("\n");
}













