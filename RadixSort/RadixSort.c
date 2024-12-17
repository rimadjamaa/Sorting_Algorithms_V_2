#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

typedef int *array;
array T;
// Function to get the key (digit at a specific position)
int key(int x, int i) {
int j, r;
    for (j=0; j<=i; j++) {
          r= x%10;
	      x = x/10;
 }
    return r;
}
// Function to reorder elements based on a specific digit position
void sortAux(int* T, int n, int i) {
    int T1[n], T2[n], j=0, k=0, l=0;

    for(j=0;j<n;j++) {
    	T1[j] = key (T[j], i);
    }

	for(j=0; j<10; j++) {
		for(k=0; k<n; k++){
			if (T1[k] == j) {
				T2[l] = T[k];
				l++;
    		}
        }
	}
	for(k=0; k<n; k++){
		T[k] = T2[k];
    }
}

// Function to implement iterative radix sort
void radixSort(int* T, int n, int k) {
    for (int exp = 0; exp < k; exp++) {
        sortAux(T, n, exp);
    }
}


int main() {
    while(1){
    float tt ;
    clock_t t1,t2 ;
    int n ;
    int k;

    printf("Give the size of array: ");
    scanf("%d",&n);
    printf("\nVeuillez saisir la valeur du K :");
	scanf("%d",&k);
    t1 = clock();

    int *arr = (int *)malloc(n *sizeof(int));

    //Fill in the array
    for (int i = 0; i < n; ++i) {
        arr[i]=rand()%((int) pow(10,k)-1);
    }

    printf("Original array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    radixSort(arr, n ,k );

    printf("\nSorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    t2=clock();
    tt=(t2-t1)/CLOCKS_PER_SEC ;
    printf("\n\n %f is the time\n\n\n",tt);
}
    return 0;
}

