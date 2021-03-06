/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:32:27 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/13 20:34:40 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	cw_live(t_cwdata *data, t_process *proc)
{
	int			num_champ;
	t_header	*champ;

	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_LIVE;
	if (proc->wait_cicle == 0)
	{
		num_champ = return_num_champ(proc, data);
		(data->verbose) ? ft_printf("%d\n", num_champ) : 0;
		proc->nb_live++;
		data->nb_live_per_cycle++;
		proc->last_clive = data->cur_cycle;
		champ = cw_id_champ_valid(data, num_champ);
		if (champ)
		{
			if (data->verbose)
				ft_printf("Player %d (%s) is said to be alive\n",
					ABS(champ->id), champ->prog_name);
			data->last_champ_live = champ->id;
			champ->last_clive = data->cur_cycle;
		}
	}
	else
		proc->move = 0;
}

void	cw_fork(t_cwdata *data, t_process *proc)
{
	t_process	*new;

	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_FORK;
	if (proc->wait_cicle == 0)
	{
		new = cw_add_process_to_lst(data, proc->id_champ, proc);
		new->loca = cw_get_new_loca(data, proc->loca, 0);
		(data->verbose) ? ft_printf(" (%d)\n", new->loca) : 0;
		new->pc = data->mem[new->loca];
	}
	else
		proc->move = 0;
}

void	cw_lfork(t_cwdata *data, t_process *proc)
{
	t_process	*new;

	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_LFORK;
	if (proc->wait_cicle == 0)
	{
		new = cw_add_process_to_lst(data, proc->id_champ, proc);
		new->loca = cw_get_new_loca(data, proc->loca, 1);
		new->pc = data->mem[new->loca];
	}
	else
		proc->move = 0;
}

void	cw_zjump(t_cwdata *data, t_process *proc)
{
	int nl;

	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_ZJUMP;
	if (proc->wait_cicle == 0)
	{
		nl = cw_get_new_loca(data, proc->loca, 0);
		if (proc->carry)
		{
			if (data->show_vm)
				show_hide_proc(data, proc, 0);
			proc->loca = nl;
			proc->pc = data->mem[proc->loca];
			proc->move = 0;
			if (data->verbose)
				ft_printf(" OK\n");
			if (data->show_vm)
				show_hide_proc(data, proc, 1);
		}
		else if (data->verbose)
			data->lastopfail = ft_printf(" FAILED\n");
	}
	else
		proc->move = 0;
}
