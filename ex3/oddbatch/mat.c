#include<sys/wait.h>
#include<string.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
        int shmid,i,j;
        int (*m1)[4][4],(*m2)[4][4],a[4][4],b[4][4];
        pid_t x;
      shmid = shmget(IPC_PRIVATE,64*sizeof(int),IPC_CREAT|0766);
       if(shmid == -1)
        {
                printf("Failed to create Shared_Memory\n\n");
                exit(1);
        }
        m1= (int**)shmat(shmid,NULL,0);
        m2= (int**)shmat(shmid,NULL,0);
        if((x=fork()) == -1)
        {
                printf("Error in creating process\n\n");
                exit(1);
        }
        else if(x == 0)
        {
          printf("\n Enter the 1st matrix:");
          for(i=0;i<4;i++)
          {
              for(j=0;j<4;j++)
               {
                 scanf("%d",&a[i][j]);
               }
           }
         printf("\n Enter te 2st matrix:");
          for(i=0;i<4;i++)
          {
           for(j=0;j<4;j++)
             scanf("%d",&b[i][j]);
         }
          for(i=0;i<4;i++)
          {
           for(j=0;j<4;j++)
           {
          *m1[i][j]=a[i][j];
          *m2[i][j]=b[i][j];
          }
         }
        }
         else
         {
           wait(&x);
           int res[4][4];
           for(i=0;i<4;i++)
           {  for(j=0;j<4;j++)
               res[i][j]=*m1[i][j]+*m2[i][j];
           }
           printf("\n The resulant matrix:\n");
          for(i=0;i<4;i++)
          {
             for(j=0;j<4;j++)
             {  printf("%d\t",res[i][j]);

             }
             printf("\n");
}
       }
return(0);
}

