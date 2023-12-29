#include<stdio.h>
#include<string.h>
#include<stdlib.h>
extern char *q;
void include_header()/////////////////Include header file//////////////////////////////////////////// 
{
	int i,j,k,l1,l2;
	char s[30]="/usr/include/", head[30];
	char b[20],x[]="#include",*o;
	l2=strlen(q);
	char *temp;
	temp=malloc(sizeof(char)*l2);
	strcpy(temp,q);//copy main buffer q in temp buffer
l1:
///////////////////////////////Finding header file name ////////////////////////////////////////////
o=temp;
	if(o=strstr(o,x))
	{

		for(i=0;o[i]!='\n';i++)
		{
			if(o[i-1]=='<')//saving predefind header file name
			{
				for(j=i,k=0;o[j]!='>';j++,k++)
					b[k]=o[j];
				b[k]=0;
				strcpy(head,s);
				strcat(head,b);//creating path for file
			}
			else if(o[i-1]=='"')//Saving user defined header file name
			{
				for(j=i,k=0;o[j]!='"';j++,k++)
					b[k]=o[j];
				b[k]=0;
				strcpy(head,b);
			}
		}
	}
	else
		return;
	if(o=strstr(o,x))//deleting line form temp buffer in which header file  name present
	{
		for(i=0;o[i]!='\n';i++)
			o[i]=' ';
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////
	o=q;
	while(o=strstr(o,x))//deleting line from main buffer q in while header file name present
	{
		for(i=0;o[i]!='\n';i++)
			o[i]=' ';
	}
/////////////////////////////////////////////////////////////////////////////////////////////////
	FILE *fp;
	fp=fopen(head,"r");//Opening header file

	char ch,*h;
	int c=0;
	while((ch=fgetc(fp))!=EOF)
		c++;//counting header file character

	rewind(fp);
	l1=strlen(q);//finding length of main buffer

	h=malloc(sizeof(char)*(c+l1));//allocating DM for h buffer

	i=0;
	while((ch=fgetc(fp))!=EOF)
		h[i++]=ch;//coping header data in h buffer
	h[i]=0;
	strcat(h,q);//concate header and main buffer in h buffer
	q=realloc(q,(c+l1));//reallocate memory for main buffer q
	strcpy(q,h);//copy h buffer to main buffer
	free(h);//free h buffer
	fclose(fp);//close header
	o=temp;	
	if(o=strstr(o,x))//if #include available then include other header again
		goto l1;
}


