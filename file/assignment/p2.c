#include<stdio.h>
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage:./a.out filename\n");
		return;
	}
	FILE *fp=fopen(argv[1],"r+");
	if(fp==0)
	{
		perror("fopen");
		return;
	}
	char ch;
	while((ch=fgetc(fp))!=EOF)
	{
                if(ch>='a' && ch<='z')
		{
			fseek(fp,-1,SEEK_CUR);
			ch=ch^32;
			fputc(ch,fp);
		}
	}
}
