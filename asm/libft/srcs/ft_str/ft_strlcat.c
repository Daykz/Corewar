/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:56:57 by mleconte          #+#    #+#             */
/*   Updated: 2015/02/02 00:16:36 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;
	size_t lens;

	i = 0;
	while (i < size)
	{
		if (dst[i] == '\0')
			break ;
		i++;
	}
	lens = i + ft_strlen(src);
	k = size - i - 1;
	if (i != size)
	{
		j = 0;
		while (src[j] && j < k)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (lens);
}
