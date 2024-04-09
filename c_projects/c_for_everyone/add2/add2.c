/*
   Adds 2 integer numbers 
   Joao Colombari 
   Oct, 27, 2023
*/

#include <stdio.h>

int main() 
{
    int num1, num2, sum;

    // Input first integer
    printf("Enter the first integer: ");
    scanf("%d", &num1);

    // Input second integer
    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Compute sum
    sum = num1 + num2;

    // Display the sum
    printf("The sum of %d and %d is: %d\n", num1, num2, sum);

    return 0;
}

