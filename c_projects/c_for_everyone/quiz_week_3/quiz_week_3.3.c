/*
   Nested ternary operator  
   Joao Colombari 
   Nov, 04, 2023
*/

#include <stdio.h>

int main(void)
{
    int i;

    printf("i starts off as: ");
    scanf("%d", &i);

    switch(i)
    {
    case 1: printf("case 1 \n"); 
        break;

    case 2: printf("case 2 \n"); 
        
    case 3: printf("case 3 \n");
        break;

    default: printf("default case \n");
    }; 
}