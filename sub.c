#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *sub(char *a,char *b)
{
    char *returnInt;
    char **r;
    char *store;
    r=understandstrings(a,b);
    a=*r;
    b=*(r+1);
    free(r);
    int i=0,size=0,g=0,p=0;
    if((*a!='-'&&*b!='-')||(*a=='-'&&*b=='-'))
    {
        if(*a=='-'&&*b=='-')
        {
            store=a;
            a=b;
            b=store;
        }

        
    }


}