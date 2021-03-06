/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 20:17:53 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/01 20:38:02 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void			cw_aff(t_cwdata *data, t_process *proc)
{
	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_AFF;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		if (data->verbose)
			ft_printf("P %4d | aff\n", proc->name);
		proc->wait_cicle = 0;
	}
	else if (proc->wait_cicle == 0 && proc->bad_encodage)
	{
		proc->wait_cicle = 0;
		proc->bad_encodage = 0;
	}
	else
		proc->move = 0;
}

void			cw_lldinorme(t_cwdata *data, t_process *proc, t_inst *inst)
{
	t_param		param;

	init_param(&param);
	param.param1 = bin_offset(proc, data, 0, inst);
	print_verbose(data, param.param1, 0, *inst);
	if (inst->param == REG_CODE)
		param.param1 = proc->reg[param.param1 - 1];
	param.param2 = bin_offset(proc, data, 2, inst);
	print_verbose(data, param.param2, 0, *inst);
	if (inst->param == REG_CODE)
		param.param2 = proc->reg[param.param2 - 1];
	param.param3 = bin_offset(proc, data, 4, inst);
	print_verbose(data, param.param3, 1, *inst);
	if (data->verbose)
		ft_printf("       | -> load from %d + %d = %d (with pc", param.param1,
			param.param2, param.param1 + param.param2);
	proc->reg[param.param3 - 1] = return_size_reg(data, proc, param.param1 +
		param.param2, 1);
	check_reg_carry(proc, proc->reg[param.param3 - 1]);
}

void			cw_lldi(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_LLDI;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc_ind(proc, &inst);
		if (!if_registre(data, proc, &inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | lldi", proc->name);
		cw_lldinorme(data, proc, &inst);
	}
	else
		bad_encodage(proc);
}

void			cw_lld(t_cwdata *data, t_process *proc)
{
	t_inst		inst;
	int			param;
	int			reg;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_LLD;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc_ind(proc, &inst);
		if (!if_registre(data, proc, &inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | lld\n", proc->name);
		param = bin_offset(proc, data, 0, &inst);
		reg = bin_offset(proc, data, 2, &inst);
		if (data->verbose)
			ft_printf("reg = %d %.2X, param = %d \n", reg, reg, param);
		proc->reg[reg - 1] = param;
		check_reg_carry(proc, proc->reg[reg - 1]);
	}
	else
		bad_encodage(proc);
}
