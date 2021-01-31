#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct store
{
int val;
int pos;
}st;

typedef struct listnode
{
        int data;
        struct listnode *next;
        struct listnode *pre;

}node;
typedef node *ptrtonode;
typedef ptrtonode list;
typedef ptrtonode position;


list initialize();
void insert(list,int);
void display(list);
void fifo(list);
void optimal(list);
void LRU(list);
int isempty(list);
int findvalue(int [],int ,list);
int findvalue2(int [],int ,list,list);
int findpos(int [],int ,int);
st findmax(st [],int);
int check(int [],int,int);


void insert(list l,int x)
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

temp->data=0;
temp->next=NULL;
temp->pre=NULL;
return temp;
  }
}



void display(list l)
{
position p=l->next;

while(p!='\0')
{
printf("\n %d,prev-%d\n",p->data,p->pre->data);
p=p->next;
}
}


int isempty(list l)
{
if(l->next==NULL)
return -1;
else return 1;
}


int check(int arr[],int nn,int k)
{
int j;
for(j=0;j<nn;j++)
{
if(arr[j]==k)
return -1;
}
return 1;
}


st findmax(st ss2[],int z)
{
int j;
st max;
max=ss2[0];
for(j=1;j<z;j++)
{
if(max.pos<ss2[j].pos)
max=ss2[j];
}
return max;
}


void fifo(list l)
{
int ch;
while(1)
{
printf("\n 1-Frame count \t2-break\n\n");
scanf("%d",&ch);
if(ch==1)
{
int f,x,find,i=0,tot=0;
list p=l->next;
printf("\nEnter frame size : ");
scanf("%d",&f);
int a[f];
while(p!=NULL)
{
find=check(a,f,p->data);
if(find!=-1)
{
a[i]=p->data;
tot++;
i++;
}
if(i==f)
i=0;
p=p->next;
}
printf("\n If frame size is %d then totel no frames in FIFO: %d\n",f,tot);
}
else
break;
}
}


void optimal(list l)
{
int ch;
while(1)
{
printf("\n 1-Frame count \t2-break\n\n");
scanf("%d",&ch);
if(ch==1)
{
int f,x,find,i=0,tot=0,ii=0,mmm;
list p=l->next;
printf("\nEnter  frame size : ");
scanf("%d",&f);
int a[f];
while(p!=NULL)
{
find=check(a,f,p->data);
if(find!=-1)
{
if(tot<=f)
{
a[i]=p->data;
tot++;
i++;
ii++;
}
else
{
mmm=findvalue(a,f,p);
i=findpos(a,f,mmm);
a[i]=p->data;
tot++;
}

}
if(i==f)
i=0;
p=p->next;
}
printf("\n If frame size is %d then total no frames in OPTIMAL: %d\n",f,tot);
}
else
break;
}
}


int findvalue(int ar[],int nn,list ll)
{
st ss[nn];
int j;
for(j=0;j<nn;j++)
{
list l=ll;
int occ=1;
ss[j].val=ar[j];
ss[j].pos=-1;
while(l!=NULL)
{
if(l->data==ss[j].val)
{
ss[j].pos=occ;
break;
}
l=l->next;
occ++;
}

if(ss[j].pos==-1)
{
ss[j].pos=occ;
}

}
st m=findmax(ss,nn);
return m.val;
}


int findpos(int aaa[],int l,int k)
{
int j;
for(j=0;j<l;j++)
{
if(aaa[j]==k)
return j;
}
}


void LRU(list l)
{
int ch;
while(1)
{
printf("\n 1-Frame count \t2-Break\n\n");
scanf("%d",&ch);
if(ch==1)
{
int f,x,find,i=0,tot=0,ii=0,mmm;
list p=l->next;
printf("\nEnter frame size : ");
scanf("%d",&f);
int a[f];
while(p!=NULL)
{
find=check(a,f,p->data);
if(find!=-1)
{
if(tot<=f)
{
a[i]=p->data;
tot++;
i++;
ii++;
}
else
{
mmm=findvalue2(a,f,p,l);
i=findpos(a,f,mmm);
a[i]=p->data;
tot++;
}

}
if(i==f)
i=0;
p=p->next;
}
printf("\n If frame size is %d then total no frames in LRU: %d\n",f,tot);
}
else
break;
}
}


int findvalue2(int ar[],int nn,list ll,list head)
{
st ss[nn];
int j;
for(j=0;j<nn;j++)
{
list l=ll;
int occ=1;
ss[j].val=ar[j];
ss[j].pos=-1;
while(l!=head)
{
if(l->data==ss[j].val)
{
ss[j].pos=occ;
break;
}
l=l->pre;
occ++;
}

if(ss[j].pos==-1)
{
ss[j].pos=occ;
}

}
st m=findmax(ss,nn);
return m.val;
}



main()
{
int n,i,a;
list l1=initialize();
printf("\nEnter the size of string : ");
scanf("%d",&n);
printf("\nEnter the sequence\n");
for(i=0;i<n;i++)
{
scanf("%d",&a);
insert(l1,a);
}
int ch1;
while(1)
{
printf("\n 1-FIFO\t 2-OPTIMAL\t 3-LRU\t 4-exit\n");
scanf("%d",&ch1);
if(ch1==1)
fifo(l1);
else if (ch1==2)
optimal(l1);
else if(ch1==3)
LRU(l1);
else if (ch1==4)
break;
else
printf("\nWrong option\n");
}

}
