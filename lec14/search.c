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
  
   printf("Binary search-recursive version\n");
   found = binarySearch_rec(array, 0, 5, key);
   if(found == -1)
       printf("Key %d not found\n", key);
   else
       printf("Found key %d at index %d\n", key, found);
/*   
   printf("Binary search\n");
   found = binarySearch(array, 0, 5, key);
   if(found == -1)
       printf("Key %d not found\n", key);
   else
       printf("Found key %d at index %d\n", key, found);
   
   
   printf("Linear search\n");
   found = linearSearch(array, 0, 5, key);
   if(found == -1)
       printf("Key %d not found\n", key);
   else
       printf("Found key %d at index %d\n", key, found);
*/
}
// linearSearch & binarySearch
// Returns the index of "key" item in given "array" from index "l" to index "r"
// otherwise -1
int linearSearch(int array[], int l, int r, int key)
{
    int i;
    for(i=l ; i<r+1; i++){
        if(key == array[i])
            return i;
    }
    return -1;
}
int binarySearch(int array[], int l, int r, int key)
{
    int L=l, H=r, M; //index

    while( L<=H )
    {
        M = (H+L)/2;
        if(key == array[M])
            return M;
        else if(key > array[M])
            L = M+1;
        else // key < array[M]
            H = M-1;
    }
    return -1;

}
int binarySearch_rec(int array[], int l, int r, int key)
{
    int M = (l+r)/2;

    if ( l > r)
        return -1;
    else if(key == array[M])
        return M;
    else if(key > array[M])
        return binarySearch_rec(array, M+1, r, key);
    else //key < array[M]
        return binarySearch_rec(array, l, M-1, key);
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
