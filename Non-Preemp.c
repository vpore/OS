#include<stdio.h> 

struct process 
{ 
    int id,WT,AT,BT,TAT,PR;
}; 
struct process a[10];
 
void swap(int *b,int *c) 
{     
    int temp;     
    temp=*c;     
    *c=*b; 
    *b=temp; 
} 
 
void main() 
{     
    int n,check_ar=0;     
    int Cmp_time=0; 
    float Total_WT=0,Total_TAT=0,Avg_WT,Avg_TAT;     
    printf("Enter the number of process : ");     
    scanf("%d",&n); 
    printf("Enter the Arrival time , Burst time and priority of the processes : \n");     
    printf("AT\tBT\tPR\n");     
    for(int i=0;i<=n-1;i++) 
    {
        scanf("%d %d %d",&a[i].AT,&a[i].BT,&a[i].PR);    
        a[i].id=i+1;        
        if(i==0) 
        { 
            check_ar=a[i].AT; 
        } 
        if(check_ar!=a[i].AT) 
        { 
            check_ar=1; 
        } 
 
 
    } 
    
    if(check_ar!=0) 
    { 
        for(int i=0;i<=n-2;i++) 
        { 
            for(int j=0;j<n-2-i;j++) 
            { 
                if(a[j].AT>a[j+1].AT) 
                { 
                    swap(&a[j].id,&a[j+1].id);                       
                    swap(&a[j].AT,&a[j+1].AT);                       
                    swap(&a[j].BT,&a[j+1].BT); 
                    swap(&a[j].PR,&a[j+1].PR); 
                } 
            } 
        } 
    } 
 
    
    if(check_ar!=0) 
    { 
        a[0].WT=a[0].AT;         
        a[0].TAT=a[0].BT-a[0].AT;          
        Cmp_time=a[0].TAT; 
        Total_WT=Total_WT+a[0].WT;         
        Total_TAT=Total_TAT+a[0].TAT;         
        for(int i=1;i<=n-1;i++) 
        { 
            int min=a[i].PR;             
            for(int j=i+1;j<=n-1;j++) 
            { 
                if(min>a[j].PR && a[j].AT<=Cmp_time) 
                { 
                    min=a[j].PR;                       
                    swap(&a[i].id,&a[j].id);                      
                    swap(&a[i].AT,&a[j].AT);                       
                    swap(&a[i].BT,&a[j].BT);                      
                    swap(&a[i].PR,&a[j].PR); 
 
                } 
 
            } 
            a[i].WT=Cmp_time-a[i].AT;             
            Total_WT=Total_WT+a[i].WT; 
            Cmp_time=Cmp_time+a[i].BT; 
  
            a[i].TAT=Cmp_time-a[i].AT;             Total_TAT=Total_TAT+a[i].TAT; 
 
        } 
    } 
   
    else 
    { 
        for(int i=0;i<=n-1;i++) 
        { 
            int min=a[i].PR; 
            for(int j=i+1;j<n;j++) 
            { 
                if(min>a[j].PR && a[j].AT<=Cmp_time) 
                { 
                    min=a[j].PR;                     
                    swap(&a[i].id,&a[j].id);                    
                    swap(&a[i].AT,&a[j].AT);                     
                    swap(&a[i].BT,&a[j].BT); 
                    swap(&a[i].PR,&a[j].PR); 
                } 
 
            } 
            a[i].WT=Cmp_time-a[i].AT; 
 
            Cmp_time=Cmp_time+a[i].BT; 
             
            a[i].TAT=Cmp_time-a[i].AT;             
            Total_WT=Total_WT+a[i].WT; 
            Total_TAT=Total_TAT+a[i].TAT; 
 
        } 
 
    } 
 
    Avg_WT=Total_WT/n; 
    Avg_TAT=Total_TAT/n; 
 
    printf("Calculated Table\n");     
    printf("ID\tWT\tTAT\n");     
    for(int i=0;i<n;i++) 
    { 
        printf("%d\t%d\t%d\n",a[i].id,a[i].WT,a[i].TAT); 
    } 
 
    printf("\nAvg waiting time = %f\n",Avg_WT);     
    printf("\nAvg turn around time = %f\n",Avg_TAT); 
} 