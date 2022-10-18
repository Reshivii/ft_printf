/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:43:38 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/18 20:47:11 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
			return ((char *)s + i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

void	ft_putchar(int c, t_data *data)
{
	write(1, &c, 1);
	data->len += 1;
}

void	ft_putstr(char *s, t_data *data)
{
	int		res;
	int		i;

	if (!s)
	{
		write (1, "(null)", 6);
		data->len += 6;
		return ;
	}
	res = 0;
	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
		res++;
	}
	data->len += res;
}

void	ft_putnbr(int nb, t_data *data)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		data->len += 11;
		return ;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		data->len += 1;
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, data);
		ft_putnbr(nb % 10, data);
	}
	else
		ft_putchar(nb + 48, data);
}
