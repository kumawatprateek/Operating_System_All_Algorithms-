#include <stdio.h>

int main() {
    int f[50], st, len, i, j, c;
    for(i = 0; i < 50; i++) 
        f[i] = 0;
    do {
        printf("\nEnter the starting block and length of the file: ");
        scanf("%d%d", &st, &len);
        for(j = st; j < (st + len); j++) {
            if(f[j] == 0) {
                f[j] = 1;
                printf("\nBlock %d -> Allocated", j);
            } else {
                printf("\nBlock %d -> Already allocated", j);
                break;
            }
        }
        if(j == (st + len)) 
            printf("\nFile is allocated successfully!\n");
        printf("\nDo you want to enter more files? (Yes - 1 / No - 0): ");
        scanf("%d", &c);
    } while(c == 1);
    return 0;
}

