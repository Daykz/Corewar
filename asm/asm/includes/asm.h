/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 10:03:41 by dgalide           #+#    #+#             */
/*   Updated: 2016/09/02 13:20:32 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "../../libft/incs/libft.h"
#include "op.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void			list_add_next(t_op_tab **data, t_op_tab *link);
t_op_tab		*link_init(void *data);
void			print_op(t_op_tab *data);
void			fill_live(t_op_tab *data);
void			fill_ld(t_op_tab *data);
void			fill_st(t_op_tab *data);
void			fill_add(t_op_tab *data);
void			fill_sub(t_op_tab *data);
void			fill_and(t_op_tab *data);
void			fill_or(t_op_tab *data);
void			fill_xor(t_op_tab *data);
void			fill_zjmp(t_op_tab *data);
void			fill_ldi(t_op_tab *data);

typedef struct							s_parse_token
{
	char								*instruction;
	char								*opcode;
	char								*byte_encoding;
	char								**arg;
	int									bool_label;
	int									nb_to_label;
	int									size_instruction;
	struct s_parse_token				*next;
	struct s_parse_token				*prev;
}										t_parse_token;

typedef struct							s_corewar_data
{
	char								**s_file;
	char								*name;
	char								*comment_name;
	t_parse_token						*ptr_token;
}										t_corewar_data;

int			main(int argc, char **argv);
int			data_init(t_corewar_data **data);
int			lexical_analysis(int fd, t_corewar_data *data);
int			syntax_analysis(char *buffer, t_corewar_data *data);
void		hex_generator(t_corewar_data *data);
void		data_del(t_corewar_data *data);

#endif
