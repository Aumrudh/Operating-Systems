#include<stdio.h>
#include<stdlib.h>
typedef struct RESOURCE
{
	int a,b,c,d;
}resource;
typedef struct listnode
{
	resource alloc;
	resource max;
	resource need;
	resource need2;
	int x;
	int pno;
	struct listnode *next;
	
}node;

typedef node *ptrtonode;
typedef ptrtonode list;
typedef ptrtonode position;


list initialize();
void insert(list,resource,resource,int);
void display(list,resource);
void calculate(list,resource);
int count(list);

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

void calculate(list l,resource av)
{
display(l,av);
int tot,counnt=0,zz=0,myarray[10];
tot=count(l);

position p=l->next;
while(counnt<tot)
{
if((p->need2.a<=av.a)&&(p->need2.b<=av.b)&&(p->need2.c<=av.c)&&(p->need2.d<=av.d)&&(p->x==0))
{
av.a+=p->alloc.a;
av.b+=p->alloc.b;
av.c+=p->alloc.c;
av.d+=p->alloc.d;
p->x=1;
myarray[counnt]=p->pno;
p=l->next;
counnt++;
if(counnt==tot-1)
break;
}
else
{
zz++;
if(zz>tot*tot)
{
break;
}
}
p=p->next;
if(p==NULL)
p=l->next;
}
if(counnt!=tot-1)
printf("\nDeadlock Occured\n");
else
{
int i;
printf("\n SAFE SEQUENCE\n");
for(i=0;i<counnt;i++)
{
printf("p%d\t",myarray[i]);
}
printf("\n\n");
}
}
void insert(list l,resource A,resource B,int pn)
{


position temp1;
temp1=initialize();
temp1->pno=pn;
temp1->need=B;
temp1->alloc=A;
temp1->need2.a = temp1->need.a-temp1->alloc.a;
temp1->need2.b = temp1->need.b-temp1->alloc.b;
temp1->need2.c = temp1->need.c-temp1->alloc.c;
temp1->need2.d = temp1->need.d-temp1->alloc.d;
temp1->x=0;
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
temp->alloc.a=0;
temp->alloc.b=0;
temp->alloc.c=0;
temp->alloc.d=0;
temp->max.a=0;
temp->max.b=0;
temp->max.c=0;
temp->max.d=0;
temp->need.a=0;
temp->need.b=0;
temp->need.c=0;
temp->need.d=0;
temp->next=NULL;

return temp;
  }
}




void display(list l,resource al)
{
float avgwt,avgtt,tottt=0,totwt=0;
int c=0;
position p;
p=l->next;
int i=1;

printf("\nPNO\tALLOC\tMAX\tAVL\tNEED\n");
while(p!='\0')
{
printf("\n%d\t%d%d%d%d\t",p->pno,p->alloc.a,p->alloc.b,p->alloc.c,p->alloc.d);

printf("%d%d%d%d\t",p->need.a,p->need.b,p->need.c,p->need.d);
if(i==1)
printf("%d%d%d%d\t",al.a,al.b,al.c,al.d);
else
printf("    \t");
printf("%d%d%d%d\n",p->need2.a,p->need2.b,p->need2.c,p->need2.d);
p=p->next;
i++;
}

}


main()
{
	list l1;
	l1=initialize();
	int i,n,pp;
	resource avl;
	printf("\nEnter total no of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{

		resource aa,bb;
		printf("Enter process no : ");
		scanf("%d",&pp);
		printf("Enter process %d details : ",pp);
		printf("Enter max A, B,C,D values\n");
		scanf("%d%d%d%d",&bb.a,&bb.b,&bb.c,&bb.d);
		printf("\n enter allocation A, B,C,D values\n");
		scanf("%d%d%d%d",&aa.a,&aa.b,&aa.c,&aa.d);
		insert(l1,aa,bb,pp);
	}
	printf("\n enter available A,B,C,D values\n");
	  scanf("%d%d%d%d",&avl.a,&avl.b,&avl.c,&avl.d);
	calculate(l1,avl);	
}
