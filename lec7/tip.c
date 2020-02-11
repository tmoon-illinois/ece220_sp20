#include <stdio.h>

#define TIP 0.18

int main()
{
    float total;
    float bill;
    printf("Enter bill amount");
    scanf("%f", &bill);

    total = (1+TIP)*bill;

    printf("total is %f.\n", total);

    return 0;
}
