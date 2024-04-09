/*
   test week 3  
   Joao Colombari 
   Nov, 04, 2023
*/

#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */

// Write a C program that has a function that prints 
// a table of values for sine and cosine between (0, 1). 
// Upload your program as a text file. 

int main(void)
{
    double index;

    for (index=0.0; index<=1; index=index+0.1)
    {
        printf("Sine of \t %lf is \t %lf\n", index, sin(index));
        printf("Cossine of \t %lf is \t %lf\n\n", index, cos(index));
    }

    return 0;
}