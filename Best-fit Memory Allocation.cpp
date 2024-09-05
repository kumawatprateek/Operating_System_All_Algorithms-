#include <stdio.h>

int main() {
    int blockSize[10], processSize[10];
    int i, j, nb, np;
    int allocation[10];
    for(i = 0; i < 10; i++)
        allocation[i] = -1;
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter size of each block: ");
    for(i = 0; i < nb; i++) {
        scanf("%d", &blockSize[i]);
    }
    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter size of each process: ");
    for(i = 0; i < np; i++) {
        scanf("%d", &processSize[i]);
    }
    for(i = 0; i < np; i++) {
        int bestIdx = -1;
        for(j = 0; j < nb; j++) {
            if(blockSize[j] >= processSize[i]) 
                if(bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
        }
        if(bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}

