/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:03:08 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/15 19:57:33 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_intswap(int *a, int *b)
{
	int tmp;

	if (a == NULL || b == NULL)
		return (0);
	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
}
