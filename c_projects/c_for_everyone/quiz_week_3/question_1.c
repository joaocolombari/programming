/*
   test week 3  
   Joao Colombari 
   Nov, 04, 2023
*/

#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */

// The program is suppose to use the sin() function 
// in the math library and write out an input's 
// absolute value over an interval.
// So for example if sine(0.6) is 0.564 then its 
// absolute value is the same (0.564).  But if 
// sine(2.4) is -0.675 then its absolute value is 0.675. 

int main(void)
{ 
    double interval, maximum = 0;
    int i;

    for(i = 0; i <30; i++)
    {
        // var current stores the corrected abs function
        double current = fabs(sin(interval)); 

        interval = i/10.0;
        printf("sin( %lf ) = %lf \n", interval, 
                            current);

        // checks if current is greater than maximum
        if (current > maximum)
        {
            maximum = current;
        }
    }

    printf("\n+++++++\n");

    printf("\nMaximum value is: %lf\n\n", maximum);

    return 0;
}