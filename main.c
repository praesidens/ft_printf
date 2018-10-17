/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:32:27 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/17 21:32:28 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int     main(void)
{
    int     cecimal_num;
    int     decimal_num;
    cecimal_num = 12333;
    decimal_num = 4536;

    ft_printf("FT_PRINTF %ld\n", decimal_num);
    printf("RET VAL: %d\n", ft_printf("FT_PRINTF %ld\n", decimal_num));
    printf("%d\n", adecimal_num);
    ft_printf("FT_PRINTF %d\n", decimal_num);
    printf("%d\n", decimal_num);
    ft_printf("FT_PRINTF %i\n", cecimal_num);
    printf("%i\n", cecimal_num);
    return (0);
}
