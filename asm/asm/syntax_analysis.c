/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sybtax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 12:30:34 by dgalide           #+#    #+#             */
/*   Updated: 2016/09/18 12:30:35 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static int	fill_header(char *buffer, t_corewar_data *data)
{
	if (ft_strequ(ft_strsub(buffer, 0, 5), NAME_CMD_STRING))
	{
		data->name = ft_strsub(buffer, 7, ft_strlen(buffer) - 8);
		return ((ft_strlen(data->name) > PROG_NAME_LENGTH) ? 0 : 1);
	}
	else
	{
		data->comment_name = ft_strsub(buffer, 10, ft_strlen(buffer) - 11);
		return ((ft_strlen(data->comment_name) > COMMENT_LENGTH) ? 0 : 1);
	}
}

int			syntax_analysis(char *buffer, t_corewar_data *data)
{
	if (ft_strequ(ft_strsub(buffer, 0, 5), NAME_CMD_STRING) || 
		ft_strequ(ft_strsub(buffer, 0, 8), COMMENT_CMD_STRING))
		fill_header(buffer, data);
	return (1);
}