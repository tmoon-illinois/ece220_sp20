#include <stdio.h>
#define SIZE 5
void print_array(int array[], int n);
void swap(int *firstVal, int *secondVal);
void bubbleSort(int array[], int n);
void insertSort(int array[], int n);
void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);


int main()
{
    //int array[SIZE] = {64, 34, 25, 12, 22, 11, 1};
    int array[SIZE] = {5, 1, 4, 2, 8};

    printf("Before sort: ");
    print_array(array, SIZE);
    //bubbleSort(array, SIZE);
    quickSort(array, 0, SIZE-1);

    insertSort(array, SIZE);
    printf("After sort: ");
    print_array(array, SIZE);

}
void print_array(int array[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}
void swap(int *firstVal, int *secondVal)
{
    int tempVal;

    tempVal = *firstVal;
    *firstVal = *secondVal;
    *secondVal = tempVal;
}
// n: size of array
void bubbleSort(int array[], int n)
{
    int i;
    int is_swapped = 0;

    do{
        is_swapped = 0;
        for(i=0; i< n-1; i++){
            if(array[i] > array[i+1]){
                swap(&array[i], &array[i+1]);
                is_swapped = 1;
            }
        }
    }while(is_swapped != 0);

}
void insertSort(int array[], int n)
{
    int unsorted;   // Index for unsorted list items
    int sorted;     // Index for sorted items
    int unsortedItem;   // Current item to be sorted

    // Loop from 1 thru n
    for(unsorted = 1;unsorted < n; unsorted++){
        unsortedItem = array[unsorted];
        // Loop from unsorted-1 thru 0
        // if unsortedItem < current sorted item, shift the current item to the right
        // stop if we hit a smaller element than unsortedItem
        sorted = unsorted-1;
        while( array[sorted]>unsortedItem && sorted >= 0  ){
            array[sorted+1] = array[sorted];
            sorted--;
        }
        array[sorted+1] = unsortedItem;
    }
}
void quickSort(int array[], int low, int high)
{
    //base case
    if(low >= high)
        return;

    //recursive case
    else{
        int pivot_idx = partition(array, low, high);
        quickSort(array, low, pivot_idx-1);
        quickSort(array, pivot_idx+1, high);
    }
}

// partition: returing the pivot index
int partition(int array[], int low, int high)
{
    int pivot = array[high]; //set the last element as pivot
    int i = low - 1; // index of smaller element
    int j;
    for(j=low;j<=high-1;j++)
    {
        if(array[j] < pivot)
        {
            i++;
            swap( &array[i], &array[j]);
        }
    }
    swap(&array[i+1],&array[high]);
    return i+1;
}


