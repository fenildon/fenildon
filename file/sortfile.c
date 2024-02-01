#include<stdio.h>
#include<string.h>
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage:./a.out filename\n");
		return;
	}
	FILE *fp=fopen(argv[1],"r");
	int t_line=0;
	char ch;
	//printf("%d\n",t_line);
	int c=0,c1=0;
	while((ch=fgetc(fp))!=EOF)//fonding bigest line
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

//	printf("%d\n",t_line);
	rewind(fp);
	char s[c1+1];
//	while(fgets(s,c1+1,fp)!=0)//findind total how much line is present in file
//		t_line++;
	rewind(fp);
	char buf[t_line][c1+1];//creating 2d arrray to store stirng

	int i=0,j;
	while(fgets(s,c1+1,fp)!=0)//sotring file data in 2d array
	{
		strcpy(buf[i],s);
		i++;
	}

	for(i=0;i<t_line-1;i++)//bubble sort logic
	{
		for(j=0;j<t_line-1-i;j++)
		{
			if(strlen(buf[j])>strlen(buf[j+1]))
			{
				strcpy(s,buf[j]);
				strcpy(buf[j],buf[j+1]);
				strcpy(buf[j+1],s);
			}
		}
	}

fp=fopen(argv[1],"w");

for(i=0;i<t_line;i++)
fputs(buf[i],fp);


}




