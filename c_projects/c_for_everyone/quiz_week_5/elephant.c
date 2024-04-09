/*
   Given the attached file listing elephant seal weights (elephant_seal_data), 
   read them into an array and compute the average weight for the set of the 
   elephant seals.

   Joao Colombari 
   Nov, 08, 2023
*/

#include <stdio.h>
#include <stdlib.h>

double average(int how_many, int data[]) 
{
    int sum = 0;
    for (int i = 0; i < how_many; i++) 
    {
        sum += data[i];
    }
    return (double)sum / how_many;
}

int *get_data(const char *filename, int size) 
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        perror("Error opening file");
        return NULL;
    }

    int *data = (int *)malloc(size * sizeof(int));
    if (data == NULL) 
    {
        fclose(fp);
        return NULL;
    }

    int num, i = 0;
    while (fscanf(fp, "%d", &num) == 1) 
    {
        data[i] = num;
        i++;
    }
    
    fclose(fp);
    return data;
}

long int find_size(const char *filename) 
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) 
    {
        perror("Error opening file");
        return -1;
    }

    // Seek to the end of the file
    fseek(fp, 0, SEEK_END);

    // Get the current position, which is the size of the file in bytes
    long int size = ftell(fp);

    // Close the file
    fclose(fp);

    return size;
}

int main(void) 
{
    const char *filename = "elephant_seal_data.txt";
    long int size = find_size(filename);
    printf("\nFile size is %li\n\n", size);

    int *data = get_data(filename, size);

    if (data != NULL) 
    {
        int data_size = size / sizeof(int);

        // Calculate and print the average weight
        double avg = average(data_size, data);
        printf("Average weight of elephant seals: %.2f\n", avg);

        // Free the allocated memory
        free(data);
    }

    return 0;
}