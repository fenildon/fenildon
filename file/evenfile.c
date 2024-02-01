#include<stdio.h>
#include<string.h>
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("./a.out filename\n");
		return;
	}
	FILE *fp=fopen(argv[1],"r");
	if(fp==0)
	{
		perror("fopen");
		return;
	}
	//////////////////////finding big line
	int c=0,c1=0;
	char ch;
	while((ch=fgetc(fp))!=EOF)
	{
		c++;
		if(ch=='\n')
		{
			if(c>c1)
				c1=c;
			c=0;
		}
	}
	rewind(fp);
	char s[c1+1];
	int len;
	FILE *fp1=fopen("file","w");
	while(fgets(s,c1+1,fp))
	{
		len=strlen(s);
		if(len%2==1)
		fputs(s,fp1);
		
	}
}
