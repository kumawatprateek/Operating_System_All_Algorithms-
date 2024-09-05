//#include <stdio.h>
//
//int main() {
//    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
//    float awt = 0, att = 0, temp = 0;
//
//    printf("Enter the number of processes -- ");
//    scanf("%d", &n);
//
//    for (i = 0; i < n; i++) {
//        printf("\nEnter Burst Time for process %d -- ", i + 1);
//        scanf("%d", &bu[i]);
//        ct[i] = bu[i]; 
//    }
//
//    printf("\nEnter the size of time slice -- ");
//    scanf("%d", &t);
//
//    max = bu[0];
//    for (i = 1; i < n; i++)
//        if (max < bu[i])
//            max = bu[i];
//
//    for (j = 0; j < (max / t) + 1; j++) {
//        for (i = 0; i < n; i++) {
//            if (bu[i] != 0) {
//                if (bu[i] <= t) {
//                    tat[i] = temp + bu[i];
//                    temp = temp + bu[i];
//                    bu[i] = 0;
//                } else {
//                    bu[i] = bu[i] - t;
//                    temp = temp + t;
//                }
//            }
//        }
//    }
//
//    for (i = 0; i < n; i++) {
//        wa[i] = tat[i] - ct[i];
//        att += tat[i];
//        awt += wa[i];
//    }
//
//    printf("\nThe Average Turnaround time is -- %f", att / n);
//    printf("\nThe Average Waiting time is -- %f ", awt / n);
//
//    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
//    for (i = 0; i < n; i++)
//        printf("\t%d \t %d \t\t %d \t\t %d \n", i + 1, ct[i], wa[i], tat[i]);
//    return 0;
//}
//


#include <stdio.h>
#include <math.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void roundRobin(int p[], int bt[], int n, int tq) {
    int ct[n], wt[n], tbt[n], tat[n], sum = 0;
	float awt = 0, att = 0;
    for (int x = 0; x < n; x++) {
        tbt[x] = bt[x];
        sum += bt[x];
    }
    int rque[50], j = 0, i = 0, k = 0, l = 0, ppoint = 0;
    int a = 1;
    rque[i++] = p[l++];
    int currentTime = 0;
    
    while (a == 1) {
        int t;
        if (tbt[rque[ppoint] - 1] > 0) {
            t = min(tbt[rque[ppoint] - 1], tq);
            tbt[rque[ppoint] - 1] -= t;
            currentTime += t;
            if (tbt[rque[ppoint] - 1] == 0) 
                ct[rque[ppoint] - 1] = currentTime;
        
            for (int m = 0; m < t; m++) {
                if (l < n) 
                    rque[i++] = p[l++];
            }
            if (tbt[rque[ppoint] - 1] != 0) {
                rque[i++] = rque[ppoint];
            }
        }
        ppoint++;
        if (ppoint == i) {
            a = 0;
        }
    }
    
    for (int x = 0; x < n; x++) {
        tat[x] = ct[x]-x;
        wt[x] = tat[x] - bt[x];
        
        att+=tat[x];
        awt+=wt[x];
    }

    printf("\nP\t BT \tCT \tTT \t WT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nThe Average Turnaround time is -- %f", att / n);
    printf("\nThe Average Waiting time is -- %f ", awt / n);
}

int main() {
    int n ,p[20] ,bt[20] ,tq;

	printf("Enter the number of processes -- ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
    	p[i]=i+1;
        printf("\nEnter Burst Time for process %d -- ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("\nEnter the size of time slice -- ");
    scanf("%d", &tq);

    roundRobin(p, bt, n, tq);
    return 0;
}

