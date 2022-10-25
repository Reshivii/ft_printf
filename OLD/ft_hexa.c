/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:28:17 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/25 19:23:12 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long hex, int type)
{
	int	len;

	len = 0;
	if (hex >= 16)
		ft_hexa(hex / 16, type);
	hex %= 16;
	if (hex >= 10)
	{
		if (type == 1)
			hex += 87;
		else
			hex += 55;
		write (1, &hex, 1);
		len += 1;
	}
	else
	{
		hex += 48;
		write (1, &hex, 1);
		len += 1;
	}
	return (len);
}

int	ft_void_hexa(void *p, int type)
{
	int	len;

	len = 0;
	write (1, "0x", 2);
	len += 2;
	if ((unsigned long)p == 0)
	{
		write (1, "0", 1);
		len += 1;
	}
	else
		len += ft_hexa((unsigned long)p, type);
	return (len);
}

int	ft_uns_putnbr(unsigned int nb)
{
	int	nb_u;
	int	len;

	len = 0;
	if (nb >= 10)
	{
		ft_uns_putnbr(nb / 10);
		nb %= 10;
	}
	if (nb <= 9)
	{
		nb_u = nb + 48;
		write (1, &nb_u, 1);
		len += 1;
	}
	return (len);
}
