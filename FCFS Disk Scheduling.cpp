#include <stdio.h>
#include <stdlib.h>
void FCFS(int tracks[], int n, int head) {
    int totalMovement = 0;
    printf("FCFS Disk Scheduling\n");
    printf("Order of servicing: %d ", head);
    for (int i = 0; i < n; i++) {
        totalMovement += abs(tracks[i] - head);
        head = tracks[i];
        printf("-> %d ", head);
    }
    printf("\nTotal head movement: %d\n\n", totalMovement);
}
int main() {
    int n, head;
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);
    int tracks[n];
    printf("Enter the tracks: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &tracks[i]);
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    FCFS(tracks, n, head);
    
    return 0;
}
