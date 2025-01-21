/* Program : Simple calculator 
 * programmer : Bibhas Das
 * Last Update : 4 Nov 2024
 */


#include <stdio.h>
#include <stdlib.h>


int isOperand(char ch)
{
	return (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9'))?1:0;
}

size_t factorial(size_t num)
{
	return (!num)?1:factorial(num-1)*num;
}

double power(double base, double exp)
{
	double pow = 1;
	for(double i=0; i<exp; i++)
	pow *= base;

	return pow;
}

char * infix_postfix(char *infix)
{
	int stack_index = 0, postfix_index = 0;
	char *stack = (char*)malloc(sizeof(char) * (stack_index+1));
	char *postfix = (char*)malloc(sizeof(char) * (postfix_index+1));

	stack[stack_index++] = '\0';

	for(int i=0; infix[i]!='\0'; i++)
	{
		char ch = infix[i];

		if(isOperand(ch))
		{
			postfix = (char*)realloc(postfix,sizeof(char) * (postfix_index+1));
			postfix[postfix_index++] = ch;
			if(!isOperand(infix[i+1]))
			{
				postfix = (char*)realloc(postfix,sizeof(char) * (postfix_index+1));
				postfix[postfix_index++] = ' ';
			}
		}
		else if(ch == '(' || ch == '{' || ch == '[')
		{
			stack = (char*)realloc(stack,sizeof(char) * (stack_index+1));
			stack[stack_index++] = ch;
		}
		else if(ch == ')')
		{
			int j = 1;
			while(stack[stack_index - j] != '(')
			{	
				postfix = (char*)realloc(postfix,sizeof(char) * (postfix_index+1));
				postfix[postfix_index++] = stack[stack_index-j];
				j++;
				//free(stack[stack_index+1]);
			}
			stack_index -= j;
		}

		else if(ch == '}')
		{
			int j = 1;
			while(stack[stack_index - j] != '{')
			{	
				postfix = (char*)realloc(postfix,sizeof(char) * (postfix_index+1));
				postfix[postfix_index++] = stack[stack_index-j];
				j++;
				//free(stack[stack_index+1]);
			}
			stack_index -= j;
		}

		else if(ch == ']')
		{
			int j = 1;
			while(stack[stack_index - j] != '[')
			{	
				postfix = (char*)realloc(postfix,sizeof(char) * (postfix_index+1));
				postfix[postfix_index++] = stack[stack_index-j];
				j++;
				//free(stack[stack_index+1]);
			}
			stack_index -= j;
		}
		else if(ch == '+' || ch == '-')
		{
			if(stack[stack_index-1] == '+' || stack[stack_index-1] == '-')
			{
				postfix  = (char*)realloc(postfix,sizeof(char*) * (postfix_index+1));
				postfix[postfix_index++] = stack[stack_index-1];
				stack[stack_index-1] = ch;
			}
			else
			{
				int j=1;
				while(stack[stack_index - j] == '+' || stack[stack_index - j] == '-'|| stack[stack_index - j] == '*' || stack[stack_index - j] == '/' || stack[stack_index - j] == '!' || stack[stack_index - j] == '^' || stack[stack_index - j] == '%' )
				{
					postfix  = (char*)realloc(postfix,sizeof(char*) * (postfix_index+1));
					postfix[postfix_index++] = stack[stack_index-j];
					j++;

				}
				stack_index -= j-1;
				stack = (char*)realloc(stack,sizeof(char) * (stack_index+1));
				stack[stack_index++] = ch;

			}
		}
		else if(ch == '*' || ch == '/')
		{
			if(stack[stack_index-1] == '*' || stack[stack_index-1] == '/')
			{
				postfix  = (char*)realloc(postfix,sizeof(char*) * (postfix_index+1));
				postfix[postfix_index++] = stack[stack_index-1];
				stack[stack_index-1] = ch;
			}
			else
			{
				int j=1;
				while(stack[stack_index - j] == '*' || stack[stack_index - j] == '/'|| stack[stack_index - j] == '!' || stack[stack_index - j] == '^' || stack[stack_index - j] == '%' )
				{
					postfix  = (char*)realloc(postfix,sizeof(char*) * (postfix_index+1));
					postfix[postfix_index++] = stack[stack_index-j];
					j++;

				}
				stack_index -= j-1;
				stack = (char*)realloc(stack,sizeof(char) * (stack_index+1));
				stack[stack_index++] = ch;

			}

		}
		else if(ch == '!' || ch == '^' || ch == '%')
		{
			if(stack[stack_index-1] == '!' || stack[stack_index-1] == '^' || stack[stack_index-1] == '%' )
			{
				postfix  = (char*)realloc(postfix,sizeof(char*) * (postfix_index+1));
				postfix[postfix_index++] = stack[stack_index-1];
				stack[stack_index-1] = ch;
			}
			else
			{
				stack = (char*)realloc(stack,sizeof(char) * (stack_index+1));
				stack[stack_index++] = ch;
			}

		}

		/*
		printf("\nchar : %c",infix[i]);
		printf("\tStack : ");
		for(int i = 0; i<stack_index; i++)printf("%c",stack[i]);
		printf("\tPostfix : ");
		for(int i = 0; i<postfix_index; i++)printf("%c",postfix[i]);
		*/
	}


	while(stack_index)
	{
		postfix  = (char*)realloc(postfix,sizeof(char*) * (postfix_index+1));
		postfix[postfix_index++] = stack[--stack_index];
	}

	if(postfix_index)
	{
		postfix = (char*)realloc(postfix,sizeof(char) * (postfix_index+1));
		postfix[postfix_index++] = '\0';
	}

	//printf("\n\nOutput is : %s\n",postfix);
	return postfix;
}




double postfix_evaluation(char *postfix)
{
	double *result = (double*)malloc(sizeof(double));
	int index = 0;
	int flag_num = 1;

	for(int i=0; postfix[i]!='\0'; i++)
	{
		char ch = postfix[i];
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
		{
			double num1 = result[index-1];
			double num2 = result[index-2];
			double num3;
			switch(ch)
			{
				case '+':num3 = num2 + num1; break;
				case '-':num3 = num2 - num1; break;
				case '*':num3 = num2 * num1; break;
				case '/':num3 = (!num1)?printf("\nundefined"):num2 / num1; break;
				case '^':num3 = power(num2,num1); break;
				case '%':num3 = (long)num2 % (long)num1; break;
			}
			result[index-2] = num3;
			index--;
		}
		else if(ch == '!')
		{
			result[index-1] = factorial(result[index-1]);
		}
		else
		{
			if(flag_num)
			{
				result = (double*)realloc(result,sizeof(double)*(index+1));
				result[index++] = (double)(ch - '0');
				flag_num = 0;
			}
			else
			{
				if(ch == ' ' )
				{
					flag_num = 1;
					continue;
				}
				result[index-1] = (result[index-1] * 10) + (double)(ch - '0');
			}
		}
	}
	//printf("\nResult : %lf",result[0]);
	return result[0];
}



char * checkInfix(int args,char *infix)
{
	if(args == 2)
	{
	char *input = (char*)malloc(sizeof(char));
	int index = 0;
	for(int i=0; infix[i]!='\0';i++)
	{
		char ch = infix[i];
		if((ch >= '0' && ch <= '9') || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '!' || ch == '%' )
		{
			input = (char*)realloc(input, sizeof(char) * (index+1));
			input[index++] = infix[i];
		}
	}
	input = (char*)realloc(input, sizeof(char) * (index+1));
	input[index++] = '\0';

	return input;
	}
	else
		return " ";
}




void main(int args, char **infix)
{
	printf("> %lf\n",postfix_evaluation(infix_postfix(checkInfix(args,infix[1]))));
}
