#include <stdio.h>
#include <stdlib.h>
#define ENLARGE_SIZE(CURR_SIZE) (CURR_SIZE) + 10

int get_set(int **group, int *curr_size);
void print_set(int *group, int size);

int main()
{
    int error_code;
    int group_size = ENLARGE_SIZE(0);
    int *group = (int *)malloc(group_size * sizeof(int));

    error_code = get_set(&group, &group_size);
    if (error_code == 0)
    {
        print_set(group, group_size);
    }
    
    free(group);
    return error_code;
}

int get_set(int **group, int *curr_size)
{
    int *group_p;
    int user_input, counter = 0;
    printf("Group_size is: %d\n", *curr_size);
    printf("Please enter numbers\n");
    while ((scanf("%d", &user_input)) != EOF)
    {
        (*group)[counter] = user_input;
        printf("the counter is: %d  user input is: %d\n", counter, (*group)[counter]);

        if (counter == *curr_size)
        {
            *curr_size = ENLARGE_SIZE(*curr_size);
            group_p = (int *)realloc(*group, *curr_size * sizeof(int));
            if (group_p == NULL)
            {
                printf("No space\n");
                return 1;
            }
            printf("Group_size is: %d\n", *curr_size);
            *group = group_p;
        }

        counter++;
    }

    return 0;
}

void print_set(int *group, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%d => %d\n", i, group[i]);
        i++;
    }
}