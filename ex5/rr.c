#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct RR
{
        int entry;
float ct;
        float bt2;
        float wt;
        float tt;
        float bt;
        int pno;

}rr;

typedef struct listnode
{
rr pr;
struct listnode *next;
}node;
typedef node *ptrtonode;
typedef ptrtonode list;
typedef ptrtonode position;

list initialize();
void insert(int,float,list);
void display(list);
int count(list);
void calculate(list,int);
position sortbt(list);
position sortpno(list);

position sortpno(list l)
{
position temp;
temp=(position)malloc(sizeof(position)*1);

position p,q;

for(p=l->next;p->next!=NULL;p=p->next)
{

for(q=p->next;q!=NULL;q=q->next)
{
if(p->pr.pno>q->pr.pno)

{
rr  temp;
temp=p->pr;
p->pr=q->pr;
q->pr=temp;
}
}
}
return l;
}



position sortbt(list l)
{
position p,q;

for(p=l->next;p->next!=NULL;p=p->next)
{

for(q=p->next;q!=NULL;q=q->next)
{
if(p->pr.bt>q->pr.bt)

{
rr  temp;
temp=p->pr;
p->pr=q->pr;
q->pr=temp;
}
}
}
return l;
}


void display(list l)
{
float avgwt,avgtt,tottt=0,totwt=0;
int c=0;
position p=l->next;
printf("\n pno\tbt\t wt\t tt\t ct\n");
while(p!='\0')
{
printf("\n %d\t%.2f\t%.2f\t%.2f\t%.2f\n",p->pr.pno,p->pr.bt2,p->pr.wt,p->pr.tt,p->pr.ct);
p=p->next;
}


}

void calculate(list ll,int n)
{
int ts;
printf("\nEnter time slice : ");
scanf("%d",&ts);
        position j,p,q,temp;
float tottt=0,totwt=0;
int index=0,count=0;
ll=sortpno(ll);
p=ll->next;
while(count!=n)
{
if(p==NULL)
{
p=ll;
}

if(p->pr.bt!=0)
{
p->pr.bt-=ts;
index+=ts;
p->pr.entry++;
if(p->pr.bt<=0)
{
index+=p->pr.bt;
p->pr.entry-=1;
p->pr.bt=0.0;
p->pr.ct=index;
count++;
}
}


p=p->next;
}




sortpno(ll);
 j= ll->next;
while(j!=NULL)
{
j->pr.wt=j->pr.ct-(j->pr.entry*ts);
j->pr.tt=j->pr.ct;
totwt=j->pr.wt+totwt;
tottt=j->pr.tt+tottt;
display(ll);
j=j->next;
ll->next=j;
}



       
display(ll);
printf("\n\n\n");
printf("Total waiting itme is : %.2f\n",totwt);
printf("Total turnarond  itme is : %.2f\n",tottt);
printf("Average  waiting itme is : %.2f\n",totwt/n);
printf("Average turnarond time  is : %.2f\n",tottt/n);

}

int count(list l)
{
position p;
int count=1;
p=l->next;
while(p!=NULL)
{
count++;
p=p->next;
}
return count;
}

void insert(int pn,float btt,list l)
{

position temp1;
temp1=(position)malloc(sizeof(position)*1);
temp1->pr.pno=pn;
temp1->pr.bt=btt;
temp1->pr.bt2=btt;
temp1->pr.tt=0;
temp1->pr.entry=0;

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

temp->pr.bt=0;
temp->pr.tt=0;
temp->pr.wt=0;
temp->pr.pno=0;
temp->pr.entry=0;
temp->next=NULL;

return temp;
  }
}


main()
{
int ch;

int a,i;
float B;
int z;
list l1;
l1=initialize();
int nn;
printf("\nEnter total no of process\n");
scanf("%d",&nn);
for(i=0;i<nn;i++)
{
printf("\nEnter process no\n");
scanf("%d",&a);
printf("\nEnter burst time\n");
scanf("%f",&B);

insert(a,B,l1);


}
calculate(l1,nn);


int tt;
tt=count(l1);
printf("\n\nTotal no of nodes %d \n",tt);

 }
