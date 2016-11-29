/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:21:40 by mleconte          #+#    #+#             */
/*   Updated: 2016/05/25 18:49:17 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarray_fd(char const **array, int fd)
{
	while (array && *array)
	{
		ft_putstr_fd(*array, fd);
		array++;
	}
}
