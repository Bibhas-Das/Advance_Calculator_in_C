#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 50


//Defenitions of the function
void push(int);
int pop();
int precedence(char);
int empty();
int top_element();
void infix_to_postfix(char [],char []);
void pushh(float);
float popp();
int get_type(char);
void evaluate(char []);///////////

//The Global variables with their globaly declared value
int stack[SIZE];
int top = -1;
float stk[SIZE];

//Main function
void main()
{
    char infix[30],postfix[30];
    printf(">> ");
    gets(infix);
    infix_to_postfix(infix,postfix);
    //printf("\nPostfix expression: %s\n",postfix);
    evaluate(postfix);
    getch();
}

//It will push the element to the stack
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
//It will pop the charater from the stack
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
//It will give the value according the oparend's precedence
int precedence(char x)
{
    if(x=='(')
        return(0);
    if(x=='+'||x=='-')
        return(1);
    if(x=='*'||x=='/'||x=='%'||x=='!')
        return(2);

    return(3);
}
//If the stack is empty then It will return the 1 otherwise it will return 0
int empty()
{
    if(top==-1)
        return(1);

    return(0);
}
//It will give the toppest element in the stack
int top_element()
{
    return (stack[top]);
}

//This function will make an infix notation to post fix notetion.
//it can get inputs in integer,charater,float, and also can give the out-put in integer charater and float value..

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
                 push(token); }}

    while(!empty())
    {
        x=pop();
        postfix[j++]=' ';
        postfix[j++]=x;
    }

    postfix[j]='\0';
}
//This function will get the postfix value and calculate this and give the actual value in integer or float value
void evaluate(char a[])
{
    char postfix[SIZE];
    int i;
    float len, val, opr1, opr2, res,cal=0,k=1,H1;
    int point=0;
    float point_value;
    strcpy(postfix,a);
    len = strlen(postfix);
    float B[5];
    float value=0;
    for(i=0;i<len;i++)
    {
        switch(get_type(postfix[i]))
        {
case 0:
                if(postfix[i]==' ' && cal!=0)
                { pushh(val);  cal=0;  break;}

                if(postfix[i]==' '&&cal==0)
                break;

                cal++;

           if(postfix[i]=='.')
           {   int i;
            point=1;
            point_value=val;
            cal=0;
            break;
           }

            val = postfix[i] - '0';

            B[5]=B[4];  B[4]=B[3]; B[3]=B[2]; B[2]=B[1]; B[1]=B[0]; B[0]=val;

            if(cal==1)
                {val=B[0]; H1=10;}
            if(cal==2)
                {val=(B[1]*10)+B[0]; H1=100;}
            if(cal==3)
               {val=(B[2]*100)+(B[1]*10)+B[0]; H1=1000;}
            if(cal==4)
                {val=(B[3]*1000)+(B[2]*100)+(B[1]*10)+B[0]; H1=10000;}
            if(cal==5)
                {val=(B[3]*10000)+(B[2]*1000)+(B[1]*100)+(B[1]*10)+B[0]; H1=100000;}

                if(point==1&&postfix[i+1]==' ')
              { val=point_value+(val/H1);
                point=0;
                break;}

                break;



case -1:        system("msg * ERROR");
                break;

case 1:

                opr1 = popp();
                opr2 = popp();
                int j; k=1;
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
                    res = (int)opr2 % (int)opr1;
                    break;
                    case '^':
                    for(j=1;j<=opr1;j++)
                   { k*=opr2;}
                    res=k;
                    break;
                    case '!':
                    push(opr2);
                    for(j=opr1;j>=1;j--)
                    {k*=j;}
                    res=k;
                    break;}
                    pushh(res);}}
        printf("\n>> %.3f", stk[0]);
}
//This function will push the value into stack for excute
void pushh(float a)
{
    if(top==SIZE-1)
    {
        printf ("Stack overflow error.");
        exit(1);
    }
    stk[++top] = a;
}
//This function will pop up the value from the stack that will be give the actual calculate value
float popp()
{
    return(stk[top--]);
}
///if input charaters ar numbers or oparators then this function return only o Or 1 , Otherwise it will return -1
int get_type(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c=='^'||c=='!')
    return 1;
    if (c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c==' '||c=='.')
    return 0;
    else return -1;
}



