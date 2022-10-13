/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:54:04 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/11 18:32:15 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if ((s[i] != c) && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count + 1);
}

char	*word(int *j_int, char const *s, char c)
{
	int		len;
	char	*buf;
	int		i;

	i = 0;
	len = 0;
	while (s[*j_int] == c)
		(*j_int)++;
	while ((s[*j_int + len] != c) && s[*j_int + len])
		len++;
	buf = malloc((len + 1) * sizeof(*buf));
	if (!buf)
		return (0);
	while (i < len)
	{
		buf[i] = s[*j_int];
		i++;
		*j_int = *j_int + 1;
	}
	buf[i] = 0;
	return (buf);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		count;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	count = ft_count(s, c);
	strings = malloc(count * sizeof(char *));
	if (!strings)
		return (0);
	while (i < count - 1)
	{
		strings[i] = word(&j, s, c);
		i++;
	}
	strings[i] = 0;
	return (strings);
}
