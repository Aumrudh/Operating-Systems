#include"head.h"
int main()
{
    int n,ch,pn,i,z;
    float BT;
    listrr l1;
    listfc l2;
    listpri l3;
    l1=initializerr();
    l2=initializefcfs();
    l3=initializepri();
    printf("\nEnter total number of process : ");
    scanf("%d",&n);
    while(1)
     {
        printf("\n================================================================================\n");
        printf("\n\tQueue 1- System Process(ROUNDROBIN)\n\tQueue 2-Batch Process(FCFS)\n\tQueue 3-Student Process(PRIORITY)\n");
        printf("\n================================================================================\n");
        printf("Enter your Choice : ");
        scanf("%d",&ch);
        switch(ch)
         {
             case 1:
                     for(i=0;i<n;i++)
                      {
                       printf("\nEnter process no : ");
                       scanf("%d",&pn);
                       printf("\nEnter burst time : ");
                       scanf("%f",&BT);
                       insertrr(pn,BT,l1);
                      }
                    calculaterr(l1,n);
                    break;
             case 2:
                    for(i=0;i<n;i++)
                     {
                       printf("\nEnter process no : ");
                       scanf("%d",&pn);
                       printf("\nEnter burst time : ");
                       scanf("%f",&BT);
                       insertfcfs(pn,BT,l2);
                     }
                     l2=calculatefcfs(l2,n);
                     break;
             case 3:
                       for(i=0;i<n;i++)
                        {
                          printf("\nEnter process no : ");
                          scanf("%d",&pn);
                          printf("\nEnter burst time : ");
                          scanf("%f",&BT);
                          printf("\nEnter priority : ");
                          scanf("%d",&z);
                          insertpri(pn,BT,z,l3);
                       }
                      l3=sort(l3);
                      l3=calculatepri(l3,n);
                      displaypri(l3);
                      break;
             default:
                      printf("Wrong Choice\n");
          }
     }
  return 1;
}


