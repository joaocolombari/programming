/*
   Convertion of Fahrenheit to Celsius as in:

   C = ( F - 32 ) / 1.8

   Joao Colombari 
   Oct, 26, 2023
*/

#include <stdio.h>

int main(void)
{
   int fahrenheit, celsius;

   printf("Please enter fahrenheit as an integer:");
   scanf("%d", &fahrenheit);
   celsius = (fahrenheit - 32)/1.8; 		//turns into double
   printf("\n %d fahrenheit is %d celsius.\n", fahrenheit, 
celsius);
   return 0;
}


