/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:31:17 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/17 21:31:18 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** G gen_struct (main structure in the whole programme)
** F flag (flag is a struct, which is used inside
** of the main struct in order to mark flags "#0-+ "
** W width
** P plus
** S space
*/

char 	*ft_itoa_oct(t_gen *gen_struct, int len, int ch, unsigned long long num)
{
	int 	j;
	int 	*r;

	j = 0;
	while (num /= 8)
		j++;
	if (!G->F.hash)
		ch = 0;
	else if (num == 0 && G->prec != 0)
		ch = 0;
	len = j > len ? j : len;
	if (!(r = (char*)malloc((len += (ch == '#' ? 1 : 0)) + 1)))
		return (NULL);


}

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
			str = ft_itoa_oct(gen_struct, G->prec - 1, G->F.hash ? '#' : 0, num);
	}

    oct_len = ft_num_len(oct, 8);
    //printf("OCT_LEN = %zu\n", oct_len);
    write(1, ft_itoa_base((int)oct, 8), oct_len);
    write(1, "\n", 1);
    init_struct(gen_struct);
    return ((int)oct_len);
}
