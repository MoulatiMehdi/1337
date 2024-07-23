#include "ft.h"
#include <stdio.h>

#define DEFAULT "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;92m"
#define GRAY "\033[1;30m"

#define PASS "\033[1;30;102m PASS " DEFAULT
#define FAIL "\033[1;37;101m FAIL " DEFAULT

#define CROSSMARK "x"
#define CHECKMARK "v"

typedef struct s_test
{
    char *desc;
    char *map[100];
    int rows;
    int cols;
    int expected;
} t_test;

// Function to read the map from the file

int main(void)
{
    t_test test[] = {
        {.desc = "A Valid Map",
         .map = {"3.ox", ".", ".", ".", NULL},
         .expected = 1},
        {.desc = "Only number in the first line", .map = {"2123", "1", "2", NULL}, .expected = 1},
        {.desc = "Missing Row", .map = {"9.ox", ".", ".", NULL}, .expected = 0},
        {.desc = "Empty First Line", .map = {"", ".", ".", NULL}, .expected = 0},
        {.desc = "Less characters in the First Line", .map = {"2xo", ".", ".", NULL}, .expected = 0},
        {.desc = "Too much characters in the First Line", .map = {"2xopl", ".", ".", NULL}, .expected = 0},
        {.desc = "No Number of Rows in the First Line", .map = {"x.op", ".", ".", NULL}, .expected = 0},
        {.desc = "Duplicate character in the Set", .map = {"9.xx", ".", ".", NULL}, .expected = 0},
        {.desc = "invalid charcter in the line", .map = {"9xop", "x", ".", "x", NULL}, .expected = 0},
        {.desc = "zero rows in the first line", .map = {"0.op", "x", ".", NULL}, .expected = 0},
        {.desc = "no rows in the map", .map = {"0xop", NULL}, .expected = 0},
    };
    int error;
    int size = sizeof(test) / sizeof(t_test);
    char **map;
    int i;
    int result;
    i = 0;
    error = 0;

    while (i < size)
    {
        map = test[i].map;
        result = is_valid_data(map);
        if (result == test[i].expected)
        {
            printf("\t" GREEN CHECKMARK " ");
            printf(GRAY " %s\n" DEFAULT, test[i].desc);
        }
        else
        {
            error++;
            printf("\t" RED CROSSMARK " ");
            printf(RED " %s", test[i].desc);
            printf(" Expected '%d' Got '%d'\n" DEFAULT, test[i].expected, result);
        }
        i++;
    }
    if (error)
        printf(FAIL RED "");
    else
        printf(PASS GREEN "");

    printf(" is_valid_data() function\n" DEFAULT);
}