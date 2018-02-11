#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}



int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*str;

	int i = 0;
	va_start(ap, fmt);
	while (*fmt++)
	{
		if (*fmt == '%')
		{
			str = va_arg(vl, char *);
			ft_putstr(str);
			break;
		}
		if (*fmt == )
		
	}
	va_end(ap);
	ft_putchar('\n');
}

int		main(void)
{
	ft_printf("aaa %s %s", "ccc", "bbb");
	return (0);
}
