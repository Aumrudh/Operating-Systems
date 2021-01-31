#include<sys/sem.h>
#include<stdio.h>
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


typedef struct FIT
{
 int size;
 struct FIT *next;
}node;
typedef node *fit;
fit max(fit);
fit best(fit,int);
fit initialize()
{
 fit temp;
 temp=(node*)malloc(sizeof(node));
 if(temp==NULL)
   printf("\n Error in initialization");
 else
 {
  temp->size=0;
  temp->next=NULL;
  return temp;
 }
}

fit Find(int x,fit L)
{
 fit p;
 p=L->next;
 while(p!=NULL)
 {
  if(p->size==x)
     return p;
  else
     p=p->next;
 }
}

fit Findprev(int x,fit L)
{
 fit p;
 p=L->next;
 while(p!=NULL)
 {
  if(p->next->size==x)
     return p;
  else
     p=p->next;
 }
}





void enqueue(int n,fit f)
{
 fit temp,p;
 p=f;
 temp=(node*)malloc(sizeof(node));
 temp->size=n;
 while(p->next!=NULL)
     p=p->next;
 temp->next=p->next;
 p->next=temp;
}

void dequeue(int n,fit f)
{
 fit temp,prev,p;
 p=Find(n,f);
 if(p==f->next)
 {
  temp=p;
  f->next=p->next;
  free (temp);
 }
 else
 {
 prev=Findprev(n,f);
 temp=prev->next;
 prev->next=temp->next;
 free (temp);
 }
}





int main()
{
 fit f=initialize();
int x,mutex,full,empty,buf[100],i=0,n,d,m,l,h;
printf("\nEnter the buffer size to store the values:");
scanf("%d",&m);
d=shmget(IPC_PRIVATE,m*sizeof(int),IPC_CREAT|0766);
buff=(int *)shmat(d,NULL,0);


if(mutex<0)
printf("\nError in creating mutex semaphore");
sem_create(mutex,1);
mutex=semget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0766);


if(full<0)
printf("\nError in creating full semaphore");
sem_create(full,0);
full=semget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0766);


if(empty<0)
printf("\nError in creating empty semaphore");
sem_create(empty,m);
empty=semget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0766);

for(i=0;i<=m;i++)
buf[i]=0;

l=fork();

if(l>0)
{
fit p=f;
printf("\nProducer process: \n");
wait(empty);
wait(mutex);
for(i=0;i<m;i++)
{
printf("The product is:");
scanf("%d",&x);
enqueue(x,p);
}
signal(mutex);
signal(full);
h=fork();
}

if(h==0&&l>0)
{
fit p=f->next;
printf("\nConsumer process: \n");
wait(full);
wait(mutex);

for(i=0;i<m;i++)
{
 printf("\nConsumed %d",p->size);
 dequeue(p->size,f);
 p=p->next;
}
signal(mutex);
signal(empty);
}
}
