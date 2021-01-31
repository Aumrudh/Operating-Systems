#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct FCFS
{
        float wt;
        float tt;
        float bt;
        int pno;

}fcfs;

typedef struct listnode
{
fcfs pr;
struct listnode *next;
}node;
typedef node *ptrtonode;
typedef ptrtonode list;
typedef ptrtonode position;

list initialize();
void insert(int,float,list);
void display(list);
int count(list);
position calculate(list,int);

void display(list l)
{
int c=0;
position p=l->next;
printf("\nPno\tWT\t TT\t BT\n");
while(p!='\0')
{
printf("\n%d \t%.2f\t%.2f\t%.2f",p->pr.pno,p->pr.wt,p->pr.tt,p->pr.bt);
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
                printf("\nTotal waiting time\t%.2f\nTotal TurnArond time %.2f\n",totwt,tottt);
        }
        printf("\nAverage waitingtime\t%.2f\nAverage Turn Around time\t%.2f\n",totwt/n,tottt/n);
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

void insert(int pn,float btt,list l)
{

position temp1;
temp1=(position)malloc(sizeof(position)*1);
temp1->pr.pno=pn;
temp1->pr.bt=btt;
temp1->pr.tt=0;
temp1->pr.tt=0;


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
temp->next=NULL;

return temp;
  }
}


main()
{
int ch;

int a,i;
float B;
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
insert(a,B,l1);


}

l1=calculate(l1,nn);


int tt;
tt=count(l1);
printf("\n\nTotal no of nodes %d \n",tt);

}
