/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:42:54 by mleconte          #+#    #+#             */
/*   Updated: 2016/05/30 13:07:51 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_smalloc(size_t n)
{
	void *ptr;

	if ((ptr = malloc(n)) == NULL)
		exit(EXIT_FAILURE);
	return (ptr);
}
