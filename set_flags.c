/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:32:35 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/17 21:32:36 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     set_flags(t_gen *gen_struct, const char *format)
{
    int     counter;

    counter = 0;
    if (*format == '#')
        gen_struct->flag.hash = 1;
    if (*format == '0' && !gen_struct->flag.zero)
        gen_struct->flag.zero = 1;
    if (*format == ' ' && !gen_struct->flag.space)
        gen_struct->flag.space = 1;
    if (*format == '+')
    {
        gen_struct->flag.space = 0;
        gen_struct->flag.plus = 1;
    }
    if (*format == '-')
    {
        gen_struct->flag.minus = 1;
        gen_struct->flag.zero = 0;
    }
    counter++;
    return (counter);
}
