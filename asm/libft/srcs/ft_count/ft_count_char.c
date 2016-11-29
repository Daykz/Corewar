/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 17:53:20 by mleconte          #+#    #+#             */
/*   Updated: 2016/05/25 17:36:04 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

size_t	ft_count_char(char const *str, char c)
{
	size_t count;

	count = 0;
	if (str)
	{
		while (*str)
		{
			if (*str++ == c)
				count++;
		}
	}
	return (count);
}
