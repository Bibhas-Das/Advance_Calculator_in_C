
/*========================================================================================
                                  Postfix evaluation
  ========================================================================================*/
//       *** INPUT MUST INCLUDE A SINGLE SPACE BETWEEN EVERY OPAREND AND OPARATOR

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50

float stk[SIZE];
int top=-1;

void push(float);
float pop();
int get_type(char);

int main()
{
    char postfix[SIZE];
    int i;
    float len, val, opr1, opr2, res,cal=0,k=1,H1;
    int point=0;
    float point_value;

    printf("Enter the postfix expression : ");
    gets(postfix);


    len = strlen(postfix);

    float B[5];
    float value=0;
    for(i=0;i<len;i++)
    {
        switch(get_type(postfix[i]))
        {
            case 0:
                if(postfix[i]==' ' && cal!=0)
                { push(val);  cal=0;  break;}

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
       {

        val=point_value+(val/H1);

        point=0;
        break;
       }





            break;



            case -1: printf("%c",postfix[i]);
            break;



            case 1:

                opr1 = pop();
                opr2 = pop();
                int j;k=1;

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
                    k*=opr2;
                    res=k;
                    break;
                    case '!':
                    push(opr2);
                    for(j=opr1;j>=1;j--)
                    k*=j;
                    res=k;
                    break;
                }



                push(res);
        }






    }

    printf("\nRESULT = %.3f", stk[0]);
    return 0;
}
























void push(float a)
{
    if(top==SIZE-1)
    {
        printf ("Stack overflow error.");
        exit(1);
    }
    stk[++top] = a;
}

float pop()
{
    return(stk[top--]);
}

int get_type(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c=='^'||c=='!')
    return 1;
    if (c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c==' '||c=='.')
        return 0;
    else return -1;
}
