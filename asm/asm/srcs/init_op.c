/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 14:34:26 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/19 14:34:28 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

void			list_add_next(t_op_tab **data, t_op_tab *link)
{
	t_op_tab *tmp;

	tmp = *data;
	if (link)
	{
		if (!tmp)
			(*data) = link;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = link;
			link->prev = tmp;
			link->next = NULL;
		}
	}
}

t_op_tab		*link_init(void *data)
{
	t_op_tab *new_link;

	new_link = (t_op_tab *)malloc(sizeof(t_op_tab));
	if (new_link == NULL)
		return (NULL);
	new_link->name = (char *)ft_strdup(data);
	new_link->next = NULL;
	new_link->prev = NULL;
	new_link->nbr_args = 0;
	new_link->args = NULL;
	new_link->opcode = 0;
	new_link->nbr_cycles = 0;
	new_link->if_codage = 0;
	new_link->if_carry = 0;
	new_link->label_size = 0;
	return (new_link);
}

void		print_op(t_op_tab *data)
{
	if (data)
	{
		while (data)
		{
			printf("name= %s, nbr_args= %d, opcode= %d, nbr_cycles= %d, encod= %d, carry= %d, label_size= %d, hex= %d\n", data->name, data->nbr_args, data->opcode, data->nbr_cycles, data->if_codage, data->if_carry, data->label_size, data->val_hex);
			data = data->next;
		}
	}
}