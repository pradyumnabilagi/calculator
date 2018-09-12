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
    int g,kl,i,size;
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
        i=0;
        while(*(r+i)!='.')
        { 
            i++;
        }
        kl=i;
        g=0;
        while(*(r+g)=='0'&&g<kl-1)
        {
            g++;
        }
        i=0;
        
        size=strlen(r)-g+1;
        while(i<size)
        {
            *(r+i)=*(r+i+g);
            i++;
        }
        r=(char*)realloc(r,size*sizeof(char));
        
        i=0;
        while(*(r+strlen(r)-1-i)=='0')
        {
            i++;
        }
        size=strlen(r)+1-i;
        r=(char*)realloc(r,(strlen(r)+1-i)*sizeof(char));
        *(r+size-1)='\0';
        size=strlen(r)+1;
        if(*(r+size-2)=='.')
        {
            r=(char*)realloc(r,(size-1)*sizeof(char));
            *(r+size-2)='\0';
        }
    }
    else if(*chooser=='-')
    {
        r=sub(a,b);
    }
    printf("\n%s",r);
    getch();
    return 0;
}