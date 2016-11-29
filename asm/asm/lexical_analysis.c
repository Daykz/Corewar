/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 10:33:55 by dgalide           #+#    #+#             */
/*   Updated: 2016/09/18 10:33:56 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


 #include "includes/asm.h"
#include <stdio.h>

static void			token_to_list(t_parse_token *token, t_corewar_data *data)
{
	t_parse_token *tmp;

	tmp = NULL;
	if (data->ptr_token)
	{
		tmp = data->ptr_token;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = token;
		token->prev = tmp;
	}
	else
		data->ptr_token = token;
}

static int			new_token(char *buff, t_corewar_data *data)
{
	t_parse_token *new_token;

	new_token = NULL;
	if (buff)
	{
		new_token = (t_parse_token *)malloc(sizeof(t_parse_token));
		new_token->instruction = ft_strdup(buff);
		new_token->opcode = NULL;
		new_token->byte_encoding = NULL;
		new_token->arg = NULL;
		new_token->bool_label = 0;
		new_token->nb_to_label = 0;
		new_token->prev = NULL;
		new_token->next = NULL;
		new_token->size_instruction = 0;
		token_to_list(new_token, data);
		return (1);
	}
	else
		return (0);
}

//decoupage en token (1 instruction == 1 token)

int			lexical_analysis(int fd, t_corewar_data *data)
{
	char *buffer;
	int ret;

	buffer = NULL;
	ret = 0;
	while ((ret = get_next_line(fd, &buffer)))
		if (!new_token(buffer, data) || !syntax_analysis(buffer, data))
			return (0);
	return ((ret != 0) ? 0 : 1);
}