/*
@problem Main caluculator program for project 5
@author Beck Christensen
@starID rg6291gh
@duedate 3.19.2022
@instructor Jie Meichsner 
*/

#include <iostream>
#include<stdbool.h>
#include<string.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

//Stack initailisation
typedef struct{
int top;
int arr[50];
}Stack;

Stack s;
//stack push and pop function
void push(char item)
{
if(s.top >= 49)
{
return;
}
/*if(s.arr[s.top]>=0 && s.arr[s.top]<=9)
{
s.arr[s.top]*=10;
s.arr[s.top]+=item;
}*/
else
{
s.top = s.top+1;
s.arr[s.top] = item;
}
}

int pop()
{
int item ;
if(s.top <0)
{
exit(1);
}
else
{
item = s.arr[s.top];
s.top = s.top-1;
return(item);
}
}

// declare of class
class calculator{
private:
char infix[50]; //expression string
bool valid(char exp[]) //cheak expression well formed
{
for(int i=0;i<strlen(exp);i++)
{
char ch=exp[i];
if((is_operator(ch))!=1 && ch!='(' && ch!=')' && isdigit(ch)!=1)
return false;
}
return true;
}
bool valid_bracket(char exp[]) //cheak weather brackets are balanced
{
int flag=0;
for(int i=0;i<strlen(exp);i++)
{
if(exp[i]=='(')
flag++;
if(exp[i]==')')
flag--;
}
if(flag==0)
return true;
else
return false;
}
int precedence(char symbol) //precedence function
{
if(symbol == '*' || symbol == '/')
{
return(2);
}
else if(symbol == '+' || symbol == '-')
{
return(1);
}
else
{
return(0);
}
}
int is_operator(char symbol)
{
if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
{
return 1;
}
else
{
return 0;
}
}
void infixTopostfix(char *postfix) //function to convert infix to postfix
{
int i, j;
char item;
char x;

push('(');
strcat(infix,")");
i=0;
j=0;
item=infix[i];
while(item != '\0')
{
if(item == '(')
{
push(item);
}
else if( isdigit(item) || isalpha(item))
{
*(postfix+j) = item;
j++;
}
else if(is_operator(item) == 1)
{
x=pop();
while((is_operator(x) == 1) && (precedence(x)>= precedence(item)))
{
*(postfix+j) = x;
j++;
x =pop();
}
push(x);
push(item);
}
else if(item == ')')
{
x =pop();
while(x != '(')
{
*(postfix+j) = x;
j++;
x =pop();
}
}
else
{
exit(1);
}
i++;
item = infix[i];
}
if(s.top>0)
{
exit(1);
}
*(postfix+j)= '\0';
}
int evaluate() //evaluatig postfix expression
{
char postfix[50];
infixTopostfix(postfix);
s.top=-1;
for(int i=0;i<strlen(postfix);i++)
{
char ch=postfix[i];
if(ch>=48 && ch<=57)
{
int x=ch-'0';
push(x);
}
if(ch=='*' || ch=='/' || ch=='+' || ch=='-')
{
int a,b,value;
a=pop();
b=pop();
switch (ch) {
case '*':
value=b*a;
break;
case '/':
value=b/a;
break;
case '+':
value=b+a;
break;
case '-':
value=b-a;
break;
}
push(value);
}
}
return pop();
}
public:
calculator() //default constructor
{
return;
}
int calc(char exp[]) //function that set datamember and evaluates
{
char postfix[50];
if(valid(exp)==false){
printf("The entered expression is not well formed.\n");
return 0;
}
if(valid_bracket(exp)==false)
{
printf("The enterned expression's brackets are not balanced.\n");
return 0;
}
strcpy(infix,exp);
int result=evaluate();
return result;
}
};

int main()
{
int choice;
s.top=-1;
char exp[50];
calculator cal;
a:printf("Choices\n1:Enter '1' to Evaluate a expression\n2:Enter any other number Quit\n" );
printf("Enter your choice:");
scanf("%d",&choice);
if(choice==1)
{
int result;
printf("Enter the expression\n");
scanf("%s",exp);
result=cal.calc(exp);
if(result==0)
{
goto a;
}
printf("*************%s=%d*****************\n\n\n\n",exp,result);
goto a;
}
else
{
return 0;
}
}