#include"header.h"

void macro(char *a)
{
	char old[50],new[50],*z;
	int i,j,k,x,olength=0,nlength=0,i1=0,i2=0;
l1:
	if(z=strstr(a,"#define"))//if #define found
	{
		for(i=0;z[i]!=' ';i++);//travel upto first space
		for(j=i+1,x=0;z[j]!=' ';j++,x++)//save macro name in old buffer
			old[x]=z[j];
		old[x]=0;

		for(k=j+1,x=0;z[k]!='\n';k++,x++)//save macro body in new buffer
			new[x]=z[k];
		new[x]=0;
	}

	if(z=strstr(a,"#define"))//if #define found
	{
		for(i=0;z[i]!='\n';i++)//remove line in which #define is present
			z[i]=' ';
	}

	z=a;
	olength=strlen(old);//finding lenth of macro name
	nlength=strlen(new);//finding length of macro body
	if(olength==nlength)//replace word for lenth of old==new
	{
		while(z=strstr(z,old))
		{
			for(olength=0;olength<nlength;olength++)
				z[olength]=new[olength];
			z=z+1;
		}
	}
	else if(olength>nlength)//replace word for length of old>new
	{
		while(z=strstr(z,old))
		{
			for(i1=0;i1<olength;i1++)
			{
				if(i1<nlength)
					z[i1]=new[i1];
				else
					z[i1]=' ';
			}
			z=z+1;
		}
	}
	else if(olength<nlength)//replace word for length of old<new
		{
			i2=nlength-olength;
			while(z=strstr(z,old))
			{
				i1=strlen(z);
				for(i1;i1>=0;i1--)
					z[i1+i2]=z[i1];
				for(olength=0;olength<nlength;olength++)
					z[olength]=new[olength];
				z=z+1;
			}
		}
		if(strstr(a,"#define"))//if still #define is present in file 
			goto l1;//then repeat again
	
}
