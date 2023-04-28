#include <stdio.h>
#include <stdlib.h>
#include "set.h"

#define FALSE 0
#define TRUE 1
#define NO_SPACE_CODE 1
#define ENLARGE_SIZE(SIZE) (SIZE) + 10

/*
    Checks if the given value exists in the set between two specific indexes
    @param *set - the set
    @param start_idx - the index to start check from
    @param end_idx - the index to stop check
    @param value - value to check.
*/

int is_exists(int *set, int start_idx, int end_idx, int value)
{
    int i;
    for (i = start_idx; i < end_idx; i++)
    {
        if (set[i] == value)
        {
            return TRUE;
        }
    }
    return FALSE;
}

/*
    Creates a set from the given integers
    @param **set - the set's refferns
    @param *set_length - the set_length's refferns
*/
int get_set(int **set, int *set_length)
{
    int *temp;
    int counter = 0;
    *set_length = ENLARGE_SIZE(0);
    *set = (int *)malloc(*set_length * sizeof(int));
    if (*set == NULL)
    {
        printf("No space\n");
        return NO_SPACE_CODE;
    }

    printf("Please enter numbers\n");
    while ((scanf("%d", &(*set)[counter])) != EOF)
    {
        printf("%d added successfully\n", (*set)[counter]);

        /* checks if realloc is needed*/
        if (counter == *set_length)
        {
            *set_length = ENLARGE_SIZE(*set_length);
            temp = (int *)realloc(*set, *set_length * sizeof(int));
          
            if (temp == NULL)
            {
                printf("No space\n");
                return NO_SPACE_CODE;
            }
          
            *set = temp;
        }

        counter++;
    }

    *set_length = counter;
    temp = (int *)realloc(*set, *set_length * sizeof(int));

    if (temp == NULL)
    {
        printf("No space\n");
        return NO_SPACE_CODE;
    }

    *set = temp;

    return 0;
}

/*
    Prints the set in order without duplicates
    @param *set - the set
    @param length - the set's length
*/
void print_set(int *set, int length)
{
    int i;
    printf("The set is: \n");

    for (i = 0; i < length; i++)
    {
        if (!is_exists(set, 0, i, set[i]))
        {
            printf("%d ", set[i]);
        }
    }

    printf("\n");
}
