//#include <stdio.h>
//
//int main() {
//    char a1[][3] = {"p1", "p2", "p3"};
//    int a2[] = {24, 3, 3}; 
//    int l = sizeof(a2) / sizeof(a2[0]);
//
//    printf("Number of processes: %d\n", l);
//
//    int wt[l]; 
//    int tt[l]; 
//    int total_wt = 0;
//    int total_tt = a2[0];
//
//    wt[0] = 0;
//    tt[0] = a2[0];
//
//    for (int i = 1; i < l; i++) {
//        wt[i] = wt[i - 1] + a2[i - 1];
//        total_wt += wt[i];
//        tt[i] = wt[i] + a2[i];
//        total_tt += tt[i];
//    }
//
//    for (int i = 0; i < l; i++) {
//        printf("Process %s: Waiting Time = %d, Turnaround Time = %d\n", a1[i], wt[i], tt[i]);
//    }
//
//    double avg_wt = (double) total_wt / l;
//    double avg_tt = (double) total_tt / l;
//
//    printf("\nAverage Waiting Time: %.2f", avg_wt);
//    printf("\nAverage Turnaround Time: %.2f\n", avg_tt);
//
//    return 0;
//}



#include <stdio.h>

int main() {
    int bt[] = {24, 3, 3}; 
    int l = sizeof(bt) / sizeof(bt[0]);

    printf("Number of processes: %d\n", l);

    int wt[l]; 
    int tt[l]; 
    int total_wt = 0,total_tt = 0;

    wt[0] = 0;
    tt[0] = bt[0];
    total_tt += tt[0];

    for (int i = 1; i < l; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        total_wt += wt[i];
        tt[i] = wt[i] + bt[i];
        total_tt += tt[i];
    }

    printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < l; i++) {
        printf("P%d\t %d\t\t %d\t\t %d\n", i+1, bt[i], wt[i], tt[i]);
    }

    double avg_wt = (double) total_wt / l;
    double avg_tt = (double) total_tt / l;
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tt);
    return 0;
}

