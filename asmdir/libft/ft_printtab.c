/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:55:25 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:09:06 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_printtab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr((char *)tab[i]);
		ft_putchar('\n');
		i++;
	}
}
