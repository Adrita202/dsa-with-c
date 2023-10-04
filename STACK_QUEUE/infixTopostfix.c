#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stk[MAX];
char infix[MAX];
char postfix [MAX];
int top=-1;
void push(char);
void pop();
int precedence(char);
int main()
{
	printf("Enter the infix expression: ");
	gets(infix);
	convert_inToPost();
	display();
	
}
void convert_inToPost()
{
	int i,j=0;
	char symbol,next;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		switch(symbol)
		{

		case '(':
			push(symbol);
			break;
		case ')':
			while((next == pop())!=='(')
				postfix[j++]=next;
			break;
		case'+':
		case'-':
		case'*':
		case'/':
			while(!isempty() && precedence(stk[top]) >= precedence(symbol))
				postfix[j++]=pop();
			push(symbol);
			break;
		default:
			postfix[j++]=symbol;
		}
	}
	while(!isEmpty())
	{
		postfix[j++]=pop();
	postfix[j]='\0';
	}
}
int isEmpty()
{
	return top==-1;
}
int isFull()
	{
		return top==MAX-1;
	}
	void push( char e)
	{
		if(isFull())
		{
			printf("Stack Overflow");
		}
		else
			stk[++top]=e;
	}
	char pop()
	{
		char temp;
		if(isEmpty())
		{
			printf("Stack underflow");
			exit(0);
		}
		temp=stk[top--];
		return temp;
	}
	void display()
	{
		int i;
		printf("The postfix expression is:\n");
		while(postfix[i])
		{
			printf("c",postfix[i]);
		}
	}
int precedence(char symbol)
{
	switch(symbol)
	{
		case'^':
			return 3;
		case'/':
		case'*':
			return 2;
		case'+':
  		case'-':
  			return 1;
		default:
			return 0;
	}
}








