/*
   Marathon in Yards 
   Joao Colombari 
   Oct, 26, 2023
*/

#include <stdio.h>

int main(void)
{
   double kilometers, miles, yards;

   printf("Please enter kilometers and miles as double:\n");
   scanf("%lf %lf", &kilometers, &miles);
   
   printf("kilometers = %lf, miles = %lf", kilometers, miles);
   yards = 1760.0 * (kilometers/1.609 - miles);
   printf("\nA marathon is %lf yards.\n\n", yards);
   return 0;
}

