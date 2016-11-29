/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:53:29 by mleconte          #+#    #+#             */
/*   Updated: 2015/02/02 00:19:28 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int i;

	i = ft_strlen(s) + 1;
	while (i > 0 && s[i - 1] != c)
		i--;
	if (i > 0)
		return ((char *)(s) + i - 1);
	else
		return (NULL);
}
