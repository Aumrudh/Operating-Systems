#include<stdio.h>
main()
{
	int n,n1;
	printf("Enter number of processor and process:\n ");
	scanf("%d %d",&n,&n1); 
   
    int te,ff=0,i,j,check=0,a[n],s[n],p[n],wr[n],w[3],fps[n1],fpr[n];
     int alloc[n1];

   int k,max,min,c=0;
   

    printf("\n Enter size of processor:\n");
	for(i=0;i<n;i++)
	{
	   scanf("%d",&a[i]);
       fpr[i]=0;
       
              
       if(i<3)
       w[i]=0;
	}
	  

	printf("Enter size of the processes in bytes:\n");
    for(i=0;i<n1;i++)
	  {
	  	fps[i]=0;
	  	
	  	alloc[i]=0;
	    scanf("%d",&p[i]);
    }

printf("\n GIVEN VALUES:\n");
      
    for(i=0;i<n;i++)
    printf("\npr: %d  i:%d \n",a[i],i);
    
    for(i=0;i<n1;i++)
     printf("ps:%d  i:%d \n",p[i],i);
      
      
    printf("\n First fit\n");
    	
    	for(i=0;i<n;i++)
    	   fpr[i]=0;
    	  
    	for(i=0;i<n1;i++)
		   fps[i]=0;  
		
	for(i=0;i<n1;i++)
    {
    	for(j=0;j<n;j++)
    	{		
  			
  	//		 printf(" iterate  check pr:%d  prs:%d \n",a[j],p[i]);
	
  			if(fpr[j]==0 && fps[i]==0)
  			{
  				
  //		       printf("available  pr:%d  prs:%d \n",a[j],p[i]);
			

		    if(a[j] >= p[i])
		      { 
//			       printf(" alllocated pr:%d  prs:%d \n",a[j],p[i]);
			    
		            fps[i]++;
		            fpr[j]++;
		            
		        	alloc[i]=j+1;
				   	wr[j]=a[j]-p[i];
				   	w[0]=w[0]+wr[j];
			  }	
	        }
	     }
   }
       
       
	for(i=0;i<n1;i++)
	{
	if(alloc[i]>0)
	printf("\n Process:%d  block:%d",i+1,alloc[i]);
    else
    printf("\n Process:%d  Not allocated",i);
	
     fps[i]=0;
	alloc[i]=0;
	}
	
	for(i=0;i<n;i++)
	  fpr[i]=0;


//printf("\n Now back to initial state\n");
for(k=0;k<n;k++)
{
// printf(" alloc[%d]:%d  fps[%d]:%d \n",k,alloc[k],k,fps[k]);
}

//for(k=0;k<n;k++)
// printf("fpr[%d]:%d \n",k,fpr[k]);


	printf("\n Wastage in First Fit:%d",w[0]);
	
	

	printf("\n Best Fit\n");
	
  for(i=0;i<n1;i++)
    {
       for(k=0;k<n;k++)
       {
       	 if(fpr[k]==0)
       	 {
          if(a[k]>=p[i])
          {
            min=k;
            c=1;
  //          printf("\n First min for pr:%d is ps:%d \n",i+1,min+1);
            break;              
          }
         }

       }

    	for(j=0;j<n;j++)
    	{		
          if(fpr[j]==0 && fps[i]==0)
         {
		    if(a[j]>=p[i])
         {
            if(a[j]<a[min])
              min=j;
         }
         }
      }

   if(c==1)
  {
//    printf("\n Final min for pr:%d is ps:%d \n",i+1,min+1);
          
		  fpr[min]++;
          fps[i]++;
            c=0;

		     		alloc[i]=min+1;
				   	wr[min]=a[min]-p[i];
				   	w[1]=w[1]+wr[min];
		}	
		   
	}
   
	
	
	for(i=0;i<n1;i++)
	{
	if(alloc[i]>0)
	printf("\n Process:%d  block:%d",i+1,alloc[i]);
    else
    printf("\n Process:%d  Not allocated");
	
	
	fps[i]=0;
	alloc[i]=0;
	}
   
for(i=0;i<n;i++)
 fpr[i]=0;
  

	
	printf("\n Wastage in Best fit:%d \n",w[1]);
	
	
 printf("\n Worst Fit\n");
		
  for(i=0;i<n1;i++)
  {
  	     for(k=0;k<n;k++)
       {
       	 if(fpr[k]==0 && fps[i]==0)
       	 {
          if(a[k]>=p[i])
          {
            min=k;
            c=1;
    //       printf("\n First min for pr:%d is ps:%d \n",i,min+1);
            break;              
          }
         }

       }
  	
  	
    	for(j=0;j<n;j++)
    	{		
          if(fpr[j]==0 && fps[i]==0)
         {
		    if(a[j]>=p[i])
         {
            if(a[j]>a[min])
              min=j;
         }
         }
        }
  	
  	
    
    	if(c==1)
    	{
  // printf("\n Final min for pr:%d is ps:%d \n",i,min+1);

		  fpr[min]++;
          fps[i]++;
            c=0;
            
	        	alloc[i]=min+1;
			   	wr[min]=a[min]-p[i];
			   	
//			   	printf("\n w[2]:%d wr[min]:%d  min:%d\n",w[2],wr[min],min+1);
			   	w[2]=w[2]+wr[min];
	  }
	     
  }
   
   for(i=0;i<n1;i++)
	{
	if(alloc[i]>0)
	printf("\n Process:%d  block:%d",i+1,alloc[i]);
    else
    printf("\n Process:%d  Not allocated");
	
		}
	
   printf("\n Wastage in worst fit:%d",w[2]);	


}
