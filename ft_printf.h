/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 22:40:29 by bsuprun           #+#    #+#             */
/*   Updated: 2018/02/10 22:40:34 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"

typedef struct s_print
{
	t_conv		conv;
	t_flag		flag;
	int			perc = 0;
	int			width = 0;
	int			prec = 0;	
}				t_gen;

typedef struct 	s_conv
{
	int		s = 0;
	int		S = 0;
	int		p = 0;
	int		d = 0;
	int		D = 0;
	int		i = 0;
	int		o = 0;
	int		O = 0;
	int		u = 0;
	int		U = 0;
	int		x = 0;
	int		X = 0;
	int		c = 0;
	int		C = 0;
}				t_conv;

typedef struct 	s_flag
{
	int			hash = 0;
	int			zero = 0;
	int			minu = 0;
	int			plus = 0;
	int			spac = 0;
	int			hh = 0;
	int			h = 0;
	int			l = 0;
	int			ll = 0;
	int			j = 0;
	int			z = 0;
}				t_flag;

#endif