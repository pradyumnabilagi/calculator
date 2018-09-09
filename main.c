#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"project.h"



int main()
{
    char *a;
    char *b;
    char *r;
    char *chooser;
    chooser=(char*)malloc(2*sizeof(char));
    a=(char*)malloc(15*sizeof(char));
    b=(char*)malloc(15*sizeof(char));
    printf("enter the two numbers\n");
    scanf("%s%s",a,b);
    printf("choose which operation\nfor division enter '/'\nfor multiplication enter '*'\nfor addition enter '+'\nfor substraction enter '-'\n");
    scanf("%s",chooser);
    if(*chooser=='/')
    {
        r=division(a,b);
    }
    else if(*chooser=='*')
    {
        r=multiplication(a,b);
    }
    else if(*chooser=='+')
    {
        r=add(a,b);
    }
    else if(*chooser=='-')
    {
        r=sub(a,b);
    }
    printf("\n%s",r);
    return 0;
}