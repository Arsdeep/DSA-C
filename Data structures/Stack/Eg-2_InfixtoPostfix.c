// Infix = A*B/C+B*E
// Postfix = AB*C/BE*+

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    char *val;
    int top,size;
};

int precedence(char s)
{
    if(s == '*' || s == '/')
    return 2;
    if(s == '+' || s == '-')
    return 1;
    return 0;   
}

char *InfixToPostfix(char *st)
{
    int n,i,j,tmp;
    for(n = 0; st[n]!= '\0' ; n++);

    char *st2 =(char*) malloc(n*sizeof(char));

    struct stack s;
    s.val = (char*) malloc(n*sizeof(char));
    s.top = -1;

    for(i = 0 , j = 0; i<n ; i++)
    {
        tmp = precedence(st[i]);
        if(tmp)
        {
            if(s.top == -1)
            {
                s.val[++s.top] = st[i];
                continue;
            }
            else
            {
                if(precedence(s.val[s.top]) < tmp)
                    s.val[++s.top] = st[i];
                else
                {
                    while(s.top > -1)
                        st2[j++] = s.val[s.top--];

                    s.val[++s.top] = st[i];
                }
            }
        }
        else
        {
            st2[j++] = st[i];
        }
    }
    while(s.top > -1)
        st2[j++] = s.val[s.top--];
    st2[j++] = '\0';
    return st2;
}

void main()
{
    char st[255];
    char *st2;

    printf("Enter the expression - ");
    scanf("%s",st);

    st2 = InfixToPostfix(st);

    printf("\nPostfixed Expression - %s",st2);
}