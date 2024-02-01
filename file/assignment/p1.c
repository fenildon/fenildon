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
	char ch,s[30];
	int line=0,word=0,c=0,digit=0;
	while((ch=fgetc(fp))!=EOF)
	{
		c++;
		if(ch=='\n')
			line++;
	if(ch>='0' && ch<='9')
	digit++;
	}
rewind(fp);
     
while(fscanf(fp,"%s",s)!=-1)
word++;



	printf("line=%d word=%d char=%d digit=%d filename=%s\n",line,word,c,digit,argv[1]);
}















