#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
main()
{
    pid_t f;
    int p,a[2],n,no[40],i,no1[40];
     int sum=0;
     printf("Enter number of integers\n");
     scanf("%d",&n);
     printf("Give some n integers %d\n",n);
    p=pipe(a);
    if(p==-1)
     {
        printf("Pipe Creation failed\n");
        exit(1);
     }
    f=fork();
   if(f==-1)
     {
        printf("Fork Creation failed\n");
        exit(1);
     }
   else if (f==0)
    {
        for(i=0;i<n;i++)
        {
          scanf("%d",&no[i]);
        }
        for(i=0;i<n;i++)
        {
          close(a[0]);
          write(a[1],&no[i],sizeof(int));
        }
    }
   else
    {
       wait(&f);
       for(i=0;i<n;i++)
       {
         read(a[0],&no1[i],sizeof(int));
         printf("Numebers are : %d\n",no1[i]);
         if(no1[i]%2==0)
           {
             sum+=no1[i];
           }
      }
      close(a[0]);
      printf("Sums is : %d\n",sum);
    }
}
