/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:43:34 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/18 11:32:54 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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
