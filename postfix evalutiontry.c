#include<stdio.h>
#include<math.h>
#define STACK_SIZE 20

int stack[STACK_SIZE];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[20];
    char *e;
    int op1,op2,num,result;
    printf("Enter the expression : ");
    scanf("%s",&postfix);
    e = postfix;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;  //the digits have its ASCII code so to get its real value we sub by 48
            push(num);
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch(*e)
            {
            case '+':
            {
                result = op1 + op2;
                break;
            }
            case '-':
            {
                result = op1 - op2;
                break;
            }
            case '*':
            {
                result = op1 * op2;
                break;
            }
            case '/':
            {
                result = op1 / op2;
                break;
            }
            case '^':
            	result=pow(op1,op2);
            	break;
            }
            push(result);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",postfix,pop());
    return 0;
}
