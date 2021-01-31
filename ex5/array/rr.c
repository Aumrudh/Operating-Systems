#include<stdio.h>
struct process
{
int status,id,burst,wt,bal,tat;
}p[20];

main()
{
        int i=0,time=0,count=0,n,tq;
        int twt=0,ttat=0;
float awt,atat;
        printf("\n Enter No of process:");
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
                printf("\n Enter the Process id:");
                scanf("%d",&p[i].id);
                printf("\n Enter the Burst time:");
                scanf("%d",&p[i].burst);
                p[i].bal=p[i].burst;
                p[i].status=0;
        }

        printf("\n Enter The Time Quantum:");
        scanf("%d",&tq);
        i=0;
        while(count<n)
        {
                if(p[i].status==0)
                {
                        if(p[i].bal<=tq)
                        {
                                time+=p[i].bal;
                                p[i].wt=time-p[i].burst;
                                p[i].tat=p[i].wt+p[i].burst;
                                p[i].status=1;
                                count++;
                        }
                        else
                        {
                                p[i].bal-=tq;
                                time+=tq;
                        }
                }
                i=(i+1)%n;
        }
  for(i=0;i<n;i++)
{
twt+=p[i].wt;
ttat+=p[i].tat;
}
        awt=twt/n;
        atat=(float)ttat/n;  
        printf("Id\tBurst Time\tWaiting Time\tTAT\n");
        for(i=0;i<n;i++)
        {
                printf("\n%d\t%d\t\t%d\t\t%d\t\n",p[i].id,p[i].burst,p[i].wt,p[i].tat);
        }
        printf("\nAverage Waiting Time:\t\t%.2f\nAverage Turn Around time\t%.2f",awt,atat);
        printf("\n");

}



