#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int top = -1;
int stk[MAX];

int isfull()
{
	return top == MAX-1;
}

int isempty()
{
	return top==-1;
}

void push(int e)
{
	if(isfull())
	{
		printf("Stack overflow!!");
		exit(0);
	}
	stk[++top] = e;
}

int pop()
{
	if(isempty())
	{
		printf("Stack underflow!!");
		exit(0);
	}
	return stk[top--];
}

int isOperator(char e)
{
	return e == '+' || e == '-' || e == '*' || e == '/';
}

int evaluate(char o,int a,int b)
{
	if(o == '+')
		return a+b;
	else if(o == '-')
		return a-b;
	else if(o == '*')
		return a*b;
	else if(o == '/')
		return a/b;
}

int main()
{
	char pre[MAX];
	int i,len,a,b,result;

	printf("Enter the prefix expression : ");
	gets(pre);

	for(len=0;pre[len]!='\0';len++);

	for(i=len-1;i>=0;i--)
	{
		if(pre[i] == ' ')
			continue;
		if(!isOperator(pre[i]))
		{
			push(pre[i]-48); // To convert ACSII value of digits to it's actual value. For example 50-48 = 2, here 50 is ASCII of '2'.
		}
		else
		{
			a = pop();
			b = pop();
			push(evaluate(pre[i],a,b));

		}
	}

	result = pop();
	printf("The evaluated prefix expression is : %d",result);
}
