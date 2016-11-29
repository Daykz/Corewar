/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:10:05 by mleconte          #+#    #+#             */
/*   Updated: 2015/02/02 00:16:20 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return ((char *)s2);
	else if (s1 && !s2)
		return ((char *)s1);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = ft_strnew(i + j + 1);
	if (str)
	{
		str = ft_strcpy(str, s1);
		str = ft_strcat(str, s2);
	}
	return (str);
}
