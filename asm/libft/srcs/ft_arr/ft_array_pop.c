/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:10:04 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/05 15:12:17 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** This function may pop `total` arguments from `**array` starting
** at element number `start`. It returns the number of arguments
** it has succeeded to pop.
*/

size_t	ft_array_pop(char ***array, size_t start, size_t total)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (i < total && (*array)[start])
	{
		ft_memdel((void **)&(*array)[start]);
		k = 0;
		while ((*array)[start + k + 1])
		{
			(*array)[start + k] = (*array)[start + k + 1];
			k++;
		}
		(*array)[start + k] = NULL;
		i++;
	}
	return (i);
}
