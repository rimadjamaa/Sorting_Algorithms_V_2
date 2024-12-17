#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortOpt(int arr[], int n) {
    int m = n - 1;
    int change = 1;  // boolean variable

    while (change) {
        change = 0;

        for (int i = 0; i < m; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                change = 1;
            }
        }

        --m;
    }
}
 //Function to Fill in the array
void FillArrayBest(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i]=i;
    }
    printf("\n");
}
void FillArrayWorst(int arr[], int n, int k) {
    k=n;
    for (int i = 0; i < n; ++i) {
        arr[i]=k;
        k--;
    }
    printf("\n");
}


int main() {

    while(1){
    float tt ;
    clock_t t1,t2 ;
    long n ,k=0;

    printf("Give the size of array: ");
    scanf("%d",&n);
    t1 = clock();

    int *arr = (long *)malloc(n *sizeof(long));

    //Fill in the array
      int choice;

    printf("Give a choice between 1 and 2 : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            FillArrayBest(arr,n);
            break;
        case 2:
             FillArrayWorst(arr,n,k);
            break;
        default:
            printf("Choix invalide.\n");
            return 0;
    }


    printf("\nOriginal array:\n ");
    for (long i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

     bubbleSortOpt(arr, n);

    printf("\n\nSorted array:\n ");
    for (long i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    t2=clock();
    tt=(t2-t1)/CLOCKS_PER_SEC ;
    printf("\n\n %f is the time\n\n\n",tt);

    }

    return 0;
}
