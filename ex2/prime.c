#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
main()
{
    pid_t f1,f2;
    int p1,a[2],p2,b[2],i,n[100],count=0,j,sum=0,flag=1,temp[100];
    p1=pipe(a);
    if(p1==-1)
     {
        printf("Pipe Creation failed\n");
        exit(1);
     }
    p2=pipe(b);
    if(p2==-1)
     {
        printf("Pipe Creation failed\n");
        exit(1);
     }
    f1=fork();
    if(f1==-1)
     {
        printf("Fork Creation failed\n");
        exit(1);
     }
    else if (f1==0)
    {
        printf("Enter 10 number : ");
        for(i=0;i<10;i++)
        {
          scanf("%d",&n[i]);
          write(a[1],&n[i],sizeof(int));
        }
        close(b[0]);
          for(i=0;i<10;i++)
          {
            if(n[i]%2!=0)
                {
                  temp[i]=n[i];
                  count++;
                }
          }
                  for(i=0;i<count;i++)
                   {
                    write(b[1],&temp[i],sizeof(int));
                   }
    }
   else
    {
      wait(&f1);
      for(i=1;i<=10;++i)
      {
       read(a[0],&n[i],sizeof(int));
       flag=0;
       for(j = 2; j <= n[i]/2; j++)
       {
         if(n[i]%j==0)
         {
            flag=1;
            //break;
         }
       }
       if(flag==0 && n[i]!=1 )
         printf("Prime number -  : %d\n",n[i]);
      }
    }
   if(f1==0)
   {
   f2=fork();
    if(f1==0&&f2==0)
       {
	 wait(&f2);
         for(i=0;i<count;i++)
          {
           read(b[0],&temp[i],sizeof(int));
           sum=sum+n[i];
          }
        printf("Sum is : %d\n",sum);
       }
    else
     {
       wait(&f2);
     }
    }
}
