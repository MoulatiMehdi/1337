#include "ft_utils.h"

void *ft_realloc(void *mem, int size)
{

    void *new_mem;
    int i;

    i = 0;
    new_mem = malloc(size);
    if (!new_mem)
        return 0;
    if (mem)
        while (i < size)
        {
            ((char *)new_mem)[i] = ((char *)mem)[i];
            i++;
        }
    free(mem);
    return new_mem;
}