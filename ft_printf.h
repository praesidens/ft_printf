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


#ifndef FT_PRINTF_H_
# define FT_PRINTF_H_

# include "./libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <inttypes.h>
# define ALL_SYMB ".#0-+ hljz0123456789"
# define MOD  "hljz"
# define TYPE "sSpdDioOuUxXcC"
# define FLAGS "#0-+ "
# define X_CONVERSION "0123456789abcdef"
# define BIG_X_CONVERSION "0123456789ABCDEF"
# define G gen_struct
# define F flag
# define W width
# define P plus
# define S space

typedef struct 	s_flag
{
	int hash; //0
	int zero; //1
	int minus;//2
	int plus; //4
	int space;//3
}				t_flag;

/*
** variable type of arg
 */
typedef struct	s_mod
{
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_mod;

typedef struct s_gen
{
    t_flag		flag;
    t_mod       mod;
    int			width;
    int			prec;
    char        type;
    int         byte;
}				t_gen;

typedef int (*t_func)(t_gen *gen_struct, va_list args);

typedef struct  s_func_arr
{
    char    ident;
    t_func  func;
}               t_func_arr;

int		ft_printf(const char *format, ...);
int 	ft_parser(const char *format, va_list *args, int *i);
void    init_struct(t_gen *gen_struct);

int     conv_to_hex(t_gen *gen_struct, va_list args);
int     conv_to_octal(t_gen *gen_struct, va_list args);
int     conv_to_str(t_gen *gen_struct, va_list args);
int     conv_to_unistr(t_gen *gen_struct, va_list args);
int     conv_to_ptr(t_gen *gen_struct, va_list args);
int     conv_to_decimal(t_gen *gen_struct, va_list args);
int     conv_to_unsigned(t_gen *gen_struct,  va_list args);
int     conv_to_char(t_gen *gen_struct,  va_list args);
int     conv_to_unichar(t_gen *gen_struct, va_list args);
int     no_type(t_gen *gen_struct);

int     set_flags(t_gen *gen_struct, const char *format);
int     set_width(t_gen *gen_struct, const char *format);
void    set_precision(t_gen *gen_struct, const char *format);
void    set_precision_helper(t_gen *gen_struct, const char *format, int *i);
int     set_mod(t_gen *gen_struct, const char *format, int *mod_counter);
void    set_mod_helper(t_gen *gen_struct, const char *format, int *mod_counter);
int     set_type(t_gen *gen_struct, const char *format, va_list *args);
long long   fetch_num(t_gen *gen_struct, va_list args);
unsigned long long fetch_unsigned_num(t_gen *gen_struct, va_list args);
char    *ft_itoa_base(int num, int base);
char    *itoa_printf(long long int num, int len, char c);
char    *neg_itoa_printf(long long int num, int len);
void    ft_print_ch(char c, int len, int *counter);
char    *ft_strzero(int len);

#endif