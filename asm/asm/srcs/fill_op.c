/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:12:51 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/19 19:12:52 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		fill_live(t_op_tab *data)
{
	data->nbr_args = 1;
	data->args[0] = T_DIR;
	data->opcode = 1;
	data->nbr_cycles = 10;
	data->if_codage = 0;
	data->if_carry = 0;
	data->label_size = 4;
}

void		fill_ld(t_op_tab *data)
{
	data->nbr_args = 2;
	data->args[0] = T_DIR | T_IND;
	data->args[1] = T_REG;
	data->opcode = 2;
	data->nbr_cycles = 5;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 4;
}

void		fill_st(t_op_tab *data)
{
	data->nbr_args = 2;
	data->args[0] = T_DIR | T_IND;
	data->args[1] = T_REG;
	data->opcode = 3;
	data->nbr_cycles = 5;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 0;
}

void		fill_add(t_op_tab *data)
{
	data->nbr_args = 3;
	data->args[0] = T_REG;
	data->args[1] = T_REG;
	data->args[2] = T_REG;
	data->opcode = 4;
	data->nbr_cycles = 10;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 0;
}

void		fill_sub(t_op_tab *data)
{
	data->nbr_args = 3;
	data->args[0] = T_REG;
	data->args[1] = T_REG;
	data->args[2] = T_REG;
	data->opcode = 5;
	data->nbr_cycles = 10;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 0;
}