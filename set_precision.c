/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:32:42 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/17 21:32:43 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    set_precision(t_gen *gen_struct, const char *format)
{
    if (*format == '.')
    {
        format++;
        if (*format == ' ' || ft_strchr("%sSpdDioOuUxXcC", *format))
            gen_struct->prec = 0;
        if (ft_isdigit(*format) || *format == '-')
            gen_struct->prec = ft_atoi(format);
    }
}

void    set_precision_helper(t_gen *gen_struct, const char *format, int *i)
{
    int     counter;

    counter = 0;
    set_precision(gen_struct, &format[counter]);
    counter++;
    while (format[counter] >= '0' && format[counter] <= '9')
        counter++;
    *i += counter;
}
