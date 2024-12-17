#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;         // Initialize largest as root
    int left = 2 * i + 1;    // Left child
    int right = 2 * i + 2;   // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and recursively heapify the affected subtree
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        swap(&arr[0], &arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}





int main() {
    while(1){
    float tt ;
    clock_t t1,t2 ;
    int n , k=0 ;

    printf("Give the size of array: ");
    scanf("%d",&n);
    t1 = clock();

    int *arr = (int *)malloc(n *sizeof(int));

    //Fill in the array
    for (int i = 0; i < n; ++i) {
        arr[i]=rand();
    }
    printf("\n");

    printf("Original array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    heapSort(arr, n);

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
