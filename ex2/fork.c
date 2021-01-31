#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
main()
{
    pid_t p1,p2,p3;
    p1=fork();
    if(p1==-1)
     {
        printf("Process p1 not created\n");
        exit(1);
     }
    else if(p1>0)
      {
        printf("First Process Parent p1 Executed and Process id for p1 is %d\n",getpid());
      }
    else
     {
        printf("Child Process p2 executed and process id is %d\n",getpid());
        printf("Parent process id for p2 is %d\n",getppid());
     }
    p2=fork();
    if(p1==-1&&p2==-1)
     {
        printf("Process p2 not created\n");
        exit(1);
     }
    else if(p1>0&&p2==0)
      {
        printf("Process p3 Executed and Process id for p3 is %d\n",getpid());
        printf("Parent process id for p3 is %d\n",getppid());
      }
    else if(p1==0&&p2==0)
     {
        printf("Child Process p4 executed and process id is %d\n",getpid());
        printf("Parent process id for p4 is %d\n",getppid());
     }
    else
     {
       printf("\n");
     }
   if(p1==0&&p2>0)
    {
      p3=fork();
      if(p3<0)
        {
           printf("Proess p3 not excuted\n");
           exit(1);
        }
      else if(p3==0)
        {
          printf("Child Process p5 executed and process id is %d\n",getpid());
          printf("Parent process id for p5 is %d\n",getppid());
        }
      else
       {
           printf("\n");
        }
    }
}
