#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
 pid_t a,b,c,d;
 a=fork();
 b=fork();
 if(a>0 && b>0)
  printf("\n I'm a parent A and my id is %d\n",getpid());
 if(a==0 && b>0)
  {
   printf("\n I'm a child B from parent A my id is %d and my parent id is %d\n",getpid(),getppid());
   c=fork();
   }
 if(a>0 && b==0)
  printf("\n I'm a child C from parent A my id is %d and my parent id is %d\n",getpid(),getppid());
 if(a==0 && b==0)
   printf("\n I'm a child D from parent B my id is %d and my parent id is %d\n",getpid(),getppid());
/*  if(a==0 && b>0)
 *     c=fork();*/
  if(a==0 && b>0 && c==0)
  printf("\n I'm a child E from parent B my id is %d and my parent id is %d\n",getpid(),getppid());
return(0);
}


