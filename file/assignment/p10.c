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
	char s[20];
	int i;
	while(fscanf(fp,"%s",s)!=-1)
	{
		for(i=0;s[i];i++);//dummy loop finding string len
	
                        if(s[0]>='a' && s[0]<='z')//if first char is small 
			s[0]=s[0]^32;
			if(s[i-1]>='a' && s[i-1]<='z')//if last char is small
			s[i-1]=s[i-1]^32;
			fseek(fp,-i,SEEK_CUR);
			fprintf(fp,"%s",s);
	
	}
}








