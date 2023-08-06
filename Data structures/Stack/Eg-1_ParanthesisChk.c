// Checking Parenthesis using Stack

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int *val,top,size;
};

int paranthesischeck(char *st)
{
    struct stack s;
    for(s.size = 0; st[s.size] != '\0';s.size++);
    s.val =(int*) malloc(sizeof(int)*s.size);
    s.top = -1;

    for(int i = 0; i<s.size ; i++)
    {
        switch(st[i])
        {
            case '[' : s.val[++s.top] = 3; break; 
            case '{' : s.val[++s.top] = 2; break;
            case '(' : s.val[++s.top] = 1; break;
            
            // Use this in case you want to check paranthesis priority too
            //case '[' : if(s.val[s.top] >= 3) s.val[++s.top] = 3; break;
            //case '{' : if(s.val[s.top] >= 2) s.val[++s.top] = 2; break;
            //case '(' : if(s.val[s.top] >= 1) s.val[++s.top] = 1; break;
            
            case ']' : if(s.val[s.top] == 3) s.top--; else return 0; break;
            case '}' : if(s.val[s.top] == 2) s.top--; else return 0; break;
            case ')' : if(s.val[s.top] == 1) s.top--; else return 0; break;
        }
    }
    if(s.top == -1)
    return 1;
    return 0;
}

void main()
{
    char st[255];

    printf("Enter the expression - ");
    scanf("%s",st);

    if(paranthesischeck(st))
        printf("Paranthesis Matches");
    else
        printf("Parenthesis Does NOT Match");
}