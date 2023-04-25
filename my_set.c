#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define NO_SPACE_CODE 1
#define ENLARGE_SIZE(CURR_length) (CURR_length) + 10

/*
    Creates a set from the given integers
    **set - the set's refferns
    *set_length - the set_length's refferns
*/
int get_set(int **set, int *set_length);

/*
    Prints the set in order without duplicates
    *set - the set
    length - the set's length
*/
void print_set(int *set, int length);

/*
    Checks if the given value exists in the set between two specific indexes
    *set - the set
    start_idx - the index to start check from
    end_idx - the index to stop check
    value - value to check.
*/
int is_exists(int *set, int start_idx, int end_idx, int value);

int main()
{
    int error_code, set_length;
    int *set;

    error_code = get_set(&set, &set_length);
    if (error_code == 0)
    {
        print_set(set, set_length);
    }

    free(set);
    return error_code;
}

int get_set(int **set, int *set_length)
{
    int *set_p;
    int counter = 0;

    *set_length = ENLARGE_SIZE(0);
    *set = (int *)malloc(*set_length * sizeof(int));
    if (set_p == NULL)
    {
        printf("No space\n");
        return NO_SPACE_CODE;
    }
    printf("Please enter numbers\n");
    while ((scanf("%d", &(*set)[counter])) != EOF)
    {

        printf("set[%d] => %d\n", counter, (*set)[counter]);

        /* checks if realloc is needed*/
        if (counter == *set_length)
        {
            *set_length = ENLARGE_SIZE(*set_length);
            set_p = (int *)realloc(*set, *set_length * sizeof(int));
            if (set_p == NULL)
            {
                printf("No space\n");
                return NO_SPACE_CODE;
            }
            *set = set_p;
        }

        counter++;
    }

    *set_length = counter;
    set_p = (int *)realloc(*set, *set_length * sizeof(int));
    if (set_p == NULL)
    {
        printf("No space\n");
        return NO_SPACE_CODE;
    }
    *set = set_p;

    return 0;
}

void print_set(int *set, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (!is_exists(set, 0, i, set[i]))
        {
            printf("%d ", set[i]);
        }
    }
    printf("\n");
}

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