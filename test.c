#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h" 

// Function to check for duplicate numbers in the array
int has_duplicates(int *numbers, int count)
{
    int i = 0;
    int j;
    while (i < count - 1)
    {
        j = i + 1;
        while (j < count)
        {
            if (numbers[i] == numbers[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

// Function to validate and parse input arguments
int validate_and_parse_input(int argc, char **argv, int **numbers)
{
    if (argc < 2)
    {
        ft_putendl_fd("Error: No input provided", 2);
        return (1);
    }

    int count = 0;
    int i = 1;
    int j;
    char **args;

    // First pass to count the number of valid integers
    while (i < argc)
    {
        args = ft_split(argv[i], ' ');
        j = 0;
        while (args[j])
        {
            if (!is_valid_number(args[j]))
            {
                ft_putendl_fd("Error: Invalid number", 2);
                while (args[j])
                {
                    free(args[j]);
                    j++;
                }
                free(args);
                return (1);
            }
            count++;
            j++;
        }
        j = 0;
        while (args[j])
        {
            free(args[j]);
            j++;
        }
        free(args);
        i++;
    }

    *numbers = (int *)malloc(sizeof(int) * count);
    if (*numbers == NULL)
    {
        ft_putendl_fd("Error: Memory allocation failed", 2);
        return (1);
    }

    int idx = 0;
    i = 1;

    // Second pass to store the valid integers
    while (i < argc)
    {
        args = ft_split(argv[i], ' ');
        j = 0;
        while (args[j])
        {
            (*numbers)[idx++] = atoi(args[j]);
            free(args[j]);
            j++;
        }
        j = 0;
        while (args[j])
        {
            free(args[j]);
            j++;
        }
        free(args);
        i++;
    }

    if (has_duplicates(*numbers, count))
    {
        ft_putendl_fd("Error: Duplicate numbers", 2);
        free(*numbers);
        return (1);
    }

    return (0);
}

int main(int argc, char **argv)
{
    int *numbers;
    if (validate_and_parse_input(argc, argv, &numbers) != 0)
    {
        return (1);
    }

    // numbers now contains the valid input integers
    // Further processing...

    free(numbers);
    return (0);
}

