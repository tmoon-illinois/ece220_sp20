#include <stdio.h>


struct A{
    int a;
    double b;
    int c;
};

enum weekday {SUN=7, MON=1, TUE, WED};
int main()
{

    struct A a1 ;
    a1.a = 0;
    a1.c = 1;
    printf("%d %lf %d\n", a1.a, a1.b, a1.c);

    enum weekday today;
    today = WED;
    printf("%d\n", today);
}
