/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:32:20 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/17 21:32:20 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_strzero(int len)
{
	char    *res;

	res = NULL;
	if (len < 0)
		len = 0;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	while (len)
		res[--len] = '0';
	return (res);
}
