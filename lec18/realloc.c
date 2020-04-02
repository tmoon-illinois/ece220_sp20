#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr, *new_ptr;
    int size=32;
    int i;
    ptr = (int*) calloc(size, sizeof(int));
    //ptr = (int*) malloc(size*sizeof(int));
    printf("%p\n", ptr);

    for(i=0;i<size;i++)
        printf("%d ", ptr[i]);
        //printf("%d ", *(ptr+i));
    
    *ptr = 10;
    //free(ptr);
    
   
    printf("\n\n");
    size = 40;
    new_ptr = (int*) realloc(ptr, size*sizeof(int));
    printf("%p\n", new_ptr);
    *(new_ptr+2) = 30;
    for(i=0;i<size;i++)
        printf("%d ", *(new_ptr+i));
/*
    printf("\n\n");

    printf("%p\n", ptr);
    ptr = (int*) calloc(size, sizeof(int));
    //ptr = (int*) malloc(size*sizeof(int));
    for(i=0;i<size;i++)
        printf("%d ", *(ptr+i));

//    free(ptr);
   
    *ptr = 5;
    printf("\n\n");

    size = 40;
    new_ptr = (int*) realloc(ptr, size*sizeof(int));
    *(new_ptr+2) = 30;
    for(i=0;i<size;i++)
        printf("%d ", *(new_ptr+i));
*/
    free(new_ptr);
}
