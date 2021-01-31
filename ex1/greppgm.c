#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
main(int c,char*arg[])
{
        int fd,buffer=1,cmp_no=0,i=0;
        char file[50],temp[50],word[15];
      if(c==1)
{
printf("\nSpecify The Pattern and File Name");
}
else if(c==2)
{
printf("\nSpecify File Name");
}
else
{
  strcpy(word,arg[1]);
         fd=open(arg[2],O_RDONLY);
        while(buffer)
        {
                buffer=read(fd,file,1);
                if(file[0]!='\n')
                {
                        temp[i]=file[0];
                 
                        i++;
                }
                else
                {
                        temp[i]='\0';
                        if(strstr(temp,word)!=NULL)
                        {
                        printf("%s",word);
    	                cmp_no++;
                        }
                        i=0;
                }
        }
printf("\nOccurrence:%d\n",cmp_no);
}

}



