/*
   Tryies to explain pointers
   Joao Colombari 
   Nov, 08, 2023
*/

#include <stdio.h>

int main(void)
{
    const int SIZE = 5;

    int grades[SIZE] = {78, 67, 92, 83, 88};
    double sum = 0.0;
    double * ptr_to_sum = &sum;
    // doouble * is pointer to double, int * is pointer to int...

    int i; 

    printf("\n My grades are:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", grades[i]);
    }
    printf("\n\n");

    for (i = 0; i < SIZE; i++)
    {
        sum = sum + grades[i];
    }
    printf("My average is: %.2f\n\n", sum/SIZE);
    printf("\n\n");

    // pointers
    printf("Sum is at %p, or %lu and is %lf\n",
            ptr_to_sum,
            ptr_to_sum,
            *ptr_to_sum);
    // %p is hex, %lu is long unsigned
    // first it prints addr in hexa
    // then it prints it in double
    // then it unreferences the addr and prints the content of the pointers addr
    printf("Grades are at %lu to %lu\n", grades, grades + 5);    

    return 0;
}