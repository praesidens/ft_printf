/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:31:57 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/17 21:31:58 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_itoa_base(int num, int base)
{
	int         i;
	int         minus;
	long long   n;
	char        *str;
	size_t      num_len;

	n = num;
	i = 0;
	minus = 0;
	if (n < 0 && base == 10)
	{
		minus = 1;
		n = -n;
	}
	num_len = ft_num_len((int)n, base);
	str = (char*)malloc(sizeof(char) * (num_len + minus + 1));
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	str[num_len + minus] = '\0';
	(minus) ? str[i++] = '-' : str[i++];
	while (n != 0)
	{
		str[num_len - i + minus] = X_CONVERSION[n % base];
		n /= base;
		i++;
	}
	return (str);
}
/*
int     main(void)
{
	printf("LEN:%zu\n", ft_num_len(-2147483647, 10));
	printf("A:%s\n", ft_itoa_base(12312, 8));
	printf("B:%s\n", ft_itoa_base(342423234, 10));
	printf("C:%s\n", ft_itoa_base(-2147483647, 10));

	return (0);
}*/
