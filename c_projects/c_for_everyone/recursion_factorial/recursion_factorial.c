/*
   Explores recursion calculating a Factorial
   Joao Colombari 
   Nov, 06, 2023
*/

#include <stdio.h>

// Long inf allows it to work for up to 20 (after is there is integer 
// overflow and results start to get wrong)

long int factorial(int n)
{
    long f = 1;
    int i;

    for (i = 1; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}

long int recursive_factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else 
    {
        return(recursive_factorial(n-1) * n);
    }
}

int main(void)
{
    int how_many = 0, i;
    printf("I want table of factorial up to n:");
    scanf("%d", &how_many);

    printf("\n factorials\n");

    for (i = 1; i <= how_many; i++)
    {
        printf("\n%d\t %ld\n", i, factorial(i));
    }
    for (i = 1; i <= how_many; i++)
    {
        printf("\n%d\t %ld\n", i, recursive_factorial(i));
    }
    printf("\n\n");
    return 0;
}