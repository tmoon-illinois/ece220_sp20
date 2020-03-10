#include <stdio.h>



int factorial_iter(int n){
    int i;
    int result = 1;
    for(i=0;i<n;i++)
        result = result*(i+1);

    return result;

}
int factorial_rec(int n){
    if(n == 1)
        return 1;
    else
        return n*factorial_rec(n-1);
}

int main(){
    printf("%d\n", factorial_iter(4));
    printf("%d\n", factorial_rec(4));
}
