/* 
    Char in C 
    Joao Colombari 
    Oct, 30, 2023
*/

#include <stdio.h>

int main(void)
{
    char c = 'a';
    printf("c in ASCII is %d\n", c);
    printf("c the character %c\n\n", c);
    printf("Three consecutive chars are: %c%c%c \n\n", c, c+1, c+2);
    printf("Three bell rings chars are: %c%c%c \n\n", '\a', '\a', '\a');

    return 0;
}
