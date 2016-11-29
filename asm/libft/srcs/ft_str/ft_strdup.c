/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:14:06 by mleconte          #+#    #+#             */
/*   Updated: 2015/02/02 00:15:53 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*t1;

	i = 0;
	t1 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (t1 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		t1[i] = s1[i];
		i++;
	}
	t1[i] = '\0';
	return (t1);
}
