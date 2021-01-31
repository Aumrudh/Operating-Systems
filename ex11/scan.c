#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct listnode
{
int data;
struct listnode *next;
}node;

typedef node *ptrtonode;
typedef ptrtonode list;
typedef ptrtonode position;

position initialize();
void insert(int ,list );
void merge (list,int);
list find(int,list);
list findmin(list);
list findmax2(list,list);
list findmax(list);
void sort(list);
void scan(list,int);


void scan(list l,int cp)
{
int ans,cap,last;
list max,min;

printf("\nEnter the capacity of the disk : ");
scanf("%d",&cap);
cap=cap-1;
printf("\nEnter last serving value : ");
scanf("%d",&last);
if(last>cp)
{
max=findmax(l);
 ans=cp+1+max->data;
printf("\nTotal distance in SCAN scheduling is %d \n",ans);
}
else
{
min=findmin(l);
ans=(cap-cp)+(cap-min->data);
printf("\nTotal distance in SCAN scheduling is %d \n",ans);
}
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

list findmax(list l)
{
position p=l->next;
list max=p;
while(p!='\0')
{
if(max->data<p->data)
max=p;
p=p->next;
}
return max;
}


list findmin(list l)
{
position p=l->next;
list min=p;
while(p!='\0')
{
if(min->data>p->data)
min=p;
p=p->next;
}
return min;
}


list findmax2(list l,list x)
{
position p=l->next;
list max=p;
while(p!=x)
{
if(max->data<p->data)
max=p;
p=p->next;
}
return max;
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
p->next=temp1;
break;
}
p=p->next;
}
}

void insert(int x,list l)
{

position temp1;
temp1=(position)malloc(sizeof(position)*1);
temp1->data=x;
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

return temp;
  }
}

main()
{
int n,i,ch;
list l1=initialize();
int a,c;
printf("\nEnter total no of elements in the list : ");
scanf("%d",&n);
printf("\nEnter the elements : ");
for(i=0;i<n;i++)
{
scanf("%d",&a);
insert(a,l1);
}
sort(l1);
printf("\nEnter the current position : ");
scanf("%d",&c);
merge(l1,c);
scan(l1,c);
}

