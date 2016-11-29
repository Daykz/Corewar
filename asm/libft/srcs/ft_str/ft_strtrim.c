/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:32:18 by mleconte          #+#    #+#             */
/*   Updated: 2016/05/25 20:08:12 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	first(const char *str)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
	{
		res++;
		i++;
	}
	return (res);
}

static int	last(const char *str)
{
	int res;
	int i;

	res = ft_strlen(str);
	i = ft_strlen(str) - 1;
	while (str[i] && ft_isspace(str[i]))
	{
		res--;
		i--;
	}
	if (res == 0)
		return (ft_strlen(str));
	return (res);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s)
	{
		i = first(s);
		j = last(s);
		str = ft_strnew(ft_strlen(s) - i - (ft_strlen(s) - j) + 1);
		k = 0;
		while (i < j)
		{
			str[k] = s[i];
			i++;
			k++;
		}
		return (str);
	}
	else
		return (NULL);
}
