/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:43:34 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/25 21:11:16 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_check_format(va_list arg, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (format == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (format == 'p')
		len += ft_void_hexa(va_arg(arg, void *), 1);
	else if (format == 'i' || format == 'd')
		len += ft_putnbr(va_arg(arg, int));
	else if (format == 'u')
		len += ft_uns_putnbr(va_arg(arg, unsigned int));
	else if (format == 'x')
		len += ft_hexa(va_arg(arg, unsigned int), 1);
	else if (format == 'X')
		len += ft_hexa(va_arg(arg, unsigned int), 2);
	else if (format == '%')
		len += ft_putchar('%');
	else
		return (0);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len;
	int		test;

	i = 0;
	len = 0;
	test = 0;
	va_start(arg, s);
	if (!s)
	{
		write(1, "(null)", 6);
		va_end(arg);
		return (len);
	}
	while (s[i])
	{
		while (s[i] != '%')
		{
			write(1, &s[i], 1);
			len++;
			i++;
		}
		if (s[i] == '%')
		{
			test = ft_check_format(arg, s[i + 1]);
			printf("TEST VALUE: %d\n\n\n", test);
			if (test)
				len += test;
			i += 2;
		}
	}
	va_end(arg);
	return (len);
}
