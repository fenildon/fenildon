#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(int argc,char ** argv)
{
	if(argc!=2)
	{
		printf("usag:./a.out file\n");
		return;
	}
	FILE *fp;
	fp=fopen(argv[1],"r+");
	if(fp==0)
	{
		printf("file is not present\n");
		return;
	}
	int c=0,c1=0,i=0,j,k;
	char ch;
	while((ch=fgetc(fp))!=EOF)
	{
		c++;
		if(ch=='\n')
		{
			i++;
			if(c1<c)
				c1=c;
			c=0;
		}
	}
	rewind(fp);
	//printf("%d %d\n",i,c1);             //i is given number of line  , c1 is given largest line length
	char *p[i],*t;                        //array of pointer
	for(j=0;j<i;j++)                      //jetal bhi i hoi etli var loop farvu joie
		p[j]=malloc(c1+1);            //memory allocated kari
	for(j=0;j<i;j++)
		fgets(p[j],c1+1,fp);                  //line by line read karse
	printf("Before sorting....\n");
	for(j=0;j<i;j++)
		printf("%s",p[j]);

	//bubble sort method for sorting
	for(j=0;j<i-1;j++)                    
	{
		for(k=0;k<i-1-j;k++)
			if(strlen(p[k])>strlen(p[k+1]))
			{
				t=p[k];
				p[k]=p[k+1];
				p[k+1]=t;
			}
	}
	printf("After sorting....\n");
	for(j=0;j<i;j++)
		printf("%s",p[j]);
	rewind(fp);

	//write update data into file
	for(j=0;j<i;j++)
		fputs(p[j],fp);                //write a string
}




























