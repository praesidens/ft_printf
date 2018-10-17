/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:31:52 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/17 21:31:53 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long   fetch_num(t_gen *gen_struct, va_list args)
{
	long long   num;

	num = 0;
	if (gen_struct->type == 'D')
		num = (long long)va_arg(args, long);
	else if (gen_struct->mod.z)
		num = (long long)va_arg(args, size_t);
	else if (gen_struct->mod.j)
		num = (long long)va_arg(args, uintmax_t);
	else if (gen_struct->mod.ll)
		num = va_arg(args, long long);
	else if (gen_struct->mod.l)
		num = (long long)va_arg(args, long);
	else if (gen_struct->mod.h)
		num = (long long)(short int)va_arg(args, int);
	else if (gen_struct->mod.hh)
		num = (long long)(signed char)va_arg(args, int);
	else
		num = (long long)va_arg(args, int);
	return (num);
}

unsigned long long fetch_unsigned_num(t_gen *gen_struct, va_list args)
{
	unsigned long long num;

	num = 0;
	if (gen_struct->type == 'U' || gen_struct->type == 'O')
		num = (unsigned long long)va_arg(args, unsigned long);
	else if (gen_struct->mod.z)
		num = (unsigned long long)va_arg(args, size_t);
	else if (gen_struct->mod.j)
		num = (unsigned long long)va_arg(args, uintmax_t);
	else if (gen_struct->mod.ll)
		num = va_arg(args, unsigned long long);
	else if (gen_struct->mod.l)
		num = (unsigned long long)va_arg(args, unsigned long);
	else if (gen_struct->mod.h)
		num = (unsigned long long)(unsigned short)va_arg(args, int);
	else if (gen_struct->mod.hh)
		num = (unsigned long long)(unsigned char)va_arg(args, int);
	else
		num = (unsigned long long)va_arg(args, unsigned int);
	return (num);
}
