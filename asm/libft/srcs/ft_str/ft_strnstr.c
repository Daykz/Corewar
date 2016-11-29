/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:12:52 by mleconte          #+#    #+#             */
/*   Updated: 2015/02/02 00:19:10 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int				i;
	int				j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		while (s2[j] != '\0' && s2[j] == s1[i] && k < n)
		{
			if (s2[j + 1] == '\0')
				return ((char *)s1 + (i - j));
			i++;
			j++;
			k++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
