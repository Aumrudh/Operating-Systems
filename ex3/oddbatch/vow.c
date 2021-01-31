#include<sys/wait.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
        int i,d,n;
        char a[10],temp,(*m)[10];
        pid_t x;
        /*printf("\n Enter no of process:");
 *         scanf("%d",&n);*/
        d= shmget(IPC_PRIVATE,sizeof(char),IPC_CREAT|0766);
        m=(char*)shmat(d,NULL,0);
        if((x=fork()) == -1)
        {
                printf("Error in creating process\n\n");
                exit(1);
        }
        else if(x == 0)
        {
                printf("Enter String\t");
                if(a!='\n')
                 scanf("%s",a);
	//n=strlen(a);
                strcpy(*m,a);
         }
        else if(x>0)
        {      
                wait(&x);
                int j,count=0;
                char temp[10];
                strcpy(temp,*m);
                for(j=0;j<strlen(temp);j++)
                {
                   if(temp[j]=='a'||temp[j]=='e'||temp[j]=='i'||temp[j]=='o'||temp[j]=='u')
                                        count++;
                }
                        printf(" %d vowels\n",count);
                }
return(0);
}

