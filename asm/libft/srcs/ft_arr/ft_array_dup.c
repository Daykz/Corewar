/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:09:49 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/05 15:12:15 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** This functions may duplicate `**array`, or return NULL
*/

char	**ft_array_dup(char **array)
{
	size_t	size;
	char	**new_array;

	size = 0;
	while (array[size])
		size++;
	if ((new_array = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	size = 0;
	while (array[size])
	{
		if ((new_array[size] = ft_strdup(array[size])) == NULL)
			return (NULL);
		size++;
	}
	new_array[size] = NULL;
	return (new_array);
}
