/*
   While loop questions - Quiz Week 3
   Joao Colombari 
   Nov, 4, 2023
*/

#include <stdio.h>

int main(void)
{
    int i;

    printf("i starts off as: ");
    scanf("%d", &i);

    while (i < 5)
    {
    	i = i - 1;
    	printf(" i = %d\n", i);
    }

    return 0;
};

