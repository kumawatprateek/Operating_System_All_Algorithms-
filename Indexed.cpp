#include <stdio.h>

int main() {
    int f[50], i, j, p, n, inde[50], c;
    for(i = 0; i < 50; i++) 
        f[i] = 0;
    do {
        printf("\nEnter the index block: ");
        scanf("%d", &p);
        if(f[p] == 0) {
            f[p] = 1;
            printf("\nEnter the number of blocks for the file: ");
            scanf("%d", &n);
            printf("\nEnter the blocks for the file: ");
            for(i = 0; i < n; i++)
                scanf("%d", &inde[i]);
            for(i = 0; i < n; i++) {
                if(f[inde[i]] == 0) {
                    f[inde[i]] = 1;
                    printf("\nBlock %d -> Allocated", inde[i]);
                } else
                    printf("\nBlock %d -> Already allocated", inde[i]);
            }
            printf("\nFile indexed with index block %d", p);
        } else 
            printf("\nBlock %d is already allocated", p);

        printf("\nDo you want to enter more files? (Yes - 1 / No - 0): ");
        scanf("%d", &c);
    } while(c == 1);
    return 0;
}

