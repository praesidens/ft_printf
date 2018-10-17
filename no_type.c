/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:32:31 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/17 21:32:32 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *no_type_helper(t_gen *gen_struct, char type);

int     no_type(t_gen *gen_struct)
{
    size_t  len;
    int     ctr;
    char    type;
    char    *str;

    ctr = 0;
    type = G->type;
    str = no_type_helper(gen_struct, type);
    len = ft_strlen(str);
    G->F.minus != 0 ? write(1, str, len) : ft_print_ch(' ', G->width - (int)len, &ctr);
    G->F.minus == 0 ? write(1, str, len) : ft_print_ch(' ', G->width - (int)len, &ctr);
    free(str);
    return ((int)len + ctr);

}

static char *no_type_helper(t_gen *gen_struct, char type)
{
    char    *res;
    char    *s1;
    char    *s2;

    res = NULL;
    if (G->F.minus)
        G->F.zero = 0;
    if (G->F.zero && G->prec == -1 && G->width >= 0)
    {
        s1 = ft_strzero(G->width > 1 ? G->width - 1 : 0);
        s2 = ft_strsub(&type, 0, 1);
        res = ft_strljoin(&s1, &s2);
    }
    else if (G->F.zero && G->prec >= 0)
    {
        s1 = ft_strzero(G->width - 1 <= 0 ? 0 : G->width - 1);
        s2 = ft_strsub(&type, 0, 1);
        res = ft_strljoin(&s1, &s2);
    }
    else
        res = ft_strsub(&type, 0, 1);
    return (res);
}
