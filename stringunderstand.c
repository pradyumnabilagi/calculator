#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char **understandstrings(char*a,char*b)
{
    int size,i=0,indexOfa,indexOfb;
    char **returnstrings;
    if(*a=='+')
    {
       size=strlen(a)+1;
       while(i<size-1)
       {
          *(a+i)=*(a+i+1);
          i++;
       }
       a=(char*)realloc(a,(size-1)*sizeof(char));
    }
    i=0;
    size=0;
    while(i<strlen(a))
    {
       if(*(a+i)=='.')
       {
          size=1; 
       }
       i++;   
    }
    i=strlen(a)+1;
    if(size==0)
    {
        a=(char*)realloc(a,(i+1)*sizeof(char));
        *(a+i-1)='.';
        *(a+i)='\0';
    }
    i=0;
    while(i<strlen(a)+1)
    {
      if(*(a+i)=='.')
      {
         indexOfa=i;
      }
      i++;
    }

    i=0;

    if(*b=='+')
    {
       size=strlen(b)+1;
       while(i<size-1)
       {
          *(b+i)=*(b+i+1);
          i++;
       }
       b=(char*)realloc(b,(size-1)*sizeof(char));
    }
    i=0;
    size=0;
    while(i<strlen(b))
    {
       if(*(b+i)=='.')
       {
          size=1; 
       }
       i++;   
    }
    i=strlen(b)+1;
    if(size==0)
    {
        b=(char*)realloc(b,(i+1)*sizeof(char));
        *(b+i-1)='.';
        *(b+i)='\0';
    }
    i=0;
    while(i<strlen(b)+1)
    {
      if(*(b+i)=='.')
      {
         indexOfb=i;
      }
      i++;
    }


     
    if((*a!='-'&&*b!='-')||(*a=='-'&&*b=='-'))
    {
        int p=0;
      if(*a=='-'&&*b=='-')
      {
          i=0;
          size=strlen(a)+1;
          while(i<size-1)
          {
             *(a+i)=*(a+i+1);
             i++;
          }
          a=(char*)realloc(a,(size-1)*sizeof(char));
          
          i=0;
          size=strlen(b)+1;
          while(i<size-1)
          {
             *(b+i)=*(b+i+1);
             i++;
          }
          b=(char*)realloc(b,(size-1)*sizeof(char));
          p=1;
      }




      if(strlen(a)-indexOfa>strlen(b)-indexOfb)
      {
         size=strlen(b)+1+strlen(a)-indexOfa-(strlen(b)-indexOfb);
         i=strlen(b);
         b=(char*)realloc(b,size*sizeof(char));
         
         while(i<size-1)
         {
            *(b+i)='0';
            i++;
         }
         *(b+size-1)='\0';
      }
      else if(strlen(b)-indexOfb>strlen(a)-indexOfa)
      {
         size=strlen(a)+1+strlen(b)-indexOfb-(strlen(a)-indexOfa);
         i=strlen(a);
         a=(char*)realloc(a,size*sizeof(char));
         while(i<size-1)
         {
            *(a+i)='0';
            i++;
         }
         *(a+size-1)='\0';
      }
      
      if(indexOfa>indexOfb)
      {
          size=strlen(b)+1+indexOfa-indexOfb;
          b=(char*)realloc(b,size*sizeof(char));
          i=size-1;
          while(i>indexOfa-indexOfb-1)
          {
           *(b+i)=*(b+i-indexOfa+indexOfb);
           i--;
          }
          i=0;
          while(i<indexOfa-indexOfb)
          {
              *(b+i)='0';  
              i++;
          }
      }
      else if(indexOfb>indexOfa)
      {
          size=strlen(a)+1+indexOfb-indexOfa;
          a=(char*)realloc(a,size*sizeof(char));
          i=size-1;
          while(i>indexOfb-indexOfa-1)
          {
           *(a+i)=*(a+i-indexOfb+indexOfa);
           i--;
          }
          i=0;
          while(i<indexOfb-indexOfa)
          {
              *(a+i)='0';  
              i++;
          }
         
      }
       
       if(p==1)
       {
         size=strlen(a)+1;
         i=size+1-1;
         a=(char*)realloc(a,(size+1)*sizeof(char));
         while(i>0)
         {
             *(a+i)=*(a+i-1);
             i--;
         }
         *a='-';
           
         size=strlen(b)+1;
         i=size+1-1;
         b=(char*)realloc(b,(size+1)*sizeof(char));
         while(i>0)
         {
             *(b+i)=*(b+i-1);
             i--;
         }
         *b='-';
       }

    }
   returnstrings=(char**)malloc(2*sizeof(char*));
   *(returnstrings)=a;
   *(returnstrings+1)=b;
   return returnstrings;
   
}


