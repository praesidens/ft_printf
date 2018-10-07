#include "ft_printf.h"

int    set_mod(t_gen *gen_struct, const char *format, int *mod_counter)
{
    int     i;

    i = 0;
    while (*format == 'h' || *format == 'l')
    {
        i++;
        format++;
        *mod_counter += 1;
    }
    if (*format == 'j' || *format == 'z')
    {
        gen_struct->mod.z = *format == 'z' ? 1 : 0;
        gen_struct->mod.j = *format == 'j' ? 1 : 0;
        i++;
    }
    format--;
    set_mod_helper(gen_struct, format, mod_counter);
    return (i);
}

void    set_mod_helper(t_gen *gen_struct, const char *format, int *mod_counter)
{
    if (*mod_counter % 2 == 0 && (*format == 'h' || *format == 'l'))
    {
        gen_struct->mod.hh = *format == 'h' ? 1 : 0;
        gen_struct->mod.ll = *format == 'l' ? 1 : 0;
        gen_struct->mod.h = 0;
        gen_struct->mod.l = 0;
    }
    else if (*format == 'h' || *format == 'l')
    {
        gen_struct->mod.h = *format == 'h' ? 1 : 0;
        gen_struct->mod.l = *format == 'l' ? 1 : 0;
        gen_struct->mod.hh = 0;
        gen_struct->mod.h = 0;
    }
}