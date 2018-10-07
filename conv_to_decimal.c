#include "ft_printf.h"
/*
** G gen_struct (main structure in the whole programme)
** F flag (flag is a struct, which is used inside
** of the main struct in order to mark flags "#0-+ "
** W width
** P plus
** S space
*/

int     conv_to_decimal(t_gen *gen_struct, va_list args)
{
	size_t      len;
	long long   num;
    char        *res;
    int         cnt;

    cnt = 0;
    res = NULL;
    num = fetch_num(G, args);
    if (G->prec == -1 && G->F.zero && !G->F.minus)
    {
        if (G->F.S || num < 0 || G->F.P)
            res = itoa_printf(num, (size_t)G->W - 1, (char)(G->F.P ? '+' : G->F.S));
        else
            res = itoa_printf(num, (size_t)G->W, (char)(G->F.P ? '+' : G->F.S));
    }
    else
        res = itoa_printf(num, (size_t)G->prec, (char)(G->F.P ? '+' : G->F.S));
    if (!G->prec && !num)
        res[ft_strlen(res) - 1] = G->W > 0 ? ' ' : 0;
    len = ft_strlen(res);
    G->F.minus != 0 ? write(1, res, len) : ft_print_ch(' ', G->W - (int)len, &cnt);
    G->F.minus == 0 ? write(1, res, len) : ft_print_ch(' ', G->W - (int)len, &cnt);
    free(res);
    return ((int)len + cnt);
}

char    *itoa_printf(long long int num, int len, char c)
{
    int     i;
    char    *res;

    i = ft_num_len(num, 10);
    len = (len < i) ? i : len;
    if (num < 0)
        return (neg_itoa_printf(-num, len));
    if (!(res = (char*)malloc(sizeof(char) * (len += (c > 0 ? 1 : 0)) + 1)))
        return (NULL);
    res[len] = 0;
    while (len != 0)
    {
        res[--len] = (num % 10) + '0';
        num /= 10;
    }
    if (c)
        res[0] = c;
    return (res);
}

char    *neg_itoa_printf(long long int num, int len)
{
    char    *res;

    len = len < ft_num_len(num, 10) ? ft_num_len(num, 10) : len;
    if (!(res = (char*)malloc(sizeof(char) * ((len += 1) + 1))))
        return (NULL);
    res[len] = 0;
    while (len)
    {
        res[--len] = (num % 10) + '0';
        num /= 10;
    }
    res[0] = '-';
    return (res);
}