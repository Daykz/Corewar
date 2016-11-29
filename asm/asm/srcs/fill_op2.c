/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:41:14 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/19 19:41:15 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		fill_and(t_op_tab *data)
{
	data->nbr_args = 3;
	data->args[0] = T_REG | T_DIR | T_IND;
	data->args[1] = T_REG | T_IND | T_DIR;
	data->args[2] = T_REG;
	data->opcode = 6;
	data->nbr_cycles = 6;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 4;
}

void		fill_or(t_op_tab *data)
{
	data->nbr_args = 3;
	data->args[0] = T_REG | T_IND | T_DIR;
	data->args[1] = T_REG | T_IND | T_DIR;
	data->args[2] = T_REG;
	data->opcode = 7;
	data->nbr_cycles = 6;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 4;
}

void		fill_xor(t_op_tab *data)
{
	data->nbr_args = 3;
	data->args[0] = T_REG | T_IND | T_DIR;
	data->args[1] = T_REG | T_IND | T_DIR;
	data->args[2] = T_REG;
	data->opcode = 8;
	data->nbr_cycles = 6;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 4;
}

void		fill_zjmp(t_op_tab *data)
{
	data->nbr_args = 1;
	data->args[0] = T_DIR;
	data->opcode = 9;
	data->nbr_cycles = 20;
	data->if_codage = 0;
	data->if_carry = 1;
	data->label_size = 2;
}

void		fill_ldi(t_op_tab *data)
{
	data->nbr_args = 3;
	data->args[0] = T_REG | T_DIR | T_IND;
	data->args[1] = T_DIR | T_REG;
	data->args[2] = T_REG;
	data->opcode = 10;
	data->nbr_cycles = 25;
	data->if_codage = 1;
	data->if_carry = 1;
	data->label_size = 2;
}