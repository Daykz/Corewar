/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 18:47:41 by mleconte          #+#    #+#             */
/*   Updated: 2016/05/25 17:37:18 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>

size_t	ft_count_word(char const *str)
{
	size_t	count;
	char	*clean;

	count = 0;
	if (str && *str)
	{
		clean = ft_strclean(str);
		if (clean)
		{
			count = ft_count_char(clean, ' ') + 1;
			ft_strdel(&clean);
		}
	}
	return (count);
}
