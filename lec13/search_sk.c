#include <stdio.h>
#define SIZE 6
int linearSearch(int array[], int l, int r, int key);
int binarySearch(int array[], int l, int r, int key);
void print_array(int array[], int l, int r);
int main()
{
   int array[] = {11, 12, 22, 25, 34, 64};

   int key;
   int found;

   print_array(array, 0, 5);
   printf("Enter key: ");
   scanf("%d", &key);
  /* 
   found = binarySearch(array, 0, 5, key);
   if(found == -1)
       printf("B: Key %d not found\n", key);
   else
       printf("B: Found key %d at index %d\n", key, found);
   */
   found = linearSearch(array, 0, 5, key);
   if(found == -1)
       printf("L: Key %d not found\n", key);
   else
       printf("L: Found key %d at index %d\n", key, found);

   //return 0;
}
// linearSearch & binarySearch
// Returns the index of "key" item in given "array" from index "l" to index "r"
// otherwise -1
int linearSearch(int array[], int l, int r, int key)
{
    int i;
    for(i=l;i<r+1;i++){
        if(array[i] == key)
            return i;
    }
    return -1;

}
int binarySearch(int array[], int l, int r, int key)
{
    int low, high, mid;
    low = l;
    high = r;

    while(low<=high){
        mid = (low+high)/2;
        if(key < array[mid])
            high = mid -1;
        else if(key > array[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}
void print_array(int array[], int l, int r)
{
    int i;
    for(i=l; i<r+1; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}
