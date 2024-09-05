#include <stdio.h>

int main() {
    int f[50], i, j, st, len, n, c;

    for(i = 0; i < 50; i++) 
        f[i] = 0;
    printf("Enter the number of blocks that are already allocated: ");
    scanf("%d", &n);
    printf("\nEnter the blocks that are already allocated: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &j);
        f[j] = 1;
    }
    do {
        printf("\nEnter the starting block and length of the file: ");
        scanf("%d%d", &st, &len);
        for(j = st; j < (st + len); j++) {
            if(f[j] == 0) {
                f[j] = 1;
                printf("\nBlock %d -> Allocated", j);
            } else {
                printf("\nBlock %d -> Already allocated", j);
                len++; 
            }
        }
        printf("\nFile is allocated successfully!\n");
        printf("\nDo you want to enter more files? (Yes - 1 / No - 0): ");
        scanf("%d", &c);
    } while(c == 1);
    return 0;
}

