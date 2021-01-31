#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
main()
{
 int p,a[2],year,y,rem_4,rem_100,rem_400;
 p=pipe(a);
 pid_t x;
 x=fork();
 if(x==0)
 {
  printf("\n Enter year to be tested!");
  scanf("%d",&year);
  close(a[0]);
  write(a[1],&year,2);
 }
 if(x>0)
 {
  //wait(&a);
  read(a[0],&y,2);
  rem_4=y%4;
  rem_100=y%100;
  rem_400=y%400;
  if((rem_4==0 && rem_100!=0)||rem_400==0)
    printf("\n The given year is a leap year!\n");
  else
    printf("\n Not a leap year!\n");
 }
}

