#include <stdio.h>

int predict(int pages[], int frame[], int n, int index, int capacity) {
    int res = -1, farthest = index;
    for (int i = 0; i < capacity; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n) return i;
    }
    return (res == -1) ? 0 : res;
}

void OPT(int pages[], int n, int capacity) {
    int frame[capacity];
    for (int i = 0; i < capacity; i++)
        frame[i] = -1;

    int faults = 0;

    printf("OPT Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (i < capacity) {
                frame[i] = pages[i];
            } else {
                int pos = predict(pages, frame, n, i + 1, capacity);
                frame[pos] = pages[i];
            }
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

    printf("Total Page Faults (OPT): %d\n", faults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    OPT(pages, n, capacity);

    return 0;
}

