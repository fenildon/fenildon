#include<ctype.h>
#include<stdio.h>
void pre_to_post(char *p);
int top=-1,stk[100];
void push(int num)
{
    stk[++top]=num;
}
int pop(void)
{
    return stk[top--];
}
void main()
{
    char s[50],*p=s,len=0;
    int n1,n2,digit=0;
    printf("enter  polish notation\n");
    scanf("%s",s);
    pre_to_post(s);
/*    while(s[len++]);

    while(*p)
    {
        if(isdigit(*p))
        {
            digit++;
             push(*p-48);
        }
        else
        {
            n2=pop();
            n1=pop();
            switch(*p)
            {
                case '+':push(n1+n2);break;
                case '-':push(n1-n2);break;
                case '*':push(n1*n2);break;
                case '%':push(n1%n2);break;
                case '/':push(n1/n2);
            }
            
        }
    p++;
    }
if(digit != (len-digit))
{
printf("provide proper rev polish notation\n");
return;
}*/
printf("reuslt of %s\n",s);
}

void pre_to_post(char *p)
{
    int i;
 char *q=p;
    while(*p)
    {
        if(isdigit(*p))
        {
            push(*p);
        }
        else
        {
          char  p1=pop();
           char p2=pop();
           char s[3]={*p,p2,p1}; 
            for(i=0;i<3;i++)
            {
                push(s[i]);
            }

        }
    p++;
    }

 while(top>=-1)
{
    *q++=pop();
}
*q=0;
}










