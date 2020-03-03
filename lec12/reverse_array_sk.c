#include <stdio.h>
#define N 5
void array_reverse(int array[], int n);
void print_array(int array[], int n);

int main()
{
    int array[N] = {1,2,3,4,5};

    printf("Before reverse\n");
    print_array(array, N);
    
    printf("After reverse\n");
    array_reverse(array, N);
    print_array(array, N);
    return 0;
}

void array_reverse(int array[], int n){
    int i;
    int temp;
    for(i=0;i<n/2;i++){//0 
        temp = array[i];
        array[i] = array[n-i-1];
        array[n-i-1] = temp;
    }
}

void print_array(int array[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d  ", array[i]);
    }
    printf("\n\n");
    /*
    for(i=0;i<n;i++){
        printf("%d  ", *(array+i));
    }
    printf("\n\n");
*/

}




