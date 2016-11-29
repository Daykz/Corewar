/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 17:53:35 by mleconte          #+#    #+#             */
/*   Updated: 2016/05/25 18:30:21 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_arrdel(char ***array)
{
	int	i;

	i = 0;
	if (array && *array)
	{
		while ((*array)[i])
		{
			free((*array)[i]);
			i++;
		}
		free(*array);
		*array = NULL;
	}
}
