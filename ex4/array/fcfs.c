#include<stdio.h>
#include<string.h>
main()
{
  char pn[10][10];
  int at[10],bt[10],st[10],ft[10],tat[10],wt[10],i,j,n,temp,temp1;
  int totwt=0,tottat=0;
  float avgwt,avgtat;
  printf("Enter the number of processes:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter the process name,Burst time for%d:",i+1);
    scanf("%s%d",pn[i],&bt[i]);
   }
  for(i=0;i<n;i++)
  {
    if(i==0)
    {
      st[i]=0;
      wt[i]=st[i]-0;
      ft[i]=st[i]+bt[i];
      tat[i]=ft[i]-0;
    }
    else
    {
      st[i]=ft[i-1];
      wt[i]=ft[i-1];
      ft[i]=st[i]+bt[i];
      tat[i]=ft[i];
    }
  }
  printf("Proc.name Bur.time Waiting time TurnAround ");
  for(i=0;i<n;i++)
  {
    printf("\n %s\t %d\t\t%d\t%d ",pn[i],bt[i],wt[i],tat[i]);
    totwt+=wt[i];
    tottat+=tat[i];
  }
  avgwt=totwt/n;
  avgtat=tottat/n;
  printf("\nAverage waiting time :%.2f\n",avgwt);
  printf("Average Turn around time: %.2f\n",avgtat);
}
