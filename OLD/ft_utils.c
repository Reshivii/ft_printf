/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:43:38 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/25 23:15:01 by aburnott         ###   ########.fr       */
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

int	ft_putchar(int c)
{
	int	i;

	i = 0;
	write(1, &c, 1);
	return (i + 1);
}

int	ft_putstr(char *s)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		len += 6;
		return (len);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
		len++;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		len += 11;
		return (len);
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		len += 1;
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (len);
}
