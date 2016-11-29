/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 10:50:39 by dgalide           #+#    #+#             */
/*   Updated: 2016/09/18 10:50:40 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"
#include <stdio.h>

int				data_init(t_corewar_data **data)
{
	if (!((*data) = (t_corewar_data *)malloc(sizeof(t_corewar_data))))
		return (0);
	(*data)->s_file = NULL;
	(*data)->ptr_token = NULL;
	(*data)->name = NULL;
	(*data)->comment_name = NULL;
	return (1);
}