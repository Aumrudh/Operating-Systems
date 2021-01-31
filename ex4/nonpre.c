#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct NOPRI
{
        int at;
	float ct;
        float bt2;
        float wt;
        float tt;
        float bt;
        int pno;

}nonpri;

typedef struct listnode
{
nonpri pr;
struct listnode *next;
}node;
typedef node *ptrtonode;
typedef ptrtonode list;
typedef ptrtonode position;

list initialize();
void insert(int,float,int,list);
void display(list);
int count(list);
void calculate(list,int);
position sortbt(list);
position sortat(list);
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
nonpri  temp;
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
nonpri  temp;
temp=p->pr;
p->pr=q->pr;
q->pr=temp;
}
}
}
return l;
}



position sortat(list l)
{

position p,q;

for(p=l->next;p->next!=NULL;p=p->next)
{

for(q=p->next;q!=NULL;q=q->next)
{
if(p->pr.at>q->pr.at)

{
nonpri temp;
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
printf("\nPNO\tAT\t BT\t WT\t TAT\t CT\n");
while(p!='\0')
{
printf("\n%d\t%d \t%.2f\t%.2f\t%.2f\t%.2f\n",p->pr.pno,p->pr.at,p->pr.bt2,p->pr.wt,p->pr.tt,p->pr.ct);
p=p->next;
}


}
void calculate(list ll,int n)
{
        position p,q,temp;
float tottt=0,totwt=0;
int index=0;
ll=sortat(ll);
        p=ll->next;
        index=p->pr.bt;
p->pr.bt=0;
        p->pr.ct=index;
        ll=sortbt(ll);
        p=ll->next;
p=p->next;
        while(p!=NULL)
        {
                index+=p->pr.bt;
                p->pr.ct=index;
                p=p->next;
               
        }
sortpno(ll);
p=ll->next;

while(p!=NULL)
{

p->pr.wt=p->pr.ct - p->pr.at - p->pr.bt2;
p->pr.tt=p->pr.bt2+p->pr.wt;
totwt+=p->pr.wt;
tottt+=p->pr.tt;
display(ll);
p=p->next;
ll->next=p;
}
display(ll);
printf("\n\n\n");
printf("Total Waiting itme is : %.2f\n",totwt);
printf("Total Turnarond  itme is : %.2f\n",tottt);
printf("Average  Waiting itme is :%.2f\n",totwt/n);
printf("Average Turn Arond time  is : %.2f\n",tottt/n);

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

void insert(int pn,float btt,int A,list l)
{

position temp1;
temp1=(position)malloc(sizeof(position)*1);
temp1->pr.pno=pn;
temp1->pr.bt=btt;
temp1->pr.bt2=btt;
temp1->pr.tt=0;
temp1->pr.at=A;

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
temp->pr.at=0;
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
printf("\nEnter process no : ");
scanf("%d",&a);
printf("\nEnter burst time : ");
scanf("%f",&B);
printf("\nEnter arrival time : ");
scanf("%d",&z);
insert(a,B,z,l1);


}
calculate(l1,nn);


int tt;
tt=count(l1);
printf("\n\nTotal no of nodes %d \n",tt);

 }
