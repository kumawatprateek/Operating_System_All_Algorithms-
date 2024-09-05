#include <stdio.h>
int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}
void LRU(int pages[], int n, int capacity) {
    int frame[capacity], time[capacity];
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
        time[i] = 0;
    }
    int faults = 0, counter = 0;
    printf("LRU Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }
        if (!found) {
            int pos = findLRU(time, capacity);
            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }
        printf("%d: ", pages[i]);
        for (int j = 0; j < capacity; j++)
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        printf("\n");
    }
    printf("Total Page Faults (LRU): %d\n", faults);
}
int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;
    LRU(pages, n, capacity);
    return 0;
}

