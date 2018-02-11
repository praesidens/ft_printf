#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;

	int i = 0;
	va_start(ap, format);
	ft_parse_params(format, ap);
	va_end(ap);
	ft_putchar('\n');
}


void		ft_putnstr(char *start, char *format)
{
	size_t	n;

	n = format - start;

}
int		ft_parse_params(const char *format, va_list ap)
{
	char		*start;

	start = NULL;
	while (*format++)
	{
		if (*format == '%')
		{
			ft_parse_params(format, ap);
			break;
		}
		else if (*format != '%')
		{
			start = format;
			while (*format && *format != '%')
				format++;
		}
	}
}


base = 8;
str = "0123456789ABCDEF";
str[nbr % base]
nbr / 8;