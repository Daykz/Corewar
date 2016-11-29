/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:19:32 by mleconte          #+#    #+#             */
/*   Updated: 2015/02/02 00:17:45 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;

	ptr = s1;
	while (ptr && *ptr)
		ptr++;
	while (ptr && s2 && *s2 && n--)
		*(ptr++) = *(s2++);
	*ptr = '\0';
	return (s1);
}
