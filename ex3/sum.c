//Programmed By AUMRUDH LAL KUMAR TJ
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
main()
{
    int shmid,n,p,*m,no[20],sum=0,i;
    printf("Enter the count of NUMBER : ");
    scanf(" %d",&n);
    shmid=shmget(IPC_PRIVATE,n*sizeof(int),IPC_CREAT|0766);
    if(shmid==-1)
      {
       printf("Error in Shared Memory Creation\n");
       exit(0);
      }
    m=(int*)shmat(shmid,NULL,0);
    p=fork();
    if(p<0)
      {
        printf("Error in process Creation\n");
        exit(0);
      }
    else if(p==0)
      {
        printf("Enter the NUMBERS : ");
        for(i=0;i<n;i++)
        {
          scanf(" %d",&no[i]);
        }
        m=&no;
      }
    else if(p>0)
     {
       if(*m==NULL)
         {
          wait(&p);
         }
       for(i=0;i<=n;i++)
         {
           sum+=*m+i;
         }
       printf("%d is SUM\n",sum);
     }
    else
     {
       printf("\n");
     }
}

