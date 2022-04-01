#include<stdio.h>
#define MAX 50

void main()
{
    int fragment[MAX],blocks[MAX],processes[MAX],i,j,numBlocks,numProcesses,frag,lowest=9999,count=0,no_allocation_process=0;//fragment array = no. and size of the internal fragments created , b=no of blocks array , p=no. of processes array , nb = no. of blocks , np = no. of processes
    int allocBlocks[MAX],allocProcesses[MAX];//barray=allocated block array , parray=allocated processes array , indicates the block no. allocated
    printf("\nMemory Allocation Technique - Best Fit : \n");
    printf("\nEnter the number of blocks : ");
    scanf("%d",&numBlocks);
    printf("Enter the number of processes : ");
    scanf("%d",&numProcesses);
    printf("\nEnter the size of the blocks : \n");
    for(i=1;i<=numBlocks;i++)
    {
        printf("Block no. %d : ",i);
        scanf("%d",&allocBlocks[i]);
    }
    printf("\nEnter the size of the processes : \n");
    for(i=1;i<=numProcesses;i++)
    {
        printf("Process no. %d : ",i);
        scanf("%d",&allocProcesses[i]);
    }
    for(i=1;i<=numProcesses;i++)
    {
        for(j=1;j<=numBlocks;j++)
        {
            if(allocBlocks[j]!=1)//checking if the block is allocated or free
            {
                frag=allocBlocks[j]-allocProcesses[i];//calculating internal fragmentation
                if(frag>=0)
                {
                    if(lowest>frag)
                    {
                        allocProcesses[i]=j;
                        lowest=frag;
                    }
                    
                }

            }
        }
        fragment[i]=lowest;
        allocBlocks[allocProcesses[i]]=1;
        lowest=10000;
    }
    printf("\nProcess no. \tProcess size\tBlock no. \tBlock size\tFragment\n");
    for(i=1;i<=numProcesses && allocProcesses[i]!=0;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,processes[i],allocProcesses[i],blocks[allocProcesses[i]],fragment[i]);
    }
}
