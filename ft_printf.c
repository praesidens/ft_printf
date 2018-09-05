#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
    va_list     args;
    int         res;
    int         i;

    res = 0;
    i = 0;
    va_start(args, format);
    while (format[i++])
    {
        if (format[i] == '%' && !(ft_strequ(format, "% ")))
            res += ft_parser((format + (i += 1)), &args, &i);
        if (!format[i])
            break ;
        if (format[i] == '%' && !(ft_strequ(format, "% ")))
        {
            i--;
            continue ;
        }
        write(1, &format[i], 1);
        res++;
    }
    va_end(args);
    return (res);
}

int    ft_parser(const char *format, va_list *args, int *i)
{
	t_gen       gen;
    int         j;
    int         mod_counter;

    mod_counter = 0;
    j = 0;
	while (format[j])
    {
        while (ft_strchr(FLAGS, format[j]))
            j += set_flags(&gen, &format[j]);
        if (format[j] >= '0' && format[j] <= '9')
            j += set_width(&gen, &format[j]);
        if (format[j] == '.')
            set_precision_helper(&gen, &format[j], &j);
        if (ft_strchr(MOD, format[j]))
            j += set_mod(&gen, &format[j], &mod_counter);
        if (!(ft_strchr(ALL_SYMB, format[j])))
        {
            *i += j + 1;
            return (set_type(&gen, &format[j], args));
        }
    }
    return (0);
}

int     set_type(t_gen *gen_struct, const char *format, va_list *args)
{
    int     i;
    int     c;
    const t_func_arr funcs[] = {{'s', &conv_to_str}, {'S', &conv_to_unistr},
                        {'p', &conv_to_ptr}, {'d', &conv_to_decimal},
                        {'D', &conv_to_decimal}, {'i', &conv_to_decimal},
                        {'o', &conv_to_octal}, {'O', &conv_to_octal},
                        {'u', &conv_to_unsigned}, {'U', &conv_to_unsigned},
                        {'x', &conv_to_hex}, {'X', &conv_to_hex},
                        {'c', &conv_to_char}, {'C', &conv_to_unichar}, {0, NULL}};
    i = 0;
    c = -1;
    if (ft_strchr(TYPE, format[i]))
    {
        gen_struct->type = format[i];
        while (funcs[++c].ident != gen_struct->type)
            ;
        return (funcs[c].func(*args, gen_struct));
    }
    else
    {
        gen_struct->type = format[i];
        return (no_type(gen_struct));
    }
}