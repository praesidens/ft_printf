/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:32:23 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/17 21:32:24 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    init_struct(t_gen *gen_struct)
{
    gen_struct->flag.hash = 0;
    gen_struct->flag.zero = 0;
    gen_struct->flag.minus = 0;
    gen_struct->flag.plus = 0;
    gen_struct->flag.space = 0;
    gen_struct->mod.hh = 0;
    gen_struct->mod.h = 0;
    gen_struct->mod.l = 0;
    gen_struct->mod.ll = 0;
    gen_struct->mod.j = 0;
    gen_struct->mod.z = 0;
    gen_struct->width = -1;
    gen_struct->prec = -1;
    gen_struct->type = 'u';
//    ft_bzero(gen_struct->last_mod, 3);
}

