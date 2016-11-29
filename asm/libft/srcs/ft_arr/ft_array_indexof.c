/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_indexof.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:09:58 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/05 15:10:00 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This functions may iterate on `**array` and compare each element to
** the string `*str` with the function `ft_strcmp`.
** It returns `1` on success and `0` on missing element.
*/

int	ft_array_indexof(char const **array, char const *str)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strcmp(array[i], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}
