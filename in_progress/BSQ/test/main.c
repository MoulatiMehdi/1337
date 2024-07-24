#include <stdio.h>
char *read_file(char *filename);
char *read_input();

int main(int argc, char **argv)
{
    int i;
    char *str;

    if (argc < 2)
    {
        printf("\033[0;30m Enter Text: (to exit press : Enter , Ctrl + z , Enter)\033[0m\n");
        str = read_input();
        printf("%s", str);
    }
    else
    {
        i = 1;
        while (i < argc)
        {
            printf("File '%s' : \n", argv[i]);
            str = read_file(argv[i]);
            printf("%s\n", str);
            i++;
        }
    }
}