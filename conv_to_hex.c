#include "ft_printf.h"
/*
int     conv_to_hex(t_gen *gen_struct, const char *format, va_list args)
{
    long            remainder;
    char            *hex;
    unsigned int    len;

    len = ft_hex_len(decimal_num) - 1;
    hex = (char*)malloc(sizeof(char) * (len + 2));
    hex[len + 1] = '\0';
    while (decimal_num != 0)
    {
        remainder = decimal_num % 16;
        if (remainder < 10)
            hex[len--] = remainder + 48;
        else
            hex[len--] = remainder + 55;
        decimal_num /= 16;
    }
    printf("HEX: %s\n", hex);
    return (hex);
}
 */