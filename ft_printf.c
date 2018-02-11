#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;

	int i = 0;
	va_start(ap, format);
	while (*format++)
	{
		if (*format == '%')
		{
			str = va_arg(vl, char *);
			ft_putstr(str);
			break;
		}
	}
	va_end(ap);
	ft_putchar('\n');
}