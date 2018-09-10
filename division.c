#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"project.h"

char *division(char *a,char *b)
{
    
    int i=0,size=0,g=0,p=0,t=0,k=0,op=1,dp=0,kl=0;
    char *returnInt;
    char *conserve;
    char *conserve1;
    char *check;
    char *increment;
    char **r;
    char **store;
  
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
    size=0;
    g=0;
    t=0;
    k=0;
    conserve=(char*)malloc(sizeof(char));
    conserve1=(char*)malloc(sizeof(char));
    returnInt=(char*)malloc(2*sizeof(char));
    store=(char**)malloc(sizeof(char*));
    *returnInt='0';
    *(returnInt+1)='\0';
    increment=(char*)malloc(3*sizeof(char));
    *increment='1';
    *(increment+1)='.';
    *(increment+2)='\0';
    while(size!=1&&op!=0)
    {
        size=0;
        while(size==0)
        {
           
            conserve=(char*)realloc(conserve,(strlen(b)+1)*sizeof(char));
            k=0;
            while(k<strlen(b)+1)
            {
                *(conserve+k)=*(b+k);
                k++;
            } 

            conserve1=(char*)realloc(conserve1,(strlen(returnInt)+1)*sizeof(char));
            k=0;
            while(k<strlen(returnInt)+1)
            {
                *(conserve1+k)=*(returnInt+k);
                k++;
            }
            
            check=multiplication(b,returnInt);
            
            b=(char*)malloc((strlen(conserve)+1)*sizeof(char));
            k=0;
            while(k<strlen(conserve)+1)
            {
                *(b+k)=*(conserve+k);
                k++;
            }
        
            returnInt=(char*)malloc((strlen(conserve1)+1)*sizeof(char));
            k=0;
            while(k<strlen(conserve1)+1)
            {
                *(returnInt+k)=*(conserve1+k);
                k++;
            }
            
            
            conserve=(char*)realloc(conserve,(strlen(a)+1)*sizeof(char));
            k=0;
            while(k<strlen(a)+1)
            {
                *(conserve+k)=*(a+k);
                k++;
            }
            
            r=understandstrings(a,check);
            a=*r;
            check=*(r+1);
            free(r);
            k=0;
            while(k<strlen(a)&&size==0)
            {
                if(*(a+k)>*(check+k))
                {
                size=1; 
                }
                else if(*(a+k)<*(check+k))
                {
                size=-1;
                }
                k++;
            }
            if(size==1)
            {
                size=0;
                free(check);
            } 
            else if(size==0)
            {
                size=1;
            }
            else if(size==-1)
            {
                size=-1;
                
            }

            a=(char*)realloc(a,(strlen(conserve)+1)*sizeof(char));  
            k=0;
            while(k<strlen(conserve)+1)
            {
                *(a+k)=*(conserve+k);
                k++;
            }

            
            conserve=(char*)realloc(conserve,(strlen(increment)+1)*sizeof(char));
            k=0;
            while(k<strlen(conserve)+1)
            {
                *(conserve+k)=*(increment+k);
                k++;
            }
                
            returnInt=add(returnInt,increment);
           
            increment=(char*)malloc((strlen(conserve)+1)*sizeof(char));
            k=0;
            while(k<strlen(increment)+1)
            {
                *(increment+k)=*(conserve+k);
                k++;
            }
            
        }
        
        conserve=(char*)realloc(conserve,(strlen(increment)+1)*sizeof(char));
        k=0;
        while(k<strlen(conserve)+1)
        {
            *(conserve+k)=*(increment+k);
            k++;
        }

        returnInt=sub(returnInt,increment);

        increment=(char*)malloc((strlen(conserve)+1)*sizeof(char));
        k=0;
        while(k<strlen(increment)+1)
        {
            *(increment+k)=*(conserve+k);
            k++;
        }
        
        if(size!=1)
        {
            conserve=(char*)realloc(conserve,(strlen(increment)+1)*sizeof(char));
            k=0;
            while(k<strlen(conserve)+1)
            {
                *(conserve+k)=*(increment+k);
                k++;
            }

            returnInt=sub(returnInt,increment);

            increment=(char*)malloc((strlen(conserve)+1)*sizeof(char));
            k=0;
            while(k<strlen(increment)+1)
            {
                *(increment+k)=*(conserve+k);
                k++;
            }
            
            if(i==0)
            {
                *increment='.';
                *(increment+1)='1';
                *(increment+2)='\0';
            }
            else
            {
                increment=(char*)realloc(increment,(strlen(increment)+2)*sizeof(char));
                k=strlen(increment)+1;
                *(increment+k)='\0';
                *(increment+k-1)='1';
                *(increment+k-2)='0';
            }
            //
            conserve=(char*)realloc(conserve,(strlen(b)+1)*sizeof(char));
            k=0;
            while(k<strlen(b)+1)
            {
                *(conserve+k)=*(b+k);
                k++;
            } 

            conserve1=(char*)realloc(conserve1,(strlen(returnInt)+1)*sizeof(char));
            k=0;
            while(k<strlen(returnInt)+1)
            {
                *(conserve1+k)=*(returnInt+k);
                k++;
            }
            free(check);
            
            check=multiplication(b,returnInt);
            
            b=(char*)malloc((strlen(conserve)+1)*sizeof(char));
            k=0;
            while(k<strlen(conserve)+1)
            {
                *(b+k)=*(conserve+k);
                k++;
            }
        
            returnInt=(char*)malloc((strlen(conserve1)+1)*sizeof(char));
            k=0;
            while(k<strlen(conserve1)+1)
            {
                *(returnInt+k)=*(conserve1+k);
                k++;
            }

            //
            conserve=(char*)realloc(conserve,(strlen(a)+1)*sizeof(char));
            k=0;
            while(k<strlen(a)+1)
            {
                *(conserve+k)=*(a+k);
                k++;
            }

            free(conserve1);
            conserve1=sub(a,check);

            a=(char*)malloc((strlen(conserve)+1)*sizeof(char));
            k=0;
            while(k<strlen(conserve)+1)
            {
                *(a+k)=*(conserve+k);
                k++;
            }
            
            store=(char**)realloc(store,(i+1)*sizeof(char*));
            *(store+i)=(char*)malloc((strlen(conserve1)+1)*sizeof(char));
            k=0;            
            while(k<strlen(conserve1)+1)
            {
                *(*(store+i)+k)=*(conserve1+k);
                k++;
            }
            
            //check weather reapetation starts or not
            conserve=(char*)realloc(conserve,3*sizeof(char));
            *(conserve)='1';
            *(conserve+1)='0';
            *(conserve+2)='\0';
            k=0;
            while(k<i&&op!=0)
            {
                *(store+i)=multiplication(*(store+i),conserve);
                conserve=(char*)malloc(3*sizeof(char));
                *(conserve)='1';
                *(conserve+1)='0';
                *(conserve+2)='\0';
                
                conserve=(char*)realloc(conserve,(strlen(*(store+i-k-1))+1)*sizeof(char));
                t=0;
                while(t<strlen(*(store+i-k-1))+1)
                {
                    *(conserve+t)=*(*(store+i-k-1)+t);
                    t++;
                } 
                r=understandstrings(*(store+i),*(store+i-k-1));
                *(store+i)=*r;
                *(store+i-k-1)=*(r+1);
                free(r);
                dp=0;
                op=0;
                while(dp<strlen(*(store+i))&&op==0)
                {
                    if(*(*(store+i)+dp)>*(*(store+i-k-1)+dp))
                    {
                    op=1; 
                    }
                    else if(*(*(store+i)+dp)<*(*(store+i-k-1)+dp))
                    {
                    op=-1;
                    }
                    dp++;
                }
                if(op==0)
                {
                    if(i-k-1==2)
                    {
                    printf("the answer reapets form %dnd decimal place",i-k-1);
                    }
                    else if(i-k-1==3)
                    {
                    printf("the answer reapets form %drd decimal place",i-k-1);
                    }
                    else
                    {
                    printf("the answer reapets form %dth decimal place",i-k-1);
                    }
                    dp=i;
                }
                *(store+i-k-1)=(char*)realloc(*(store+i-k-1),(strlen(conserve)+1)*sizeof(char));
                t=0;
                while(t<strlen(*(store+i-k-1))+1)
                {
                    *(*(store+i-k-1)+t)=*(conserve+t);
                    t++;
                }
                conserve=(char*)realloc(conserve,3*sizeof(char));
                *(conserve)='1';
                *(conserve+1)='0';
                *(conserve+2)='\0';
                k++;
            }
            *(store+i)=(char*)realloc(*(store+i),(strlen(conserve1)+1)*sizeof(char));
            t=0;
            while(t<strlen(conserve1)+1)
            {
                *(*(store+i)+t)=*(conserve1+t);
                t++;
            }
            i++;
            //
        }
           
    }
    
    
    ///
    i=0;
    while(*(returnInt+i)!='.')
    { 
        i++;
    }
    kl=i;
    g=0;
    while(*(returnInt+g)=='0'&&g<kl-1)
    {
        g++;
    }
    i=0;
       
    size=strlen(returnInt)-g+1;
    while(i<size)
    {
        *(returnInt+i)=*(returnInt+i+g);
        i++;
    }
    returnInt=(char*)realloc(returnInt,size*sizeof(returnInt));
       
    i=0;
    while(*(returnInt+strlen(returnInt)-1-i)=='0')
    {
        i++;
    }
    size=strlen(returnInt)+1-i;
    returnInt=(char*)realloc(returnInt,(strlen(returnInt)+1-i)*sizeof(char));
    *(returnInt+size-1)='\0';
    size=strlen(returnInt)+1;
    if(*(returnInt+size-2)=='.')
    {
        returnInt=(char*)realloc(returnInt,(size-1)*sizeof(char));
        *(returnInt+size-2)='\0';
    }
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
    
    i=0;
    while(i<dp+1)
    {
        free(*(store+i));
        i++;
    }
       
    free(store);
    free(conserve);
    free(conserve1);
    free(increment);
    free(a);
    free(b);
    free(check);
    return returnInt;
}
