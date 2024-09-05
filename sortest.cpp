//#include<stdio.h>
//void sortArray(int arr[],int n){
//	int count=0;
//	for(int i=0;i<n;i++){
//		for(int j=i+1;j<n;j++){
//			if(arr[i]>arr[j]){
//				int temp=arr[i];
//				arr[i]=arr[j];
//				arr[j]=temp;
//			}
//			else{
//				count++;
//			}
//		}
//		if(count==n) break;
//	}
//}
//int main(){
////	char p[]={'p1','p2','p3','p4','p5'};
//	int arr[]={4,3,1,2,5};
//	int size=sizeof(arr)/sizeof(arr[0]);
////	for(int i=0;i<size;i++){
////		printf(" %d",arr[i]);
////	}
//	sortArray(arr,size);
////	for(int i=0;i<size;i++){
////		printf(" %d",arr[i]);
////	}
//	int wt[size],avwt=0;
//	int tt[size],avtt=0;
//	wt[0]=0;
//	tt[0]=wt[0]+arr[0];avtt=tt[0];
//	for(int i=1;i<size;i++){
//		wt[i]=wt[i-1]+arr[i-1];
//		avwt+=wt[i];
//		tt[i]=wt[i]+arr[i];
//		avtt+=tt[i];
//	}
//	printf("Wait time is: %d, and Tround Around Time is: %d.",avwt/size,avtt/size);
//	return 0;
//}


#include <stdio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (bt[i] > bt[k]) {
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    wt[0] = 0;
    wtavg = 0;
    tat[0] = bt[0];
    tatavg = tat[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\t PROCESS \tBURST TIME \tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time -- %f", wtavg / n);
    printf("\nAverage Turnaround Time -- %f\n", tatavg / n);

    return 0;
}


