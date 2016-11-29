/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:04:23 by mleconte          #+#    #+#             */
/*   Updated: 2015/02/02 00:18:33 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int result;

	if (!s1 || !s2)
		return (0);
	result = (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
	return (result);
}
