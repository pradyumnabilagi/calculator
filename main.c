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
    a=(char*)malloc(15*sizeof(char));
    b=(char*)malloc(15*sizeof(char));
    scanf("%s%s",a,b);
    r=division(a,b);
    printf("\n%s",r);
    return 0;
}