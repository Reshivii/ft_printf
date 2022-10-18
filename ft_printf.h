/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:29:27 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/18 17:42:45 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int	len;
	int	width;
}				t_data;

int		ft_printf(const char *s, ...);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s);
void	ft_putchar(int c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);

#endif