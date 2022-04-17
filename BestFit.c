#include<stdio.h>
#define MAX 20
#define INF 99999

void main()
{
    int fragment[MAX],blocks[MAX],processes[MAX],i,j,numBlocks,numProc,frag,lowestFrag=INF;
    int allocProc[MAX];
    int ttlFrag=0;
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
        lowestFrag = INF;
        for(j=1;j<=numBlocks;j++)
        {
            frag = blocks[j]-processes[i];
            if(frag>=0){
                if(frag<lowestFrag){
                    lowestFrag = frag;
                    allocProc[i] = j;
                    fragment[i] = lowestFrag;
                }
            }
        }
        if(lowestFrag == INF){printf("\nProcess-%d cant be allocated", i); allocProc[i]=-1;}
    }

    printf("\nProcess \tProcess size\tBlock no. \tBlock size\tFragment\n");
    for(i=1;i<=numProc && allocProc[i]!=-1;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,processes[i],allocProc[i],blocks[allocProc[i]],fragment[i]);
        ttlFrag += fragment[i];
    }

    printf("\nTotal Fragmentation = %d", ttlFrag);
}