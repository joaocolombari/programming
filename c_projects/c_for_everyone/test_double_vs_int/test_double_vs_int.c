/*
    Test to see the difference between data types in operations
    Joao Colombari 
    Oct, 27, 2023 
*/

#include <stdio.h>

int main() {
    int intNum1 = 10;
    int intNum2 = 3;
    double doubleNum1 = 10.0;
    double doubleNum2 = 3.0;

    // Division of two integers
    int intResult = intNum1 / intNum2;
    printf("Integer division result: %d\n", intResult);

    // Division of an integer by a double
    double doubleResult1 = intNum1 / doubleNum2;
    printf("Integer divided by double result: %f\n", doubleResult1);

    // Division of a double by an integer
    double doubleResult2 = doubleNum1 / intNum2;
    printf("Double divided by integer result: %f\n", doubleResult2);

    return 0;
}

