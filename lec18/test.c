#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr;
    ptr = (int*) malloc(10*sizeof(int));

    int *ptr2;
    ptr2 = ptr;
    ptr[0] = 10;

    *(ptr+1) = 5;
    //ptr[1] = 5;

    free(ptr);
//    free(ptr2);

    ptr = (char*) malloc(sizeof(char));
    *ptr = 100;
    printf("%d\n", *ptr);

    return 0;
}
