/*
   Use of simple arrays as parameters - Sorting bubble sort
   Joao Colombari 
   Nov, 08, 2023
*/

/*
    Para entender:

    Yes, that's correct. In the swap function, you are passing 
    two integer pointers a and b. These pointers contain memory 
    addresses. When you use the * operator inside the swap 
    function, you are accessing the values that these pointers 
    are pointing to in memory.

    Entao a fita e a seguinte, o endereco e o mesmo, eu to trocando
    o dado de lugar e mantendo os enderecos como estavam.
*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int how_many, int data[], char *str)
{
    int i;
    printf("%s", str);
    
    for (i = 0; i < how_many; i++)
    {
        printf("%d\t", data[i]);
    }
}

void bubble(int data[], int how_many)
{
    int i, j;
    int go_on;

    for (i = 0; i < how_many; i++)
    {
        print_array(how_many, data, "\nInside bubble\n");
        printf("i = %d, input any int to continue: ",i);
        scanf("%d", &go_on);
        for (j = how_many - 1; j > i; j--)
        {
            if(data[j-1] > data[j])
            {
                swap(&data[j-1], &data[j]);
            }
        }
    }
}

int main(void)
{
    const int SIZE = 5;
    int grades[SIZE] = {78, 67, 92, 83, 88};

    print_array(SIZE, grades, "My grades\n");
    printf("\n\n");
    bubble(grades, SIZE);
    print_array(SIZE, grades, "My sorted grades\n");
    printf("\n\n");
    return 0;
}