#include <stdio.h>
#include <stdlib.h>

double GenRand(double a, double b);
int main(){
    double a, b;
    unsigned int n;
    unsigned int seed;
    
    printf("Enter a,b (range): " );
    scanf("%lf %lf", &a, &b);
    printf("Enter n (number of samples): " );
    scanf("%u", &n);
    printf("Enter seed: " );
    scanf("%u", &seed);
    srand(seed);

    // Compute the theoretical mean, variance
    double mean_th, var_th;
    mean_th = (b+a)/2;
    var_th = (b-a)*(b-a)/12;

    // Compute the sample mean, variance
    double x;
    double mean_s=0, var_s=0;
    int k;
    for(k=0; k<n;k++){
        x = GenRand(a, b);
        printf("%lf\n", x);
        mean_s = mean_s + x;
        var_s = var_s + x*x;
    }
    mean_s = mean_s/n;
    var_s = var_s/n - mean_s*mean_s;

    printf("Theoretical mean, variance: %lf, %lf\n", mean_th, var_th);
    printf("Sample mean, variance: %lf, %lf\n", mean_s, var_s);
}
double GenRand(double a, double b){
    // Your code here
    //

    double result;
    //result = rand()%(b-a+1)+a;//a~a+(b-a)
    result = (b-a)*rand()/RAND_MAX +a;
    return result;
}










