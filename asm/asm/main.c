/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 10:33:44 by dgalide           #+#    #+#             */
/*   Updated: 2016/09/18 10:33:46 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"
#include <stdio.h>

/*static void	print(t_corewar_data *data)
{
	t_parse_token *tmp;

	tmp = NULL;
	if (data->ptr_token)
	{
		tmp = data->ptr_token;
		while (tmp)
		{
			ft_putendl(tmp->instruction);
			ft_putendl("-------------------------------------------");
			tmp = tmp->next;
		}
	}
}*/

static int	put_error(char *error)
{
	if (error)
		ft_putendl(error);
	return (0);
}

int			main(int argc, char **argv)
{
	t_corewar_data *data;
	int fd;

	data = NULL;
	fd = 0;
	if (argc != 2)
		return (put_error("Error File"));
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (!data_init(&data))
			return(put_error("Error init"));
		if (!lexical_analysis(fd, data))
			return(put_error("Error Parse"));
		//print(data);
		//printf("name == %s\ncomment_name == %s\n", data->name, data->comment_name);
		hex_generator(data);
		close(fd);
		data_del(data);
	}
	return (0);
}