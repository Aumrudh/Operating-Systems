#include<stdio.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
int *buff;

void sem_create(int id,int value)
{
union semnum
{
int val;
struct semid_ds *buf;
unsigned short *array;
}s;
s.val=value;
semctl(id,1,SETVAL,s);
}


void sem_op(int id,int value)
{
struct sembuf
{
int sem_num;
int sem_op;
int sem_flg;
}v;
v.sem_op=value;
semop(id,&v,1);
}

void wait(int id)
{
sem_op(id,-1);
}

void signal(int id)
{
sem_op(id,1);
}


int main()
{
int mutex,full,empty,buf[100],i=0,n,d,m,l,h;
printf("\nEnter the buffer size to store the values:");
scanf("%d",&m);
d=shmget(IPC_PRIVATE,m*sizeof(int),IPC_CREAT);
buff=(int *)shmat(d,NULL,0);
mutex=semget(IPC_PRIVATE,sizeof(int),IPC_CREAT);


if(mutex<0)
printf("\nError in creating mutex semaphore");
sem_create(mutex,1);
full=semget(IPC_PRIVATE,sizeof(int),IPC_CREAT);


if(full<0)
printf("\nError in creating full semaphore");
sem_create(full,0);
empty=semget(IPC_PRIVATE,sizeof(int),IPC_CREAT);


if(empty<0)
printf("\nError in creating empty semaphore");
sem_create(empty,m);


for(i=0;i<=m;i++)
buf[i]=0;

l=fork();

if(l>0)
{
printf("\nProducer process: \n");
wait(empty);
wait(mutex);
for(i=0;i<m;i++)
{
printf("The product is:");
scanf("%d",&buf[i]);
}
signal(mutex);
signal(full);
h=fork();
}

if(h==0&&l>0)
{
printf("\nConsumer process: \n");
wait(full);
wait(mutex);

for(i=0;i<m;i++)
printf("\nConsumed %d",buf[i]);
signal(mutex);
signal(empty);
}
}

