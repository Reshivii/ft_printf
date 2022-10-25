/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:28:17 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/25 17:40:46 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_hexa(unsigned long hex, t_data *data, int type)
{
	if (hex >= 16)
		ft_hexa(hex / 16, data, type);
	hex %= 16;
	if (hex >= 10)
	{
		if (type == 1)
			hex += 87;
		else
			hex += 55;
		write (1, &hex, 1);
		data->len += 1;
	}
	else
	{
		hex += 48;
		write (1, &hex, 1);
		data->len += 1;
	}
}

void	ft_void_hexa(void *p, t_data *data, int type)
{
	write (1, "0x", 2);
	data->len += 2;
	if ((unsigned long)p == 0)
	{
		write (1, "0", 1);
		data->len += 1;
	}
	else
		ft_hexa((unsigned long)p, data, type);
}

void	ft_uns_putnbr(unsigned int nb, t_data *data)
{
	int	nb_u;

	if (nb >= 10)
	{
		ft_uns_putnbr(nb / 10, data);
		nb %= 10;
	}
	if (nb <= 9)
	{
		nb_u = nb + 48;
		write (1, &nb_u, 1);
		data->len += 1;
	}
}
