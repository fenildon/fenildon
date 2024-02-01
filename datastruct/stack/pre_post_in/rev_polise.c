#include<ctype.h>
#include<stdio.h>
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
    printf("enter reverse polish notation\n");
    scanf("%s",s);
    while(s[len++]);

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
}
printf("reuslt of %s = %d\n",s,pop());
}










