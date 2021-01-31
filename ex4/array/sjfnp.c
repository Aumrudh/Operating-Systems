#include<stdio.h>
typedef struct mynode
{
	char pname[20];
	int burst,wait,tat;
}mynode;
main()
{
	int n,i,j,swt=0,stat=0;
	float awt,atat;
	mynode p[50],temp;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the name of the process : ");
		scanf("%s",p[i].pname);
		printf("\nEnter the burst time for the process %d : ",i+1);
		scanf("%d",&p[i].burst);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(p[i].burst<p[j].burst)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	p[0].wait=0;
	p[0].tat=p[0].burst;
	for(i=1;i<n;i++)
	{
		p[i].wait=p[i-1].wait+p[i-1].burst;
		p[i].tat=p[i].wait+p[i].burst;
	}
	for(i=0;i<n;i++)
	{
		swt=swt+p[i].wait;
		stat=stat+p[i].tat;
	}
	awt=(float)swt/n;
	atat=(float)stat/n;
	printf("\n\nNAME\t\tbursttime\t\twaitingtime\t\tturnaroundtime\t\t");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t\t%d\t\t\t%d\t\t\t%d\t\t",p[i].pname,p[i].burst,p[i].wait,p[i].tat);
	}
	printf("\nAverage Waiting time : %.2f\n",awt);
        printf("Average turn around time : %.2f\n",atat);
}
