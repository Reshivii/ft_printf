/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:29:27 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/25 19:24:14 by aburnott         ###   ########.fr       */
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
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_hexa(unsigned long hex, int type);
int		ft_void_hexa(void *p, int type);
int		ft_uns_putnbr(unsigned int nb);

#endif