#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"project.h"


char *multiplication(char *a,char *b)
{
    int i=0,size=0,g=0,p=0,t=0,k=0;
    char *returnInt;
    char *conserve;
    char **r;
    if((*a!='-'&&*b!='-')||(*a=='-'&&*b=='-'))
    {
        if(*a=='-'&&*b=='-')
        {
            i=0;
            g=strlen(a)+1;
            while(i<g-1)
            {
                *(a+i)=*(a+i+1);
                i++;
            }
            a=(char*)realloc(a,(g-1)*sizeof(char));
            
            i=0;
            g=strlen(b)+1;
            while(i<g-1)
            {
                *(b+i)=*(b+i+1);
                i++;
            }
            b=(char*)realloc(b,(g-1)*sizeof(char));
        }
        r=understandstrings(a,b);
        a=*r;
        b=*(r+1);
        free(r);
    }
    else
    {
        if(*a=='-')
        {
            i=0;
            size=strlen(a)+1;
            while(i<size-1)
            {
                *(a+i)=*(a+i+1);
                i++;
            }
            a=(char*)realloc(a,(size-1)*sizeof(char));
            
            r=understandstrings(a,b);
            a=*r;
            b=*(r+1);
            free(r);
        }
        else
        {
            i=0;
            g=strlen(b)+1;
            while(i<g-1)
            {
                *(b+i)=*(b+i+1);
                i++;
            }
            b=(char*)realloc(b,(g-1)*sizeof(char));
            
            r=understandstrings(a,b);
            a=*r;
            b=*(r+1);
            free(r);
        }
        p=1;
    }
    i=0;
    k=0;
    while(k==0)
    {
        if(*(a+i)=='.')
        {
            k=1;
        }
        i++;
    }
    i--;
    
    size=strlen(a)+1;
    g=0;
    while(i+g<size-1)
    {
        *(a+i+g)=*(a+i+g+1);
        *(b+i+g)=*(b+i+g+1);
        g++;
    }
    a=(char*)realloc(a,(size-1)*sizeof(char));
    b=(char*)realloc(b,(size-1)*sizeof(char));

    t=2*(size-1-i-1);
    
    conserve=(char*)malloc(sizeof(char));
    i=0;
    g=0;
    r=(char**)malloc((strlen(b))*sizeof(char*));
    returnInt=(char*)malloc(2*sizeof(char));
    *returnInt='0';
    *(returnInt+1)='\0';
    while(i<strlen(b))
    {
        *(r+i)=(char*)malloc(2*sizeof(char));
        **(r+i)='0';
        *(*(r+i)+1)='\0';
        
        while(g<*(b+strlen(b)-1-i)-48)
        {
            conserve=(char*)realloc(conserve,(strlen(a)+1)*sizeof(char));
            k=0;
            while(k<strlen(a)+1)
            {
                *(conserve+k)=*(a+k);
                k++;
            }

            *(r+i)=add(*(r+i),a);
            
            a=(char*)malloc((strlen(conserve)+1)*sizeof(char));
            k=0;
            while(k<strlen(conserve)+1)
            {
                *(a+k)=*(conserve+k);
                k++;
            }

            g++;
        }
        g=0;
        
        size=strlen(*(r+i))+1;
        *(r+i)=(char*)realloc(*(r+i),(size+i)*sizeof(char));
        k=size-2;
        while(k<size+i-2)
        {
            *(*(r+i)+k)='0';
            k++;
        }
        *(*(r+i)+size+i-2)='.';
        *(*(r+i)+size+i-1)='\0';
        
        returnInt=add(returnInt,*(r+i));
        
        i++;

    }
    
    size=strlen(returnInt)+1;
    
    
    
    if(size-t-2<0)
    {
        k=t+2-size;
        returnInt=(char*)realloc(returnInt,(size+t+2-size)*sizeof(char));  
        size=t+2;
        g=size-1;
        while(g>k-1)
        {
            *(returnInt+g)=*(returnInt+g-k);
            g--;
        }
        g=0;
        while(g<k)
        {
            *(returnInt+g)='0';
            g++;
        }  
    }

    i=size-2;
    while(i>size-t-2)
    {
        *(returnInt+i)=*(returnInt+i-1);
        i--;
    }
    *(returnInt+i)='.';
    
    if(p==1)
    {
        size=strlen(returnInt)+1;
        i=size+1-1;
        returnInt=(char*)realloc(returnInt,(size+1)*sizeof(char));
        while(i>0)
        {
            *(returnInt+i)=*(returnInt+i-1);
            i--;
        }
        *returnInt='-';
    }
    
    free(a);
    free(b);
    free(conserve);
    free(r);
    
    return returnInt;
}