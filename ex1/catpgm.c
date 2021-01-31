#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
main(int argc,char *argv[])
{
    //display one file
    int fd1,fd2;
    char temp;
    if(argc==2) 
      {
         fd1=open(argv[1],O_RDONLY);
         if(fd1==-1)
         {
           printf("Error\n");
         }
         else
         {
          while(read(fd1,&temp,1)>0)
           {
              printf("%c",temp);
           }
              close(fd1);
         }
       }
    //display 2 file 
    else if(argc==3)
      {
         fd1=open(argv[1],O_RDONLY);
         fd2=open(argv[2],O_RDONLY);
         if(fd1==-1|fd2==-1)
         {
           printf("Error\n"); 
         }
         else
         {
          while(read(fd1,&temp,1)>0)
           {
              printf("%c",temp);
           }
           while(read(fd2,&temp,1)>0)
           {
              printf("%c",temp);
           }
              close(fd1);
              close(fd2);
         }

      }
    //write file 1 to file 2
    else if(argc==4&&argv[2]==">")
      {
         fd1=open(argv[1],O_RDONLY);
         fd2=open(argv[2],O_RDONLY);
         if(fd1==-1|fd2==-1)
         {
           printf("Error\n"); 
         }
         else
         {
          while(read(fd1,&temp,1)>0)
           {
            write(fd2,&temp,1);
           }
          close(fd1);
          close(fd2);
         }

      }
    //append file
    else if(argc==4&&argv[2]==">>")
      {
         fd1=open(argv[1],O_RDONLY);
         fd2=open(argv[2],O_RDONLY);
         if(fd1==-1|fd2==-1)
         {
           printf("Error\n"); 
         }
         else
         {
          while(read(fd1,&temp,1)>0)
           {
            write(fd2,&temp,1);
           }  
          close(fd1);
          close(fd2);
         }
       }
    else
     {
       printf("Enter valid arguments\n");
     }
}


