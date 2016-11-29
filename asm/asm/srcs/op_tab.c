/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:20:07 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/19 16:20:08 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		**create_opcode(char **str)
{
	str = (char **)malloc(sizeof(char *) * 17);
	str[0] = (char *)malloc(sizeof(char *) * 5);
	str[0] = "live";
	str[1] = (char *)malloc(sizeof(char *) * 3);
	str[1] = "ld";
	str[2] = (char *)malloc(sizeof(char *) * 3);
	str[2] = "st";
	str[3] = (char *)malloc(sizeof(char *) * 4);
	str[3] = "add";
	str[4] = (char *)malloc(sizeof(char *) * 4);
	str[4] = "sub";
	str[5] = (char *)malloc(sizeof(char *) * 4);
	str[5] = "and";
	str[6] = (char *)malloc(sizeof(char *) * 3);
	str[6] = "or";
	str[7] = (char *)malloc(sizeof(char *) * 4);
	str[7] = "xor";
	str[8] = (char *)malloc(sizeof(char *) * 5);
	str[8] = "zjmp";
	str[9] = (char *)malloc(sizeof(char *) * 4);
	str[9] = "ldi";
	str[10] = (char *)malloc(sizeof(char *) * 4);
	str[10] = "sti";
	str[11] = (char *)malloc(sizeof(char *) * 5);
	str[11] = "fork";
	str[12] = (char *)malloc(sizeof(char *) * 4);
	str[12] = "lld";
	str[13] = (char *)malloc(sizeof(char *) * 5);
	str[13] = "lldi";
	str[14] = (char *)malloc(sizeof(char *) * 6);
	str[14] = "lfork";
	str[15] = (char *)malloc(sizeof(char *) * 4);
	str[15] = "aff";
	return (str);
}

void		fill_op_bis(t_op_tab *data)
{
	if (!ft_strcmp(data->name, "fork"))
		fill_fork(data);
	else if (!ft_strcmp(data->name, "lld"))
		fill_lld(data);
	else if (!ft_strcmp(data->name, "lldi"))
		fill_lldi(data);
	else if (!ft_strcmp(data->name, "lfork"))
		fill_lfork(data);
	else if (!ft_strcmp(data->name, "aff"))
		fill_aff(data);
}

void		fill_op(t_op_tab *data)
{
	if (!ft_strcmp(data->name, "live"))
		fill_live(data);
	else if (!ft_strcmp(data->name, "ld"))
		fill_ld(data);
	else if (!ft_strcmp(data->name, "st"))
		fill_st(data);
	else if (!ft_strcmp(data->name, "add"))
		fill_add(data);
	else if (!ft_strcmp(data->name, "sub"))
		fill_sub(data);
	else if (!ft_strcmp(data->name, "and"))
		fill_and(data);
	else if (!ft_strcmp(data->name, "or"))
		fill_or(data);
	else if (!ft_strcmp(data->name, "xor"))
		fill_xor(data);
	else if (!ft_strcmp(data->name, "zjmp"))
		fill_zjmp(data);
	else if (!ft_strcmp(data->name, "ldi"))
		fill_ldi(data);
	else if (!ft_strcmp(data->name, "sti"))
		fill_sti(data);
	else
		fill_op_bis(data);
}

void		parse_name(t_op_tab *data)
{
	while (data)
	{
		fill_op(data);
		data = data->next;
	}
}

int			main(void)
{
	t_op_tab	*data;
	char	**str;
	int		i;

	i = 0;
	str = NULL;
	data = NULL;
	str = create_opcode(str);
	while (str[i])
	{
		list_add_next(&data, link_init((void *)str[i]));
		i++;
	}
	parse_name(data);
	print_op(data);
	return (0);
}