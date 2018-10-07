#include "ft_printf.h"

int     conv_to_octal(t_gen *gen_struct, va_list args)
{
	unsigned long long	num;
	int 				len;
	int 				ctr;
	char 				*str;

	ctr = 0;
	str = NULL;
	num = fetch_unsigned_num(gen_struct, args);
	if (G->prec == -1 && G->F.zero && !G->F.minus)
	{
		if (G->F.hash)
			str = ft_itoa_oct(gen_struct, )
	}


    if (gen_struct->type != '\0' && gen_struct->mod.z)
        oct = va_arg(args, size_t);
    else if (gen_struct->type != '\0' && gen_struct->mod.j)
        oct = (uintmax_t)va_arg(args, uintmax_t);
    else if (gen_struct->type != '\0' && gen_struct->mod.ll)
        oct = (unsigned long long)va_arg(args, unsigned long long);
    else if (gen_struct->type != '\0' && gen_struct->mod.l)
        oct = (unsigned long)va_arg(args, unsigned long);
    else if (gen_struct->type != '\0' && gen_struct->mod.h)
        oct = (unsigned short)va_arg(args, unsigned short);
    else if (gen_struct->type != '\0' && gen_struct->mod.hh)
        oct = (unsigned char)va_arg(args, unsigned char);
    else
        oct = (unsigned int)va_arg(args, unsigned int);
    (void)*(*format)++;
    oct_len = ft_num_len(oct, 8);
    //printf("OCT_LEN = %zu\n", oct_len);
    write(1, ft_itoa_base((int)oct, 8), oct_len);
    write(1, "\n", 1);
    init_struct(gen_struct);
    return ((int)oct_len);
}