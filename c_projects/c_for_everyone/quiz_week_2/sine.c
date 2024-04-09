#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;
    double result = 0;

    printf("\nInput a number betwen 0 and 1: ");
    scanf("%lf", &x);

    result = sin(x);

    printf("\a\tThe sine of %lf is %lf\n", x, result);

    return 0;
}
