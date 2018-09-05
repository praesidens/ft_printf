#include "ft_printf.h"
#include <stdio.h>

int     main(void)
{
    int     cecimal_num;
    int     decimal_num;
    cecimal_num = 12333;
    decimal_num = 4536;

    int     octal_num;

    octal_num = 12312;

    ft_printf("%lo", octal_num);
    //ft_printf("%ld%ld", cecimal_num, decimal_num);
    ft_printf("%00lo", octal_num);
    //printf("PRINTF:%zo\n", octal_num);
    ft_printf("%zd%zd", cecimal_num, decimal_num);
    //printf("PRINTF:%zi\nPRINTF:%zi\n", cecimal_num, (long)decimal_num);
    return (0);
}