#include<stdio.h>
#include<stdlib.h>
typedef int elementtype;
struct list
{
 elementtype data;
 struct list* next;
};
typedef struct list* disk;
typedef struct list* position;
void allocate(int,disk,int);

position ini()
{
 position temp;
 temp=(struct list*)malloc(sizeof(struct list));
 if(temp==NULL)
 {
  printf("\n no memory space");
  exit(-1);
 }
 else
 {
  temp->data=0;
  temp->next=NULL;
  return temp;
 }
}


void insert(elementtype x,disk d)
{
 position temp,p;
 p=d;
 temp=(struct list*)malloc(sizeof(struct list));
 temp->data=x;
 //temp->next=NULL;
 while(p->next!=NULL)
   p=p->next;
 temp->next=p->next;
 p->next=temp;
}


void contiguous (disk d)
{
 char fname[10];
 int start,len,i,count,count1;
 position p;
 p=d->next;
 printf("\nEnter the file name: ");
 scanf("%s",fname);
 printf("\nEnter the starting block: ");
 scanf("%d",&start);
 printf("\nEnter the length of the file: ");
 scanf("%d",&len);
 printf("\nThe file allocation details are: ");
 while(p!=NULL)
 {
  if((count>start)&&(count1<len))
  {
   p->data=1;
   //printf("%d",count+1);
   count1++;
  }
  count++;
  p=p->next;
 }
 printf("\nThe details of page are: ");
 for(i=0;i<len;i++)
 {
  printf("\n%d",start+i);
 }
 printf("\nThe files are allocated");
}


void indexed(disk d)
{
 int ind,len,start,n,i,file[10],count=0;
 position p;
 char fname[20];
 elementtype x;
 p=d->next;
 printf("\nEnter the file name: ");
 scanf("%s",fname);
 printf("\nEnter the index block: ");
 scanf("%d",&ind);
 printf("\nEnter the blocks needed: ");
 scanf("%d",&n);
 printf("\nEnter the files for the index %d: ",ind);
 for(i=0;i<n;i++)
 {
  scanf("%d",&file[i]);
  x=searchfile(file[i],d);
  if(x==0)
  {
   count++;
   //printf("\n%d",count);
  }
  else if(count==n)
  {
   for(i=0;i<n;i++)
   {
    allocate(file[i],d,ind);
   }
   printf("\nFile are allocted");
  }
 }
 printf("\nThe details of pages are: ");
 for(i=0;i<n;i++)
 {
  printf("\n%d",file[i]);
 }
 printf("\nThe files are allocated");
}


void linked(disk d)
{
 int n,file[10],count=0,count1=0,len,i,start;
 position p,p1=ini(),t;
 char fname[20];
 p=d->next;
 printf("\nEnter the file name: ");
 scanf("%s",fname);
 printf("\nEnter how many blocks are already allocated: ");
 scanf("%d",&n);
 printf("\nEnter the blocks already allocated: ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&file[i]);
  allocate(file[i],d,1);
 }
 printf("\nEnter the index starting block: ");
 scanf("%d",&start);
 printf("\nEnter the length of file: ");
 scanf("%d",&len);
 count=0;
 p=d->next;
 while(p!=NULL)
 {
  if(count==start && count<=(start+len))
  {
   while(p!=NULL && count <= (start+len))
   {
    if(p->data!=1)
    {
     allocate(count,p,1);
     insert(count,p1);
     //printf("\n%d",count);
    }
    count1++;
    count++;
    p=p->next;
   }
  }
  p=p->next;
  count++;
 }
 
 printf("\nthe details of page are");
 t=p1->next;
 while(t!=NULL)
 {
  printf("\n%d",t->data);
  t=t->next;
 }
 
 printf("\nThe files are allocated");
}


elementtype searchfile(int y,disk d)
{
 int count=0;
 position p;
 elementtype x;
 p=d->next;
 while(p!=NULL)
 {
  if(count==y)
  {
   x=p->data;
  }
  p=p->next;
  count++;
 }
 return x;
}


void allocate(int y,disk d,int index)
{
 int count=0;
 position p;
 elementtype x;
 p=d->next;
 while(p!=NULL)
 {
  if(count==y)
  {
   p->data=index;
  }
  p=p->next;
  count++;
 }
}


void main()
{
 int n,i,ch;
 disk d;
 d=ini();
 printf("\nEnter the total no of memory space: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  insert(0,d);
 }
 while(1)
 {
  printf("\n1-Contiguous Allocation\n2-Indexed Allocation\n3-Linked Allocation\n4-Exit\n");
  printf("\nEnter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:contiguous(d);
          break;
   case 2:indexed(d);
          break;
   case 3:linked(d);
          break;
   case 4:exit(-1);
  }
 }
}


