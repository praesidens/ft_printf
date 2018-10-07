#include "ft_printf.h"

void    ft_print_ch(char c, int len, int *counter)
{
    while (*counter < len)
    {
        write(1, &c, 1);
        *counter += 1;
    }
}