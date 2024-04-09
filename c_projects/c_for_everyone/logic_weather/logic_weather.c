/*
   Logical Operators and short circuit evaluation - weather 
   Joao Colombari 
   Oct, 26, 2023
*/

#include <stdio.h>

int main(void)
{
    int outside, weather;

    printf("\nEnter if outside 1 true 0 false:");
    scanf("%d", &outside);

    printf("\nEnter if rain 1 true 0 false:");
    scanf("%d",&weather);

    if (outside && weather) 
   	printf("\nPlease use an umbrella.\n");
    else
	printf("\nDress normally.\n\n");

    return 0;
}

