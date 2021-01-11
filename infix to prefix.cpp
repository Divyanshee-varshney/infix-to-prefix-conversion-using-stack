#include<stdio.h>
#include<ctype.h>
#include<string.h>
char stack[20];
int top=-1;
void push(char x)
{
	stack[++top]=x;
	
}
char pop()
{
	if(top==-1)
	return -1;
	else
	{
		return stack[top--];
	}
}
int priority(char x)
{
	if(x=='(')
	return 0;
    if(x=='+' || x=='-')
    return 1;
    if(x=='*'|| x=='/')
    return 2;
    
}
void display(char expr[])
{
     int size=strlen(expr);
	for(int i=size-1;i>=0;i--)
	printf("%c",expr[i]);
	
}
int main()

{
	char exp[20];
	char expr[20];
	char exp1[20];

	printf("\nEnter infix expression : ");
	scanf("%s",exp);
	int length=strlen(exp);
	for(int i=0;i<length;i++)
	{
		if(exp[i]=='(')
		exp1[length-i-1]=')';
		else if(exp[i]==')')
		exp1[length-i-1]='(';
		else
		exp1[length-i-1]=exp[i];

		
	}
    int i=0;
	char *e,x;
	e=exp1;
    while(*e!='\0')
	{
		if(isalnum(*e))
		{
		expr[i]=*e;
		i++;
		}
		else if(*e=='(')
		{
			push(*e);
		}
		else if(*e==')')
		{
			while((x=pop())!='(')
			{
				expr[i]=x;
		        i++;		
			}
		}
		else
		{
			while(priority(stack[top])>=priority(*e))
			{
				expr[i]=pop();
				i++;
			}
			push(*e);
		}
		e++;
	
	}
	while(top!=-1)
	{
		expr[i]=pop();
		i++;
	}
	display(expr);


}
