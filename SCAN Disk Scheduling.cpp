#include <stdio.h>
#include <stdlib.h>
void SCAN(int tracks[], int n, int head, int direction, int diskSize) {
    int totalMovement = 0, i;
    printf("SCAN Disk Scheduling\n");
    printf("Order of servicing: %d ", head);
    if (direction == 1) { 
        for (i = 0; i < n; i++) {
            if (tracks[i] >= head) {
                totalMovement += abs(tracks[i] - head);
                head = tracks[i];
                printf("-> %d ", head);
            }
        }
        if (head != diskSize - 1) {
            totalMovement += abs(diskSize - 1 - head);
            head = diskSize - 1;
            printf("-> %d ", head);
        }
        for (i = n - 1; i >= 0; i--) {
            if (tracks[i] < head) {
                totalMovement += abs(tracks[i] - head);
                head = tracks[i];
                printf("-> %d ", head);
            }
        }
    } else {
        for (i = n - 1; i >= 0; i--) {
            if (tracks[i] <= head) {
                totalMovement += abs(tracks[i] - head);
                head = tracks[i];
                printf("-> %d ", head);
            }
        }
        if (head != 0) {
            totalMovement += head;
            head = 0;
            printf("-> %d ", head);
        }
        for (i = 0; i < n; i++) {
            if (tracks[i] > head) {
                totalMovement += abs(tracks[i] - head);
                head = tracks[i];
                printf("-> %d ", head);
            }
        }
    }
    printf("\nTotal head movement: %d\n\n", totalMovement);
}
int main() {
    int n, head, diskSize, direction;
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);
    int tracks[n];
    printf("Enter the tracks: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &tracks[i]);
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the disk size: ");
    scanf("%d", &diskSize);
    printf("Enter the direction (1 for high, 0 for low): ");
    scanf("%d", &direction);
    SCAN(tracks, n, head, direction, diskSize);

    return 0;
}
