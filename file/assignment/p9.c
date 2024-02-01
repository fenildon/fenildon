#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char **argv)
{
	if(argc!=4)
	{
		printf("usage:./a.out fname oldchar newchar\n");
		return;
	}
	FILE *fp,*buf;
	int i;
	char s[100];
	fp=fopen(argv[1],"r+");
	if(fp==0)
	{
		perror("fopen");
		return;
	}
	buf=fopen("buf","w+");

	while(fscanf(fp,"%s",s)!=-1)
	{
		if(strcmp(argv[2],s)==0)
			strcpy(s,argv[3]);
		if(fgetc(fp)=='\n')
			fprintf(buf,"%s\n",s);
		else		
			fprintf(buf,"%s ",s);
	}
if(fgetc(buf)!='\n')
{
fseek(buf,-1,SEEK_CUR);
	fputc('\n',buf);
}
	fp=fopen(argv[1],"w");
	rewind(buf);
	while(fgets(s,100,buf)!=0)
		fputs(s,fp);
}




