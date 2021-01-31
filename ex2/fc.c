#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
main()
{
     pid_t firstChild,secondChild;
     int wc=0,lc=0,cc=0,p1,a[2],p2,b[2],i=0,linebuffer=1;
     char line[50],temp[50];
     FILE *fd;
     //Pipe Creation
     p1=pipe(a);
     if(p1==-1)
      {
         printf("Pipe 1 Not Created\n");
         exit(1);
      }
     p2=pipe(b);
     if(p2==-1)
      {
         printf("Pipe 1 Not Created\n");
         exit(1);
      }


      firstChild = fork();
      if(firstChild > 0)
      {
        wait(&firstChild);
        // In parent
        secondChild = fork();
        if(secondChild > 0)
        {
           // In parent
        }
        else if(secondChild < 0)
        {
          // Error
          printf("SecondChild Error");
        }
        else {
          // In secondChild
          printf("Inside SecondChild\n");
          close(a[1]);
          read(a[0], temp, sizeof(temp));
          printf("Contents Read from Pipe A and Written to Pipe B %s\n",temp);
          printf("Couting Now\n");
          while (temp[i]!='\0') {
              cc++;
              //printf("%c",temp[i]);
              if(temp[i]==' ') {
                 wc++;
              }
              if(temp[i]=='\n') {
                lc++;
              }
              i++;
            }
            printf("Word Count : %d\n",wc);
            printf("Character count : %d\n",cc);
            fd=fopen("a.txt","w");
            if(fd==-1) {
               printf("File not opened\n");
               exit(1);
            }
            else {
              fprintf(fd,"%s", temp);
              fclose(fd);
            }
         
        }
      }
      else if(firstChild < 0 )
      {
        // Error
         printf("FirstChild Error");
      }
      else
      {
        // In firstChild
        printf("Inside FirstChild\n" );
        printf("Enter the line you want\n");
        gets(line);
        write(a[1],&line,sizeof(line));
        printf("Contents are Written in Pipe are -> %s \n",line);
        close(a[1]);
      }
}
