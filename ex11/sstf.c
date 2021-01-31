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
void insert(int ,list );
void merge (list,int);
list find(int,list);
list choose(list,list,int);
void sort(list);
void display(list);
void sstf(list,int,int);
void deletee (list);


void deletee(list x)
{
if(x->next==NULL)
x->pre->next=NULL;
else
{
list t1,t2;
t1=x->pre;
t2=x->next;
t1->next=t2;
t2->pre=t1;
}
}

void sstf(list l,int cp,int n)
{

list p=find(cp,l);
int count=0;
list p2;
int ans=0;
while(1)
{
if(count==n)
break;
p2=choose(p->pre,p->next,cp);
list x=p;
deletee(p);
p2->val=x->data-p2->data;
if(p2->val<0)
p2->val=p2->val*-1;
count++;
ans=ans+ p2->val;
p=p2;
}
printf("\n total distance in SSTF scheduling %d\n",ans);
}


position find(int x,list l)
{
position p;
p=l->next;
while(p!=NULL)
{
if(p->data==x)
{
return p;
}
else
p=p->next;
}
position z=NULL;
return z;
}


list choose(list a,list b,int x)
{
if(b==NULL)
return a;

if(a->data==-1)
return b;

int aa=x-a->data;
int bb=b->data-x;
if(aa<bb)
return a;
else
return b;
}


void display(list l)
{
position p=l->next;
while(p!='\0')
{
printf("%d  %d\n",p->data,p->pre->data);
p=p->next;
}
}

void sort(list l)
{
position temp;
temp=(position)malloc(sizeof(position)*1);

position p,q;

for(p=l->next;p->next!=NULL;p=p->next)
{
for(q=p->next;q!=NULL;q=q->next)
{
if(p->data>q->data)
{
int rr1,rr2,rr3;
rr1=p->data;
rr2=q->data;
p->data=rr2;
q->data=rr1;
}
}
}
}

void merge(list l,int x)
{
position p;
position temp1;
temp1=(position)malloc(sizeof(position)*1);
temp1->data=x;
int count=1;
p=l->next;
list nn;
while(p!=NULL)
{
nn=p->next;
if((temp1->data>p->data)&&(temp1->data<nn->data)||(temp1->data<p->data)&&(temp1->data>nn->data))
{
temp1->next=nn;
nn->pre=temp1;
p->next=temp1;
temp1->pre=p;

break;
}
p=p->next;
}
}

void  insert(int x,list l)
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
printf("\n error in initialize\n");
 }
else
{
temp->data=-1;
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
printf("\nEnter total no of elements in the queue : ");
scanf("%d",&n);
printf("Enter the elements : ");
for(i=0;i<n;i++)
{
scanf("%d",&a);
insert(a,l1);
}
printf("Enter the current position : ");
scanf("%d",&a);
merge(l1,a);
sort(l1);
sstf(l1,a,n);
}

