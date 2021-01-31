#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
main(int argc,char* argv[])
{
    DIR *dp;
    struct dirent *sd;
    dp=opendir(argv[1]);
    if(dp==NULL)
     {
        printf("Cannot open the directory\n");
        exit(0);
     }
    else
      {
        while((sd=readdir(dp))!=NULL)
         {
          printf("%s\t",sd->d_name);
         }
      }
     closedir(dp);
}

