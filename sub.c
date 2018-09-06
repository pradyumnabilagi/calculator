#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **understandstrings(char *a,char *b);
char *add(char *a,char *b);

char *sub(char *a,char *b)
{
    char *returnInt;
    char **r;
    char *store;
    r=understandstrings(a,b);
    a=*r;
    b=*(r+1);
    free(r);
    int i=0,size=0,g=0;
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

            store=a;
            a=b;
            b=store;
        }
        i=0;
        while(i<strlen(a)&&g==0)
        {
            if(*(a+i)>*(b+i))
            {
               g=1; 
            }
            else if(*(a+i)<*(b+i))
            {
               g=-1;
            }
            i++;
        }
        i=0;
        
        if(g==1||g==0)
        {
            i=0;
            returnInt=(char*)malloc((strlen(a)+1)*sizeof(char));
            while(i<strlen(a)+1)
            {
                *(returnInt+i)='0';
                i++;
            }
            *(returnInt+strlen(a))='\0';
            i=0;
            while(i<strlen(a))
            {
                if(*(a+strlen(a)-i-1)=='.')
                {
                    *(returnInt+strlen(returnInt)-1-i)='.';
                }
                else if(*(a+strlen(a)-i-1)>=*(b+strlen(b)-i-1))
                {
                   *(returnInt+strlen(returnInt)-1-i)=*(a+strlen(a)-i-1)-*(b+strlen(b)-i-1)+48;   
                }
                else if(*(a+strlen(a)-i-1)<*(b+strlen(b)-i-1))
                {
                    g=0;
                    size=1;
                    while(g==0)
                    {
                        if(*(a+strlen(a)-1-i-size)=='0')
                        {
                            *(a+strlen(a)-1-i-size)='9';
                        }
                        else if(*(a+strlen(a)-1-i-size)>48)
                        {
                            *(a+strlen(a)-1-i-size)=*(a+strlen(a)-1-i-size)-1;
                            g=1;
                        }
                        size++;
                    }
                    *(returnInt+strlen(returnInt)-1-i)=*(a+strlen(a)-1-i)+10-*(b+strlen(b)-i-1)+48;   
                }
                i++;
            }
        }
        else if(g==-1)
        {
            store=a;
            a=b;
            b=store;
            i=0;
            returnInt=(char*)malloc((strlen(a)+1)*sizeof(char));
            while(i<strlen(a)+1)
            {
                *(returnInt+i)='0';
                i++;
            }
            *(returnInt+strlen(a))='\0';
            i=0;
            while(i<strlen(a))
            {
               if(*(a+strlen(a)-i-1)=='.')
                {
                   *(returnInt+strlen(returnInt)-1-i)='.';
                }
                else if(*(a+strlen(a)-i-1)>=*(b+strlen(b)-i-1))
                {
                   *(returnInt+strlen(returnInt)-1-i)=*(a+strlen(a)-i-1)-*(b+strlen(b)-i-1)+48;   
                }
                else if(*(a+strlen(a)-i-1)<*(b+strlen(b)-i-1))
                {
                    g=0;
                    size=1;
                    while(g==0)
                    {
                        if(*(a+strlen(a)-1-i-size)=='0')
                        {
                            *(a+strlen(a)-1-i-size)='9';
                        }
                        else if(*(a+strlen(a)-1-i-size)>48)
                        {
                            *(a+strlen(a)-1-i-size)=*(a+strlen(a)-1-i-size)-1;
                            g=1;
                        }
                        size++;
                    }
                    *(returnInt+strlen(returnInt)-1-i)=*(a+strlen(a)-1-i)+10-*(b+strlen(b)-i-1)+48;   
                }
                i++;
            }
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
    }
    else
    {
        if(*a=='-')
        {
            size=strlen(b)+1;
            i=size+1-1;
            b=(char*)realloc(b,(size+1)*sizeof(char));
            while(i>0)
            {
                *(b+i)=*(b+i-1);
                i--;
            }
            *b='-';
            returnInt=add(a,b);
        }
        else
        {
            i=0;
            size=strlen(b)+1;
            while(i<size-1)
            {
                *(b+i)=*(b+i+1);
                i++;
            }
            b=(char*)realloc(b,(size-1)*sizeof(char));
            returnInt=add(a,b);
        }
    }
   free(a);
   free(b);
   return returnInt;

}