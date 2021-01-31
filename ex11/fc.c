#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct listnode
{
int data;
int val;
struct listnode *next;
struct listnode *pre;
}node;

typedef node *ptrtonode;
typedef ptrtonode list;
typedef ptrtonode position;
position initialize();
int count(list);
void insert(int,list);
void fcfs(list);


void fcfs(list l)
{
 int tot=0;
list p=l->next->next;
while(p!=NULL)
{
p->val=p->pre->data-p->data;
if(p->val<0)
{
 p->val=p->val*-1;
}
 tot=tot+p->val;
 p=p->next;
 }
printf("\n Total distance in Fcfs:%d\n",tot);
}
void insert(int x,list l)
{
position temp1;
temp1=(position)malloc(sizeof(position)*1);
temp1->data=x;
temp1->val=0;
position p1,q;
q=l;
p1=l->next;
while(p1!=NULL)
{
q=q->next;
p1=p1->next;
}
temp1->next=NULL;
p1=temp1;
q->next=p1;
p1->pre=q;
}
position initialize()
{
position temp;
temp=(position)malloc(sizeof(position)*1);
if(temp==NULL)
{
printf("\nError in initialize\n");
}
else
{
temp->data=0;
temp->next=NULL;
temp->pre=NULL;
return temp;
}
}


main()
{
int n,i;
list l1=initialize();
int a,c;
printf("Enter the total no of elements in the queue : ");
scanf("%d",&n);
for(i=0;i<n+1;i++)
{
if(i==0)
{
 printf("Enter the current position : ");
 scanf("%d",&a);
 insert(a,l1);
 printf("Enter the elements : ");
 }
  else
 {
 scanf("%d",&a);
 insert(a,l1);
 }
  }
fcfs(l1);
}

