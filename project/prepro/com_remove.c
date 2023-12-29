
//comment removal
#include<stdio.h>
#include<string.h>

void com_rmv(char *s)
{
	int i,j,k;
	for(i=0;s[i];i++)
	{
		if(s[i]=='/' && s[i+1]=='/')// (finding //)
		{
			for(j=i;s[j]!='\n';j++)//Removing singal line comment with spaces
				s[j]=' ';
		}

		if(s[i]=='/' && s[i+1]=='*')// (finding /*)
		{
			for(k=i;s[k];k++)
			{
				if((s[k]=='*')&&(s[k+1]=='/'))// (if */ found)
				{
					s[k]=s[k+1]=' ';// putting spaces at last where */ found
					break;
				}
				if(s[k]=='\n')
					continue;
				s[k]=' ';// removing multiline comment with spaces
			}
		}
	}
}









