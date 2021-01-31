#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct PRI
{
        float wt;
        float tt;
        float bt;
        int pno;
        int pt;
}pri;

typedef struct listnode
{
pri pr;
struct listnode *next;
}node;
typedef node *ptrtonode;
typedef ptrtonode list;
typedef ptrtonode position;

list initialize();
void insert(int,float,int,list);
void display(list);
int count(list);
position calculate(list,int);
position sort(list);

position sort(list l)
{
position temp;
temp=(position)malloc(sizeof(position)*1);

position p,q;

for(p=l->next;p->next!=NULL;p=p->next)
{

for(q=p->next;q!=NULL;q=q->next)
{
if(p->pr.pt>q->pr.pt)

{
pri temp;
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
printf("\nPno\tWT\t TT\t BT\t Priority\n");
while(p!='\0')
{
printf("\n %d \t%.2f\t%.2f\t%.2f\t%d\n",p->pr.pno,p->pr.wt,p->pr.tt,p->pr.bt,p->pr.pt);
c++;
p=p->next;
}

}
position calculate(list l,int n)
{
        float totwt=0,tottt=0,avgwt,agtt;

        position xx;
        position p,q,temp;
        p=l->next;
        xx=l->next;
        p->pr.wt=0;
        p->pr.tt=p->pr.bt;
        q=p;
        p=p->next;
        while(p!=NULL)
        {
                p->pr.wt=q->pr.tt;
                p->pr.tt=q->pr.tt+p->pr.bt;
                totwt=totwt+p->pr.wt;
                tottt=tottt+p->pr.tt;
                p=p->next;
                q=q->next;
         display(l);
                l->next=xx->next;
                display(l);
                xx=xx->next;
                printf("\nTotal waiting time\t %.2f\nTotal turnarond time %.2f\n",totwt,tottt);
        }
        printf("\nAverage waitingtime\t%.2f\nAverage turn arond timt\t%.2f\n",totwt/n,tottt/n);
                return l;
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
temp1->pr.tt=0;
temp1->pr.pt=A;

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
printf("\n error in initialize\n");
 }
else
{

temp->pr.bt=0;
temp->pr.tt=0;
temp->pr.wt=0;
temp->pr.pno=0;
temp->pr.pt=0;
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
printf("\nEnter total no of Process : ");
scanf("%d",&nn);
for(i=0;i<nn;i++)
{
printf("\nEnter process no : ");
scanf("%d",&a);
printf("\nEnter burst time : ");
scanf("%f",&B);
printf("\nEnter Priority ");
scanf("%d",&z);
insert(a,B,z,l1);


}
l1=sort(l1);
printf("\nAfter Sorting \n\n");
display(l1);
l1=calculate(l1,nn);
display(l1);


int tt;
tt=count(l1);
printf("\n\nTotal no of nodes %d \n",tt);

}
