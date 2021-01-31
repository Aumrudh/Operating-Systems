#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
 int a[2],p,fd1;
 pid_t x;
 p=pipe(a);
 if(p==-1)
  printf("\n Pipe creation failed!");
 char n[10],cp;
 x=fork();
 printf("\n Enter filename to be opened!");
 scanf("%s",n);
 if(x>0)
 {
  printf("\n Parent ID is:%d\n",getpid());
  close(a[0]);
  write(a[1],&n,sizeof(n));
 }
 if(x==0)
 {
  printf("\n Child ID is:%d\n",getpid());
  read(a[0],&n,sizeof(n));
  fd1=open(n,O_RDONLY);
  if(fd1==-1)
  {
   printf("\n File doesnt opened!");
  }
  while(read(fd1,&cp,1)>0)
  { 
    printf("%c",cp);
  }
}
 close(fd1);
return(0);
}


