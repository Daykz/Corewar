/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps_upline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 21:02:09 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/11 22:28:05 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_termcaps.h>

void			ft_termcaps_upline(int nbline)
{
	ft_printf("\033[%dA", nbline);
}
