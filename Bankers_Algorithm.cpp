#include <stdio.h>

int available[100][3];
int remainingNeed[100][3];
void Bankers_Algo(int n, int p[], int allocation[][3]) {
    int a = 0;
    int new_P[n];
    int pos = 0, ind = 0;
    while (a < n) {
        int j = (pos % n);
        if ((remainingNeed[j][0] <= available[ind][0] && remainingNeed[j][1] <= available[ind][1] && remainingNeed[j][2] <= available[ind][2]) &&
            (remainingNeed[j][0] != -1 && remainingNeed[j][1] != -1 && remainingNeed[j][2] != -1)) {
            new_P[ind] = p[j];
            ind++;
            available[ind][0] = available[ind - 1][0] + allocation[j][0];
            available[ind][1] = available[ind - 1][1] + allocation[j][1];
            available[ind][2] = available[ind - 1][2] + allocation[j][2];

            remainingNeed[j][0] = -1;
            remainingNeed[j][1] = -1;
            remainingNeed[j][2] = -1;
            a++;
        }pos++;
    }
    printf("Process\n");
    for (int i = 0; i < n; i++) 
        printf("P%d-->", new_P[i]);
    printf("\n");
}
int main() {
    int n = 5;
    int p[n];
    int allocation[n][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };
    int maxNeed[n][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {4, 2, 2},
        {5, 3, 3}
    };
    int maxA = 10, maxB = 5, maxC = 7;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        a += allocation[i][0];
        b += allocation[i][1];
        c += allocation[i][2];
        remainingNeed[i][0] = maxNeed[i][0] - allocation[i][0];
        remainingNeed[i][1] = maxNeed[i][1] - allocation[i][1];
        remainingNeed[i][2] = maxNeed[i][2] - allocation[i][2];
        p[i] = i + 1;
    }
    printf("Total \nA B C\n%d %d %d\n", a, b, c);
    available[0][0] = maxA - a;
    available[0][1] = maxB - b;
    available[0][2] = maxC - c;
    printf("Available \nA B C\n%d %d %d\n", available[0][0], available[0][1], available[0][2]);
    printf("Remaining \nA B C\n");
    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", remainingNeed[i][0], remainingNeed[i][1], remainingNeed[i][2]);
    Bankers_Algo(n, p, allocation);
    return 0;
}
