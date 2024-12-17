#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

typedef int *array;
array T;
/******************La Fonction partition****************************/
int partition(int* t, int g, int d)
{
    int i = g,j=d,pivot = t[g],temp;
    while(1)
        {

			while( t[j] > pivot) j--;
			while( t[i] < pivot) i++;

            if(i<j)
                {
                    swap(&t[i], &t[j]);
                    i++; j--;
                }
            else return j;
        }
}

/******************La Fonction triRapide****************************/
void quicksort(int* tab,int g, int d)
{
    int i;
    if(d>g)
        {
            i = partition(tab,g,d);
            quicksort(tab,g,i);
            quicksort(tab,i+1,d);
        }
}


//Function to Fill in the array
void FillArrayBest(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i]=i;
    }
    printf("\n");
}
void FillArrayWorst(int arr[], int n ) {

    for (int i = 0; i < n; ++i) {
        arr[i]=rand();

    }
    printf("\n");
}

int main() {
    while(1){
    float tt ;
    clock_t t1,t2 ;
    int n ;

    printf("Give the size of array: ");
    scanf("%d",&n);
    t1 = clock();

    int *arr = (int *)malloc(n *sizeof(int));

    //Fill in the array
    int choice;

    printf("Give a choice between 1 and 2 : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            FillArrayBest(arr,n);
            break;
        case 2:
             FillArrayWorst(arr,n);
            break;
        default:
            printf("Choix invalide.\n");
            return 0;
    }

    printf("Original array: \n\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    quicksort(arr, 0, n-1);

    printf("\nSorted array:\n\n ");
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
