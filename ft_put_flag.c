/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:24:03 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/27 00:28:52 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_put_hex(t_type *type)
{
	if()
}

int	ft_put_sp(t_type *type)
{
	if (type->plus)
	{
		write(1, "+", 1);
		return (1);
	}
	else if (type->space)
	{
		write (1, " ", 1);
		return (1);
	}
	return (0);
}
