/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:29:27 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/18 20:47:46 by aburnott         ###   ########.fr       */
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
void	ft_putchar(int c, t_data *data);
void	ft_putstr(char *s, t_data *data);
void	ft_putnbr(int nb, t_data *data);
void	ft_hexa(unsigned long hex, t_data *data, int type);
void	ft_void_hexa(void *p, t_data *data, int type);
void	ft_uns_putnbr(unsigned int nb, t_data *data);

#endif