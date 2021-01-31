#include<stdio.h>
#include<string.h>
struct process
{
char name[5];
int at,bt,pr;
};
main()
{
struct process p[100];
// struct process temp;
int st[100],ft[100],wt[100],tat[100],totwt=0,tottat=0,n,i,j;
float awt,atat;
void sort(struct process p[],int i,int j);
printf("\nEnter number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n%d",i+1);
printf("\nEnter Process Name:");
scanf("%s",p[i].name);
printf("\nEnter Burst Time:");
scanf("%d",&p[i].bt);
printf("\nEnter Arrival time:");
scanf("%d",&p[i].at);
printf("\nEnter Priority:");
scanf("%d",&p[i].pr);
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(p[i].pr<p[j].pr)
{
sort(p,i,j);
/* temp=p[i];
p[i]=p[j];
p[j]=temp;*/
}
else if(p[i].pr==p[j].pr)
{
if(p[i].at<p[i].at)
{
sort(p,i,j);
/* temp=p[i];
p[i]=p[j];
p[j]=temp;
*/
}
}
}
}
for(i=0;i<n;i++)
{
if(i==0)
{
st[i]=p[i].at;
wt[i]=st[i]-p[i].at;
ft[i]=st[i]+p[i].bt;
tat[i]=ft[i]-p[i].at;
}
else
{
st[i]=ft[i-1];
 wt[i]=st[i]-p[i].at;
        ft[i]=st[i]+p[i].bt;
        tat[i]=ft[i]-p[i].at;
      }
totwt+=wt[i];
tottat+=tat[i];
}
printf("\nProcess Name\tArrivaltime\tBursttime\tPriority\tWT\tTAT");
for(i=0;i<n;i++)
{
printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d\t%d",p[i].name,p[i].at,p[i].bt,p[i].pr,wt[i],tat[i]);
}
awt=totwt/n;
atat=tottat/n;
printf("\nAverage Waiting Time: %.2f",awt);
printf("\nAverage Turn Around Time:%.2f",atat);
}
void sort(struct process p[],int i,int j)
{
char temp[10];
int t;
strcpy(temp,p[i].name);
strcpy(p[i].name,p[j].name);
strcpy(p[j].name,temp);
t=p[i].bt;
p[i].bt=p[j].bt;
p[j].bt=t;
t=p[i].pr;
p[i].pr=p[j].pr;
p[j].pr=t;
t=p[i].at;
p[i].at=p[j].at;
p[j].at=t;
}


