/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:14:24 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/26 00:27:49 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	write (1, s, i);
	return (i);
}

int	ft_putnbr(long nb)
{
	static int	len;
	printf("LENNNN SIZE: %d\n\n\n", len);

	len = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		len++;
		printf("LEN SIZE: %d\n\n\n", len);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb %= 10;
	}
	if (nb <= 9)
	{
		nb += 48;
		write (1, &nb, 1);
	}
	len++;
	printf("LLLEN SIZE: %d\n\n\n", len);
	return (len);
}
