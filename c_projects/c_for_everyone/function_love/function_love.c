/*
   Nested ternary operator  
   Joao Colombari 
   Nov, 04, 2023
*/

#include <stdio.h>

void love(int count)
{
    while (count > 0)
    {
        printf("\n very");
        count--;
    };
    
    printf(" much\n\n");
}

int main(void)
{
    int repeat = 0;
    printf("How deep is you love (1-10)?: ");
    scanf("%d", &repeat);
    printf("\n I love you very");
    love(repeat);
    return 0;
}