#include<stdio.h>
int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20], i, j, n, temp;
    float wtavg, tatavg;
    n = 5;
    int default_bt[] = {10, 1, 2, 1, 5};  
    int default_pri[] = {3, 1, 4, 5, 2};  
    for(i = 0; i < n; i++) {
        p[i] = i;
        bt[i] = default_bt[i];
        pri[i] = default_pri[i];
    }
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(pri[i] > pri[j]) {
                temp = p[i]; 
                p[i] = p[j]; 
                p[j] = temp;
                temp = bt[i]; 
                bt[i] = bt[j]; 
                bt[j] = temp;
                temp = pri[i]; 
                pri[i] = pri[j]; 
                pri[j] = temp;
            }
        }
    }
    wtavg = wt[0] = 0;  
    tatavg = tat[0] = bt[0];  
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1]; 
        tat[i] = tat[i-1] + bt[i];  
        wtavg += wt[i]; 
        tatavg += tat[i];  
    }
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) 
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d", p[i], pri[i], bt[i], wt[i], tat[i]);
    printf("\n\nAverage Waiting Time is: %f", wtavg/n);
    printf("\nAverage Turnaround Time is: %f", tatavg/n);
    return 0;
}

