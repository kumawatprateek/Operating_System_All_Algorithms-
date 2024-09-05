#include <stdio.h>
void FIFO(int pages[], int n, int capacity) {
    int frame[capacity];
    for (int i = 0; i < capacity; i++)
        frame[i] = -1;
    int faults = 0, index = 0;
    printf("FIFO Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % capacity;
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
    printf("Total Page Faults (FIFO): %d\n", faults);
}
int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;
    FIFO(pages, n, capacity);
    return 0;
}
