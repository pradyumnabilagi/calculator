#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"project.h"



char *add(char *a,char *b)
{
   char *returnInt;
   char **r;
   int kl=0;
   r=understandstrings(a,b);
   a=*r;
   b=*(r+1);
   free(r);
   int i=0,g=0,p=0,size=0;
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
          p=1;
       }

       returnInt=(char*)malloc((strlen(a)+2)*sizeof(char));
        i=0;
        while(i<strlen(a)+2)
        {
            *(returnInt+i)='0';   
            i++;
        }
       *(returnInt+strlen(a)+1)='\0';
       i=0;
       g=0;
       while(i<strlen(a))
       {
            size=*(a+strlen(a)-1-i)-48+*(b+strlen(b)-1-i)-48+g;
            if(*(a+strlen(a)-1-i)!='.')
            {
                if(size<10){*(returnInt+strlen(returnInt)-1-i)=size+48;g=0;}
                else if(size<20&&size>=10){*(returnInt+strlen(returnInt)-1-i)=size+48-10;g=1;}
                else if(size<30&&size>=20){*(returnInt+strlen(returnInt)-1-i)=size+48-20;g=2;} 
            }
            else
            {
                *(returnInt+strlen(returnInt)-1-i)='.';
            }
            i++;
       }
       *(returnInt+strlen(returnInt)-1-i)=g+48;
       ///

       ///
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
   }
   else
   {
       i=0;
       g=0;
       size=0;
       if(*a=='-')
       {
         i=0;
          g=strlen(a)+1;
          while(i<g-1)
          {
             *(a+i)=*(a+i+1);
             i++;
          }
          a=(char*)realloc(a,(g-1)*sizeof(char));
          returnInt=sub(b,a);
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
          returnInt=sub(a,b);
       }   
   }
   free(a);
   free(b);
   return returnInt;
   
}