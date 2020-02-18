/*
 * Print nxn idendity matrix (input n from keyboard)
 */
#include <stdio.h>

int main()
{
    // size of idendity matrix
    int n;
    // get input from keyboard
    printf("Enter the size of nxn matrix: ");
    scanf("%d", &n);

    // print the result
    int x=0;
    printf("Output Identity Matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++){
            if(i==j){
                printf("1 ");
                if(j == 1){
                    x = 1;
                    break;
                }
            }
            else
                printf("0 ");
        }

        if(i==1)
            break;
        printf("\n");
    }
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++){
            if(i==1 && j==2)
                return 0;


            if(i==j){
                printf("1 ");
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
    */
    return 0;
}
