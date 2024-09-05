#include <stdio.h>
#include <stdlib.h>
void SSTF(int tracks[], int n, int head) {
    int totalMovement = 0, completed[n], closestTrack;
    int minDistance, currentIndex;
    for (int i = 0; i < n; i++) 
        completed[i] = 0;
    printf("SSTF Disk Scheduling\n");
    printf("Order of servicing: %d ", head);
    for (int i = 0; i < n; i++) {
        minDistance = 9999;
        for (int j = 0; j < n; j++) {
            if (!completed[j] && abs(tracks[j] - head) < minDistance) {
                minDistance = abs(tracks[j] - head);
                closestTrack = tracks[j];
                currentIndex = j;
            }
        }
        totalMovement += minDistance;
        head = closestTrack;
        completed[currentIndex] = 1;
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
    SSTF(tracks, n, head);
    return 0;
}
