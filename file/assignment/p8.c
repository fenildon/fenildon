//delet line
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage:./a.out filename\n");
		return;
	}
	int c=0,c1=0,t_line=0,i;
	char ch;
	FILE *fp=fopen(argv[1],"r");
	while((ch=fgetc(fp))!=EOF)
	{
		c++;	
		if(ch=='\n')
		{
			t_line++;
			if(c>c1)
				c1=c;
			c=0;
		}
	}

	char **buf,s[c1+1];
	buf=malloc(sizeof(*buf)*t_line);
	for(i=0;i<t_line;i++)
		buf[i]=malloc(sizeof(**buf)*c1+1);

	rewind(fp);
	i=0;
	while(fgets(buf[i],c1+1,fp)!=0)
	i++;
	
	for(i=0;i<t_line-1;i++)
		strcpy(buf[i],buf[i+1]);

fp=fopen(argv[1],"w");
for(i=0;i<t_line-2;i++)
fputs(buf[i],fp);

for(i=0;i<t_line;i++)
free(buf[i]);
free(buf);

}









