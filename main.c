#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


char **understandstrings(char *a,char* b);
char *add(char *a,char *b);
char *sub(char *a,char *b);
char *multiplication(char *a,char *b);

int main()
{
    char *a;
    char *b;
    char *r;
    a=(char*)malloc(15*sizeof(char));
    b=(char*)malloc(15*sizeof(char));
    scanf("%s%s",a,b);
    r=multiplication(a,b);
    printf("\n%s",r);
    return 0;
}