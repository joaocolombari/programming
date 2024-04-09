/*
    Hello World in c, first Lab
    Joao Colombari	
    Oct, 26, 2023


    Wrong verison:
    int main(void)
    {
    int radius;
    printf(“Enter radius:”);
    scanf(“% d”, &radius);
    printf(“volume is: % d \n\n“, 4 * radius * radius * radius / 3);
    return 0;
    }
*/

#include <stdio.h>
#define PI 3.14159

int main(void)
{
    double radius;
    printf("Enter radius:");
    scanf("%lf", &radius);
    printf("volume is: %lf \n\n", 4 * PI * radius * radius * radius / 3);
    return 0;
}
