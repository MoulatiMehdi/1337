#ifndef TEST_H
#define TEST_H

#include "constant.h"
#include <stdio.h>

void status(int error, char *desc)
{
    if (error)
        printf(FAIL RED "");
    else
        printf(PASS GREEN "");
    printf(" %s\n" DEFAULT, desc);
}
void pass(char *desc)
{
    printf("\t" GREEN CHECKMARK " ");
    printf(GRAY " %s\n" DEFAULT, desc);
}

#endif