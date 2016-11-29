/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 22:37:59 by mleconte          #+#    #+#             */
/*   Updated: 2016/05/25 19:10:56 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strclean(char const *str)
{
	char	clear[1024];
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (str)
	{
		ft_memset(clear, '\0', 1024);
		while (ft_isspace(*str))
			str++;
		if (!str || !*str)
			return (NULL);
		while (str[++i] && j < 1024)
		{
			if (!ft_isspace(str[i]))
				clear[j++] = str[i];
			else
			{
				if (str[i + 1] && !ft_isspace(str[i + 1]))
					clear[j++] = ' ';
			}
		}
	}
	return (ft_strdup(clear));
}
