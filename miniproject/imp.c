#include"head.h"

positionpri sort(listpri l)
{
    positionpri temp;
    temp=(positionpri)malloc(sizeof(positionpri)*1);
    positionpri p,q;
    for(p=l->nextpri;p->nextpri!=NULL;p=p->nextpri)
     {
        for(q=p->nextpri;q!=NULL;q=q->nextpri)
        {
          if(p->pr2.pt>q->pr2.pt)
           {
             pri temp;
             temp=p->pr2;
             p->pr2=q->pr2;
             q->pr2=temp;
           }
        }
     }
   return l;
}

positionrr sortpno(listrr l)
{
    positionrr temp,p,q;
    temp=(positionrr)malloc(sizeof(positionrr)*1);
    for(p=l->next;p->next!=NULL;p=p->next)
     {
       for(q=p->next;q!=NULL;q=q->next)
       {
         if(p->pr.pno>q->pr.pno)
          {
           rr temp;
           temp=p->pr;
           p->pr=q->pr;
           q->pr=temp;
          }
        }
     }
    return l;
}
positionrr sortbt(listrr l)
{
   positionrr p,q;
   for(p=l->next;p->next!=NULL;p=p->next)
    {
      for(q=p->next;q!=NULL;q=q->next)
       {
         if(p->pr.bt>q->pr.bt)
         {
          rr temp;
          temp=p->pr;
          p->pr=q->pr;
          q->pr=temp;
         }
       }
    }
    return l;
}

void displayrr(listrr l)
{
    float avgwt,avgtt,tottt=0,totwt=0;
    int c=0;
    positionrr p=l->next;
    printf("\nPID\tBURSTTIME\tWAITING TIME\tTURNAROUNDTIME\tCT\n");
    while(p!='\0')
     {
       printf("\n%d\t%.2f\t%.2f\t%.2f\t%.2f\n",p->pr.pno,p->pr.bt2,p->pr.wt,p->pr.tt,p->pr.ct);
       p=p->next;
     }
}

void displaypri(listpri l)
{
    float avgwt,avgtt,tottt=0,totwt=0;
    int c=0;
    positionpri p=l->nextpri;
    printf("\nPID\tBURSTTIME\tWAITING TIME\tTURNAROUNDTIME\tPRIORITY\n");
    while(p!='\0')
    {
      printf("\n %d\t\t%.2f\t\t%.2f\t\t%.2f\t\t%d\n",p->pr2.pno,p->pr2.bt,p->pr2.wt,p->pr2.tt,p->pr2.pt);
      c++;
      p=p->nextpri;
    }
}
void displayfcfs(listfc l)
{
   int c=0;
   positionfc p=l->nextfc;
   printf("\nPID\tBURSTTIME\tWAITING TIME\tTURNAROUNDTIME\n");
   while(p!=NULL)
    {
      printf("\n %d\t%f\t%f\t%f",p->pr1.pno,p->pr1.bt,p->pr1.wt,p->pr1.tt);
      c++;
      p=p->nextfc;
    }
}
void calculaterr(listrr ll,int n)
{
        int ts,index=0,count=0;
        float tottt=0,totwt=0;
        positionrr j,p,q,temp;
        printf("\nEnter time slice : ");
        scanf("%d",&ts);
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
     displayrr(ll);
     j=j->next;
     ll->next=j;
    }
        displayrr(ll);
        printf("\n\n\n");
        printf("Total waiting time is : %f\n",totwt);
        printf("Total turnarond time is : %f\n",tottt);
        printf("Average  waiting time is : %f\n",totwt/n);
        printf("Average turnarond time  is : %f\n",tottt/n);

}

positionfc calculatefcfs(listfc l,int n)
{
        printf("inside cal");
        float totwt=0.0,tottt=0.0,avgwt,agtt;
        positionfc p,q,temp,xx;
        p=l->nextfc;
        xx=l->nextfc;
        p->pr1.wt=0;
        p->pr1.tt=p->pr1.bt;
        q=p;
        p=p->nextfc;
        while(p!=NULL)
        {       printf("insede while\n");
                p->pr1.wt=q->pr1.tt;
                p->pr1.tt=q->pr1.tt+p->pr1.bt;
                totwt=totwt+p->pr1.wt;
                tottt=tottt+p->pr1.tt;
                p=p->nextfc;
                q=q->nextfc;
                displayfcfs(l);
                l->nextfc=xx->nextfc;
                displayfcfs(l);
                xx=xx->nextfc;
        }
        printf("\nTotal waiting time : %f\nTotal turnarond time : %f\n",totwt,tottt);
        printf("\nAverage waitingtime : %f\nAverage turn around time : %f\n",totwt/n,tottt/n);
        return l;
}

positionpri calculatepri(listpri l,int n)
{
        float totwt=0,tottt=0,avgwt,agtt;
        positionpri p,q,temp,xx;
        p=l->nextpri;
        xx=l->nextpri;
        p->pr2.wt=0;
        p->pr2.tt=p->pr2.bt;
        q=p;
        p=p->nextpri;
        while(p!=NULL)
        {
                p->pr2.wt=q->pr2.tt;
                p->pr2.tt=q->pr2.tt+p->pr2.bt;
                totwt=totwt+p->pr2.wt;
                tottt=tottt+p->pr2.tt;
                p=p->nextpri;
                q=q->nextpri;
                displaypri(l);
                l->nextpri=xx->nextpri;
                displaypri(l);
                xx=xx->nextpri;
        }
       printf("\nTotal waiting time : %f\nTotal turnarond time : %f\n",totwt,tottt);
       printf("\nAverage waitingtime : %f\nAverage turn around time : %f\n",totwt/n,tottt/n);
       return l;
}

void insertrr(int pn,float btt,listrr l)
{
     positionrr temp1,p1,q;
     temp1=(positionrr)malloc(sizeof(positionrr));
     temp1->pr.pno=pn;
     temp1->pr.bt=btt;
     temp1->pr.bt2=btt;
     temp1->pr.tt=0;
     temp1->pr.entry=0;
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
     printf("Process Queued Successfully\n");
}
void insertfcfs(int pn,float btt,listfc l)
{
    positionfc p1,q,temp1;
    temp1=(positionfc)malloc(sizeof(positionfc)*1);
    temp1->pr1.pno=pn;
    temp1->pr1.bt=btt;
    temp1->pr1.tt=0;
    temp1->pr1.tt=0;
    q=l;
    p1=l->nextfc;
    while(p1!=NULL)
     {
      q=q->nextfc;
      p1=p1->nextfc;
     }
    temp1->nextfc=NULL;
    p1=temp1;
    q->nextfc=p1;
    printf("Process Queued Successfully\n");
}

void insertpri(int pn,float btt,int A,listpri l)
{
         positionpri temp1,p1,q;
         temp1=(positionpri)malloc(sizeof(positionpri)*1);
         temp1->pr2.pno=pn;
         temp1->pr2.bt=btt;
         temp1->pr2.tt=0;
         temp1->pr2.pt=A;
         q=l;
         p1=l->nextpri;
         while(p1!=NULL)
          {
                q=q->nextpri;
                p1=p1->nextpri;
          }
         temp1->nextpri=NULL;
         p1=temp1;
         q->nextpri=p1;
         printf("Process Queued Successfully\n");
}

positionrr initializerr()
{
   positionrr temp;
   temp=(positionrr)malloc(sizeof(positionrr)*1);
   if(temp==NULL)
    {
      printf("\nError in initialization\n");
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

positionfc initializefcfs()
{
    positionfc temp;
    temp=(positionfc)malloc(sizeof(positionfc)*1);
    if(temp==NULL)
     {
      printf("\nError in initialization\n");
     }
   else
     {
       temp->pr1.bt=0;
       temp->pr1.tt=0;
       temp->pr1.wt=0;
       temp->pr1.pno=0;
       temp->nextfc=NULL;
       return temp;
     }
}

positionpri initializepri()
{
    positionpri temp;
    temp=(positionpri)malloc(sizeof(positionpri)*1);
    if(temp==NULL)
     {
      printf("\nError in initialization\n");
     }
   else
    {
      temp->pr2.bt=0;
      temp->pr2.tt=0;
      temp->pr2.wt=0;
      temp->pr2.pno=0;
      temp->pr2.pt=0;
      temp->nextpri=NULL;
      return temp;
    }
}


