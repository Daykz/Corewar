/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:39:57 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/28 16:57:31 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbchar(const char *s, char c)
{
	size_t i;
	size_t nb;

	i = 0;
	nb = 0;
	if (s && c)
	{
		while (s[i] && s[i++] != c)
			nb++;
	}
	return (nb);
}
