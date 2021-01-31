#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/ipc.h>
main()
{
 int x,*a,id,n;
 id=shmget(IPC_PRIVATE,sizeof(int)*1,IPC_CREAT|0766);
 if(id==-1)
 {
  printf("Shared memory creation failed !");
 }
 else
 {
  a=(int*)shmat(id,NULL,0);
  x=fork();
  if(x==-1)
  {
   printf("Child process creation failed !");
  }
  if(x==0) 
  {
   printf("Enter a number :");
   scanf("%d",&n);
   *a=n;
  }
  else if(x>0)
  {
   wait(&x);
   if(*a%2==0)
   {
    printf("The number %d is even !\n",*a);
   }
   else
   {
    printf("The number %d is odd !\n",*a);
   }
  }
 }
}
