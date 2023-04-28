#include <stdio.h>
#include <stdlib.h>
#include "set.h"

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