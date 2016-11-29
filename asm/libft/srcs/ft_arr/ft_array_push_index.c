/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_push_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:10:20 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/05 15:14:02 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** This function duplicates the value `*value` and push it at position `index`
** of the array pointed by `***array` through an allocation of a new one.
** If either parameter is NULL, it returns -1.
** If the array pointed by `***array` is NULL, a new one is created.
** On failure, the function returns -1 and `***array` is not changed.
** On success, the function returns the new size of the array.
*/

static int	s_return_and_free(char **new_array, size_t total)
{
	while (total > 0)
	{
		total--;
		ft_memdel((void **)&new_array[total]);
	}
	free(new_array);
	return (-1);
}

static int	s_iterate_on_array(char **array, char ***new_array,
						size_t index, size_t *total)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		if (i == index)
		{
			(*new_array)[*total] = NULL;
			(*total)++;
		}
		if (((*new_array)[*total] = ft_strdup(array[i])) == NULL)
			return (-1);
		(*total)++;
		i++;
	}
	return (0);
}

int			ft_array_push_index(char ***array, char const *value,
				size_t index)
{
	char	**new_array;
	size_t	total;

	if (!value || !array)
		return (-1);
	total = 0;
	while (*array && (*array)[total])
		total++;
	if (index > total)
		index = total;
	if ((new_array = (char **)malloc(sizeof(char *) * (total + 2))) == NULL)
		return (s_return_and_free(new_array, 0));
	if (*array && total > 0)
	{
		total = 0;
		if (s_iterate_on_array(*array, &new_array, index, &total) == -1)
			return (s_return_and_free(new_array, total));
	}
	total = total == 0 ? 1 : total;
	if ((new_array[index] = ft_strdup(value)) == NULL)
		return (s_return_and_free(new_array, total));
	new_array[total] = NULL;
	ft_arrdel(&(*array));
	*array = new_array;
	return (total);
}
