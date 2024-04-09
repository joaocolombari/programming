/*
    Declarations
    Joao Colombari 
    Oct, 30, 2023
*/

#include <stdio.h>

int main(void)
{
    int a = 5, b = 7, c = 6; 		// Declarations
    double average = 0.0;		// Good practice, as in ML

    printf("a = %d, b = %d, c = %d\n", a, b, c);

    average = (a + b + c) / 3.0;	// Conversion to double

    printf("average = %lf\n", average);
    return 0;
}
