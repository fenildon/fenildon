#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char**argv)
{
if(argc!=4)
{
printf("usage:./a.out filename oldword newword\n");
return;
}
	FILE *fp=fopen("data","r+");
if(fp==0)
{
perror("fopen");
return;
}
	char *p,*buf,ch;
	int len=0,i,i1,i2,k,j;

	while(fgetc(fp)!=EOF)//finding file size
		len++;
	rewind(fp);
	buf=malloc(len+100);//memory allocate for filesize

	i=0;
	while((ch=fgetc(fp))!=EOF)//copy all file contaoin on buffer
		buf[i++]=ch;
	buf[i]='\0';
	char *str,*space;
	str=buf;//str pointer is pointing to buffer
	int oldlen=strlen(argv[2]);//finding old word length
	int newlen=strlen(argv[3]);//finding new word length
	if(oldlen==newlen)//if both word size is same
	{
		while(str=strstr(str,argv[2]))//finding oldword buffer if word not found it will retrun zero
		{
			for(i=0;i<oldlen;i++)//copy new word insted of old word
				str[i]=argv[3][i];
			str=str+1;
		}
	}
	else if(oldlen>newlen)//if oldword is bigger and newword is smaller
	{
		while(str=strstr(str,argv[2]))
		{
			for(i=0;i<newlen;i++)
				str[i]=argv[3][i];
			for(k=i;k<oldlen;k++)//data over write
				for(j=i;str[j];j++)      
					str[j]=str[j+1];
			str=str+1;
		}
	}
	else if(oldlen<newlen)//if new word is big compare to old
	{
		while(str=strstr(str,argv[2]))
		{
			i2=newlen-oldlen;
			i1=strlen(str);
			for(i1;i1>=0;i1--)//creating space for fit word
				str[i1+i2]=str[i1];
			for(i=0;i<newlen;i++)//puting new word in buf 
				str[i]=argv[3][i];
			
			str=str+1;
		}
	}
	fp=fopen("data","w");//opend data file in write mode
	for(i=0;buf[i];i++)//puting contaion of buffer in data file
		fputc(buf[i],fp);
}

































