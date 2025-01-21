#include<stdio.h>
#include<string.h>
#include <ctype.h>

int stk[100];
int top=-1;
int flag=0;

void push(int);
int pop();


int main()
{
    char postfix[100];
    int len, val, i, opr1, opr2, res;
    printf("Enter the postfix expression (put space between each operand and operator): ");
    gets(postfix);
    len = strlen(postfix);

    for(i=0;i<len;i++)
    {

        if(isdigit(postfix[i]))
            push(postfix[i]-'0');
        else if(postfix[i]==' ')
            flag=0;
        else
        {
            flag=0;
            opr1 = pop();
            opr2 = pop();

            switch(postfix[i])
            {
                case '+':
                res = opr2 + opr1;
                break;
                case '-':
                res = opr2 - opr1;
                break;
                case '*':
                res = opr2 * opr1;
                break;
                case '/':
                res = opr2 / opr1;
                break;
                case '%':
                res = opr2 % opr1;
                break;
            }

                push(res);
         }
    }

    printf("RESULT = %d", stk[0]);
    return 0;
}


void push(int val)
{
    if(flag==1){
    int num;
    num=pop();
    stk[++top]=val+10*num;
  }
  else if(flag==0){
    stk[++top]=val;
    flag=1;
  }
}

int pop()
{
    return(stk[top--]);
}

