/* 
    Int Type 
    Joao Colombari 
    Oct, 30, 2023
*/

/*
The letters used as format specifiers in the `printf` and `scanf` families of 
functions in the C programming language are derived from the historical roots of 
the C language and its precursor, the B programming language.

The choice of letters as format specifiers is based on mnemonics that represent 
the data types they are associated with. Here is a brief explanation of some 
common format specifiers and their mnemonic meanings:

- `%d`: Used for `int` data type. The letter "d" stands for "decimal."

- `%f`: Used for `float` data type. The letter "f" stands for "floating point."

- `%c`: Used for `char` data type. The letter "c" stands for "character."

- `%s`: Used for C strings, or arrays of `char`. The letter "s" stands for 
"string."

- `%u`: Used for unsigned integer. The letter "u" stands for "unsigned."

- `%p`: Used for pointer data types. The letter "p" stands for "pointer."

- `%x` and `%X`: Used for printing hexadecimal representations of integers. The 
letter "x" represents the word "hexadecimal."

- `%o`: Used for printing octal representations of integers. The letter "o" 
represents the word "octal."

- `%hd` and `%hu`: Used for `short int` data types. The letter "h" stands for 
"short."

- `%lf`: Used for `double` data type. The letter "l" stands for "long" and the 
letter "f" stands for "floating point."

These mnemonics were chosen to make it easier for programmers to remember and 
understand the meanings of the format specifiers and to provide a consistent and 
intuitive way of formatting different types of data for input and output 
operations. 
*/

#include <stdio.h>

int main(void)
{
    short short_a = 5;
    int normal_a = 67;
    unsigned unsigned_a = 67u;
    long long_a = 67l;
    printf("short_a = %hd, divide by int 2 is %d\n", short_a, short_a/2);
    printf("short_a = %hd, divide by float 2 is %lf\n", short_a, short_a/2.0);
    printf("67 as a char is %c\n", normal_a);
    printf("sizes is bytes of short, int, unsigned and long on my macine:\n");
    printf("%lu, %lu, %lu, %lu\n\n", sizeof(short_a), sizeof(normal_a), 
sizeof(unsigned_a), sizeof(long_a));

    return 0;
}
