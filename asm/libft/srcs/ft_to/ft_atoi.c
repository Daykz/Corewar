/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:26:56 by mleconte          #+#    #+#             */
/*   Updated: 2015/04/18 18:28:32 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int	sign;
	int	nb;
	int	i;

	sign = 1;
	nb = 0;
	i = 0;
	if (str)
	{
		while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
				|| str[i] == '\t' || str[i] == '\r' || str[i] == '\f'))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			sign = (str[i] == '-') ? -sign : sign;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10;
			nb = nb + (str[i] - '0');
			i++;
		}
	}
	return (nb * sign);
}
