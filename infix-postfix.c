


/*===================================================================================
                             Infix to Postfix conversion
===================================================================================*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define SIZE 50

void push(int);
int pop();
int precedence(char);
int empty();
int top_element();
void infix_to_postfix(char [],char []);

int stack[SIZE];
int top = -1;



void main()
{
    char infix[30],postfix[30];
    printf("Enter an infix expression(eg: 5+2*4): ");
    gets(infix);
    infix_to_postfix(infix,postfix);
    printf("\nPostfix expression: %s",postfix);
}












void push(int x)
{
    if(top==SIZE-1)
    {
        printf ("Stack overflow error.");
        exit(1);
    }

    top=top+1;
    stack[top]=x;
}

int pop()
{

     if (top==-1)
     {
        printf ("Stack underflow error");
        exit(1);
     }

    else
    {
        int x;
        x=stack[top];
        top=top-1;
        return(x);
    }

}

int precedence(char x)
{
    if(x=='(')
        return(0);
    if(x=='+'||x=='-')
        return(1);
    if(x=='*'||x=='/'||x=='%')
        return(2);

    return(3);
}


int empty()
{
    if(top==-1)
        return(1);

    return(0);
}



int top_element()
{
    return (stack[top]);
}


void infix_to_postfix(char infix[],char postfix[])
{
    char x,token;
    int i,j=0;

    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalnum(token)||token=='.')
            postfix[j++]=token;
        else
            if(token=='(')
               push('(');
        else
            if(token==')')
                while((x=pop())!='(')
                { postfix[j++]=' ';
                      postfix[j++]=x;  }
                else
                {    postfix[j++]=' ';
                    while(precedence(token)<=precedence(top_element()) && !empty())
                    {
                        x=pop();
                        postfix[j++]=x;
                        postfix[j++]=' ';
                    }

                    push(token);

                }
      }

    while(!empty())
    {
        x=pop();
        postfix[j++]=' ';
        postfix[j++]=x;
    }

    postfix[j]='\0';
}

