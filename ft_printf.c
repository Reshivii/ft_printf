/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:27:10 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/26 00:24:49 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(va_list arg, char c, int *len)
{
	if (c == 'c')
		*len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		*len += ft_putstr(va_arg(arg, char *));
	// else if (c == 'p')
	// 	*len += ft_void_hex();
	else if (c == 'i' || c == 'd')
		*len += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		*len += ft_putnbr(va_arg(arg, unsigned int));
	// else if (c == 'x')
	// 	*len += ft_hexa();
	// else if (c == 'X')
	// 	*len += ft_hexa();
	// else if (c == '%')
	// 	*len += ft_putchar('%');
	else
		return (0);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, s);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			check_format(arg, s[++i], &len);
		else
			len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}

/* Checking for NULL string
if (!s)
{
	write (1, "(null)", 6);
	len += 6;
	va_end(arg);
}*/