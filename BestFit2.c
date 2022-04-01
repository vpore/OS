#include<stdio.h>
#define MAX 20

void main()
{
    int fragment[MAX],blocks[MAX],processes[MAX],i,j,numBlocks,numProc,frag,lowest=9999,count=0;
    static int allocBlocks[MAX],allocProc[MAX];
    printf("\n\tMemory Allocation Technique - Best Fit : \n");
    printf("\nEnter the number of blocks : ");
    scanf("%d",&numBlocks);
    printf("Enter the number of processes : ");
    scanf("%d",&numProc);
    printf("\nEnter the size of the blocks : \n");
    for(i=1;i<=numBlocks;i++)
    {
        printf("Block-%d : ",i);
        scanf("%d",&blocks[i]);
    }
    printf("\nEnter the size of the processes : \n");
    for(i=1;i<=numProc;i++)
    {
        printf("Process-%d : ",i);
        scanf("%d",&processes[i]);
    }
    for(i=1;i<=numProc;i++)
    {
        for(j=1;j<=numBlocks;j++)
        {
            if(allocBlocks[j]!=1)
            {
                frag=blocks[j]-processes[i];
                if(frag>=0)
                {
                    if(lowest>frag)
                    {
                        allocProc[i]=j;
                        count++;
                        lowest=frag;
                    }
                }

            }
        }
        fragment[i]=lowest;
        allocBlocks[allocProc[i]]=1;
        lowest=10000;
    }
    printf("\nProcess \tProcess size\tBlock no. \tBlock size\tFragment\n");
    for(i=1;i<=numProc && allocProc[i]!=0;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,processes[i],allocProc[i],blocks[allocProc[i]],fragment[i]);
    }
}