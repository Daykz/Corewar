/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:37:59 by mleconte          #+#    #+#             */
/*   Updated: 2014/11/08 17:03:01 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	if (!s)
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		*s = '\0';
		s++;
		i++;
	}
}
