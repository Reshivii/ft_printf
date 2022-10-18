/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:43:34 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/18 14:14:39 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	ft_check_format(va_list arg, const char *format, t_data *data)
{
	if (*format == 'c')
		ft_putchar_fd(arg, 1);
	else if (*format == 's')
		ft_putstr_fd(arg, 1);
	else if (*format == 'p')
		ft_void_hexa(arg);
	else if (*format == 'i')
		ft_putnbr_fd(arg, 1);
	else if (*format == 'u')
		ft_uns_putnbr(arg);
	else if (*format == 'x')
		ft_hexa(arg, 1);
	else if (*format == 'X')
		ft_hexa(arg, 2);
}

const char	ft_print_text(t_data *data, char *s)
{
	char	*next;

	next = ft_strchr(s, '%');
	if (next)
		data->width = (next - s);
	else
		data->width = ft_strlen(s);
	write (1, s, data->width);
	data->len += data->width;
	while (*s && *s != '%')
		++s;
	return (s);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	t_data	data;

	data.len = 0;
	data.width = 0;
	va_start(arg, s);
	if (!s)
	{
		write(1, "(null)", 6);
		va_end(arg);
		return (data.len);
	}
	while (*s)
	{
		if (*s == '%')
			s = ft_check_format(arg, s + 1, &data);
		else
			s = ft_print_text(&data, s);
	}
	va_end(arg);
	return (data.len);
}
