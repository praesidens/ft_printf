#include "ft_printf.h"

int     conv_to_decimal(t_gen *gen_struct, va_list args)
{
    intmax_t dec;

    size_t int_len;

    if (gen_struct->type != '\0' && gen_struct->mod.z)
        dec = (ssize_t)va_arg(args, intmax_t);
    else if (gen_struct->type != '\0' && gen_struct->mod.j)
        dec = va_arg(args, intmax_t);
    else if (gen_struct->type != '\0' && gen_struct->mod.ll)
        dec = (long long)va_arg(args, intmax_t);
    else if (gen_struct->type != '\0' && gen_struct->mod.l)
        dec = (long)va_arg(args, intmax_t);
    else if (gen_struct->type != '\0' && gen_struct->mod.h)
        dec = (short)va_arg(args, intmax_t);
    else if (gen_struct->type != '\0' && gen_struct->mod.hh)
        dec = (signed char)va_arg(args, intmax_t);
    else
        dec = (int)va_arg(args, int);
    //printf("INT LEN = %d\n", ft_int_len(dec));
    //printf("PRINTF %d\n", (int)dec);
    (void)*(*format)++;
    int_len = ft_num_len(dec, 10);
    //printf("INTLEN = %zu\n", int_len);
    write(1, ft_itoa((int)dec), int_len);
    write(1, "\n", 1);
    return ((int)int_len);
}