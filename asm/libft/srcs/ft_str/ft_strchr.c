/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:40:38 by mleconte          #+#    #+#             */
/*   Updated: 2015/02/02 00:13:58 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*temp;

	temp = (char*)s;
	while (*temp != c && *temp)
		temp++;
	if (*temp != c)
		return (NULL);
	return (temp);
}
