/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 16:09:18 by mleconte          #+#    #+#             */
/*   Updated: 2014/11/09 18:02:23 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int result;

	if (!s1 || !s2)
		return (0);
	result = (ft_strcmp(s1, s2) == 0 ? 1 : 0);
	return (result);
}
