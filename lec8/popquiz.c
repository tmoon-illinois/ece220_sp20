#include <stdio.h>


int main()
{
    int a = 6, b = 9;

    float c;
    printf("%-15s%-15s\n", "Expression", "Value of Expression");
    printf("%-15s%-15d\n", "a | b", a | b);
    printf("%-15s%-15d\n", "a || b", a || b);
    printf("%-15s%-15d\n", "a & b", a & b);
    printf("%-15s%-15d\n", "a && b", a && b);
    printf("%-15s%-15d\n", "!(a + b)", !(a + b));
    printf("%-15s%-15d\n", "a % b", a % b);
    printf("%-15s%-15d\n", "b / a", b / a);
    printf("%-15s%-15f\n", "c = b / a", c = (float) (9 / 6));
    printf("%-15s%-15f\n", "c = b / a", c = (float) 9 / 6);
    printf("%-15s%-15d\n", "a = b", a = b);
    printf("%-15s%-15d\n", "a = b = 5", a = b = 5);
    printf("%-15s%-15d\n", "++a + b--", ++a + b--);
    printf("%-15s%-15d\n", "a ", a);
    printf("%-15s%-15d\n", "b ", b);

    printf("%-15s%-15d\n", "a = (++b < 3)? a : b", a = (++b < 3)? a : b);

}
