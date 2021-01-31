#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct listnode
{
        int pp;
        int pno;
        int xx;
        int bal;
        int tot;
        struct listnode *next;
}node;
typedef node *ptrtonode;
typedef ptrtonode list;
typedef ptrtonode position;

typedef struct pronode
{
int pnoo;
int mem;
struct pronode *next;
}node2;
typedef node2 *ptrtonode2;
typedef ptrtonode2 list2;
typedef ptrtonode2 position2;

list initialize();
void insert(list,int);
void display(list);
list findmax(list);
int findmin(int [],int);
list find(list,int);

list2 initialize2();
void insert2(list2,int,int);
void display2(list2);
void setzero(list);


void firstfit(list ,list2,int);
void worstfit(list ,list2,int);
void bestfit(list,list2,int);

int count(list);
void sideline();
void straightline();

int findmin(int j[],int k)
{
int i,min=j[0];
for(i=1;i<k;i++)
{
if(min>j[i])
min=j[i];
}
return min;
}

/*void sideline()
{
int i,x=2;
for(i=0;i<x;i++)
{
printf("\n|                     |");
}
}
void straightline()
{
printf("\n|_______________________|");
}*/


int count(list l)
{
position p;
int countt=1;
p=l->next;
while(p!=NULL)
{
countt++;
p=p->next;
}
return countt;
}

void worstfit(list l,list2 ll,int no)
{
list2 x=ll->next;
list p,q;
int cc=0,tot,done=0,not=0;
tot=count(l);
while(cc!=tot)
{
p=findmax(l);
if(p->tot>=x->mem)
{
p->pno=x->pnoo;
p->bal=p->tot-x->mem;
p->pp=x->mem;
p->xx=1;
x=x->next;
cc++;
done++;
if(done==no)
break;
}

else
{
not++;
break;
}

}
if(done==no)
{
display(l);
printf("\n done\n\n");
}
else
{
display(l);
printf("\n fail\n\n");
}

}

void firstfit(list l,list2 ll,int no)
{
list2 x=ll->next;
list p;
p=l->next;
int cc=0,tot,done=0,not=0;
tot=count(l);
while(1)
{
if((x->mem<=p->tot)&&(p->xx!=1))
{
p->pno=x->pnoo;
p->bal=p->tot-x->mem;
p->pp=x->mem;
p->xx=1;
x=x->next;
cc=0;
p=l->next;
done++;
}
cc++;
if(cc==tot)
{
not++;
break;
}
if(done==no)
{
break;
}
p=p->next;
if(p==NULL)
p=l->next;

}
if(done==no)
{
display(l);
printf("\n done\n\n");
}
else
{
display(l);
printf("\n fail\n\n");
}

}





void bestfit(list l,list2 ll,int no)
{
list2 x=ll->next;
int cc=0,tot,done=0,not=0;
list p;
while(1)
{

list temp;
temp=l->next;
int arr[10],index=0;
while(temp!=NULL)
{
if((temp->tot>=x->mem)&&(temp->xx==0))
{
arr[index]=temp->tot;
index++;
}
temp=temp->next;
}

if(index==0)
{
display(l);
printf("\n fail\n");
break;
}
else
{
int r=findmin(arr,index);

 p=find(l,r);
}

if(p->tot>=x->mem)
{
p->pno=x->pnoo;
p->bal=p->tot-x->mem;
p->pp=x->mem;
p->xx=1;
x=x->next;
cc++;
done++;

if(done==no)
break;
}

else
{
not++;
break;
}

}
if(done==no)
{
display(l);
printf("\nDONE in allocation\n\n");

}
else
{
display(l);
printf("\nFAILED IN ALLOCATION\n\n");
}

}


position find(list l,int g)
{
position p;
p=l->next;
while(p!=NULL)
{
if(p->tot==g)
{
return p;
}
else
p=p->next;
}
position z=NULL;
return z;
}

list findmax(list l3)
{

list max;
position v=l3->next;
 max=l3;
while(v!=NULL)
{
if((max->tot<v->tot)&&(v->xx==0))
{
max=v;
}
v=v->next;
}

return max;

}

void insert(list l,int a)
{

position temp1;
temp1=(position)malloc(sizeof(position)*1);
temp1->tot=a;
temp1->xx=0;
position p1,q;
q=l;
p1=l->next;
while(p1!=NULL)
{
q=q->next;
p1=p1->next;
}

temp1->next=NULL;
q->next=temp1;
}


void insert2(list2 l,int z,int y)
{

position2 temp1;
temp1=(position2)malloc(sizeof(position2)*1);
temp1->mem=y;
temp1->pnoo=z;

position2 p1,q;
q=l;
p1=l->next;
while(p1!=NULL)
{
q=q->next;
p1=p1->next;
}

temp1->next=NULL;
q->next=temp1;
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
temp->next=NULL;
temp->tot=-1;
temp->xx=0;
temp->pno=0;
return temp;
  }
}


position2 initialize2()
{
position2 temp;
temp=(position2)malloc(sizeof(position2)*1);
if(temp==NULL)
{
printf("\nError in initialize\n");
 }
else
{
temp->mem=0;
temp->pnoo=0;
return temp;
  }
}


void display(list l)
{

int c=0;
position p=l->next;
//straightline();
while(p!='\0')
{

//sideline();
printf("\nProcess Number : (%d)\t\t\t",p->pno);
printf("\nTotal=%d",p->tot);
if (p->tot<100)
printf("\t");
else if (p->tot<10)
printf("\t");
printf("\t\t");

printf("\nMemory=%d",p->pp);;
if (p->pp<100)
printf("\t");
else if ((p->pp<10)||(p->pp==0))
printf("\t");
printf("\t\t");

printf("\nBalance=%d",p->bal);
if (p->bal<100)
printf("\t");
else if ((p->bal<10)||(p->bal==0))
printf("\t");
printf("\t\t");

//sideline();
//straightline();
p=p->next;
}
}


void display2(list2 l)
{

int c=0;
position2 p=l->next;

while(p!='\0')
{
printf("\n %d\t%d\n",p->pnoo,p->mem);
p=p->next;
}
}


void setzero(list l)
{

int c=0;
position p=l->next;

while(p!='\0')
{
p->xx=0;
p->bal=0;
p->pp=0;
p->pno=0;
p=p->next;
}
}


main()
{
        list l1,mm;
        l1=initialize();
        int aa,bb;
        int  i,n,no;
        printf("\nEnter total no of partitions : ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {

                printf("Enter partition values : ");
                scanf("%d",&aa);
                insert(l1,aa);
        }

        list2 l2;
        l2=initialize2();
        int n2;
        printf("Enter tot no of processers : ");
         scanf("%d",&n2);
        for(i=0;i<n2;i++)
        {

                printf("Enter pno : ");
                scanf("%d",&aa);
                 printf("Enter memory : ");
                scanf("%d",&bb);
                insert2(l2,aa,bb);
        }
        printf("\nFIRST FIT\n");
        firstfit(l1,l2,n2);
        setzero(l1);
        printf("\n\nWORST FIT\n");
        worstfit(l1,l2,n2);
        setzero(l1);
        printf("\n\nBEST FIT\n");
        bestfit(l1,l2,n2);


}
