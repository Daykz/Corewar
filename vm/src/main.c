/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:15:30 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/21 18:06:04 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	cw_endloop(t_cwdata *data)
{
	t_list		*tmp;

	tmp = data->processlist;
	while (tmp)
	{
		if (data->show_vm)
			show_hide_proc(data, (t_process*)tmp->content, 0);
		cw_del_process_to_lst(data, NULL, tmp);
		tmp = tmp->next;
	}
	if (data->show_vm)
		ft_termcaps_poscurs(MEM_SIZE / NB_OCT_LINE + 5, 0);
}

static void	cw_get_winner(t_cwdata *data)
{
	t_header	*champ;

	champ = cw_id_champ_valid(data, data->last_champ_live);
	if (!champ)
		champ = ((t_header*)data->beginlist->content);
	ft_printf("Contestant %d, \"%s\", has won !\n",
		ABS(champ->id), champ->prog_name);
}

int			main(int argc, t_tab argv)
{
	t_cwdata	data;

	if (argc > 1)
	{
		data.v = argv;
		data.c = argc - 1;
		if (cw_init(&data))
			return (1);
		fill_map(&data);
		cw_loop(&data);
		cw_endloop(&data);
		(data.dumpcycles == -1) ? cw_get_winner(&data) : 0;
		cw_freeall(&data);
	}
	else
		ft_printf("{lgreen}use: ./corewar [[-n number] champion1.cor] ...\
\nOptions:\n\
	[-v]              : Verbose\n	[-vm]             : Affichage de la loop\n\
	|    [-h]         : Cache les octets de -vm\n\
	|    [-b]         : Cache les processus pour augmenter le vitesse\n\
	[-dump nbr_cycles]: Affiche la memoire au cycle nbr_cycles [format 32bit]\n\
	[-d nbr_cycles]   : Affiche la memoire au cycle nbr_cycles [format 64bit]\n\
	[-r nbr_cycles]   : Relenti a nbr_cycles\n\
	|    [-w nbr_sec] : nbr_sec entre les cycles {eoc}\n");
	return (0);
}
