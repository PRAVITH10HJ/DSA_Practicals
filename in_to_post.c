#include<stdio.h>
#include<ctype.h>
#define size 20
char s[size];
int top=-1;
void push(char elem){
s[++top]=elem;
}
char pop(){
return(s[top--]);
}
int presedence(char elem){
switch(elem)
{
case '#':return 0;
case '(':return 1;
case '+':
case '-':return 2;
case '*':
case '/':
case '%':return 3;
case '$':
case '^':return 4;
}
return elem;
}
void main()
{
char infix[50],postfix[50],ch,elem;
int i=0,k=0;
printf("\n  enter teh infix expresssion");
scanf("%s",infix);
push('#');
while ((ch=infix[i++])!='\0')
{
if (ch=='(')
push(ch);
else if (isalpha(ch))
postfix[k++]=ch;
else if(ch==')')
while(s[top]!='(')
{
postfix[k++]=pop();
elem=pop();
}
else
{
while(presedence(s[top])>=presedence(ch))
postfix[k++]=pop();
push(ch);
}
}
while(s[top]!='#')
{
postfix[k++]=pop();
}
postfix[k]='\0';
printf("\n the infix is %s",infix);
printf("\n the postfix is %s\n",postfix);
}
