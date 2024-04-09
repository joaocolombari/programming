/*
   Explores the storage classes 
   Joao Colombari 
   Nov, 06, 2023
*/

#include <stdio.h>

extern int reps = 0;                    // Global variable, every
                                        // function can use it       

void f(void)
{
    static int called = 0;              // variable mantains value 
                                        // throughout calls
    printf("f called %d\n", called);
    called++;
    reps = reps + called;
}

int main(void)
{
    auto int i = 1;                     // O compilador que decide
                                        // o tempo de vida 
    const int Limit = 10;               // Initial value is to remain
                                        // throug the code
    for (i = 1; i < Limit; i++)
    {
        printf("i local = %d, reps global = %d\n", i, reps);
        f();
    }

    return 0;    
}