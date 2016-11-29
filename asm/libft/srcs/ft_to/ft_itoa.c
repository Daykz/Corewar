/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:08:27 by mleconte          #+#    #+#             */
/*   Updated: 2015/02/02 00:07:56 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>

static int	int_len(int n)
{
	unsigned int result;

	result = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static void	ft_num_to_char(char *str, int n, size_t len, size_t neg)
{
	while (len != 0)
	{
		str[len - 1 + neg] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	neg;
	size_t	len;

	len = int_len(n);
	neg = (n < 0) ? 1 : 0;
	str = ft_strnew(len + neg + 1);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (neg == 1)
	{
		n = -n;
		str[0] = '-';
	}
	str[len + neg] = '\0';
	ft_num_to_char(str, n, len, neg);
	return (str);
}
