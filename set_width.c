/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:32:46 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/17 21:32:47 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    set_width(t_gen *gen_struct, const char *format)
{
    int     counter;

    counter = 0;
    if (ft_isdigit(*format))
    {
        gen_struct->width = ft_atoi(format);
        counter = (int)ft_num_len(gen_struct->width, 10);
    }
    else
        counter++;
    return (counter);
}
