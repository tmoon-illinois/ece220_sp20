#include <stdio.h>
#define SIZE 5
void print_array(int array[], int n);
void swap(int *firstVal, int *secondVal);
void bubbleSort(int array[], int n);
void insertSort(int array[], int n);


int main()
{
    //int array[SIZE] = {64, 34, 25, 12, 22, 11, 1};
    int array[SIZE] = {5, 1, 4, 2, 8};

    printf("Before sort: ");
    print_array(array, SIZE);
    bubbleSort(array, SIZE);
    //insertSort(array, n);
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
}
