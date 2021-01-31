#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main(int argc,char * argval[])
{
int fd,fd2;
char temp;
if(argc==1)
{
printf("\nSpecify File name");
}
else
{
fd=open(argval[1],O_RDONLY);
if(fd!=-1)
{
fd2=open(argval[2],O_RDWR|O_APPEND);
if(fd2==-1)
{
fd2=open(argval[2],O_CREAT|O_RDWR|O_APPEND,S_IRWXU);
}
while(read(fd,&temp,1)>0)
{
write(fd2,&temp,1);
printf("");
}
close(fd);
unlink(argval[1]);
close(fd2);
}
else
{
printf("\nSource File Not Available");
}
}
}
