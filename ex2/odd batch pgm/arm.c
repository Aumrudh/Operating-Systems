#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<unistd.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
 int p,a[2],num,n,n1,sum=0,rem;
 p=pipe(a);
 pid_t x;
 x=fork();
 if(x==0)
 {
  printf("\n Enter number to be tested!");
  scanf("%d",&num);
  close(a[0]);
  write(a[1],&num,2);
 }
 if(x>0)
 {
  wait(); 
  read(a[0],&n1,2);
  printf("%d",n1);
  n=n1;
  for(;n1>0;n1=n1/10)
  {
    rem=n1%10;
    sum+=pow(rem,3);
  }
  if(sum==n)
   printf("\n The given number is a armstrong number!%d\n",sum);
  else
   printf("\n Its is not a armstrong number!%d\n",sum);
 }
}

