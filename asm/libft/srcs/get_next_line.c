/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 04:13:17 by mleconte          #+#    #+#             */
/*   Updated: 2015/04/18 18:01:58 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <stdlib.h>
#include <unistd.h>

static void	stock_line(char *buf, char *line, int *i, int *var)
{
	static int		j = 0;

	while (buf[*i])
	{
		if (buf[*i] == '\n')
		{
			var[EOL] = 1;
			(*i)++;
			line[j] = '\0';
			j = 0;
			return ;
		}
		else
		{
			line[j] = buf[*i];
			(*i)++;
			j++;
		}
	}
	line[j] = '\0';
	*i = 0;
	var[READED] = 1;
}

int			get_next_line(int const fd, char **line)
{
	static char		buf[BUF_SIZE];
	static int		i = 0;
	int				var[3];

	var[EOL] = 0;
	*line = malloc(sizeof(char) * BUF_SIZE + 4096);
	if (!(*line))
		return (-1);
	while (var[EOL] == 0)
	{
		if (i == 0)
		{
			var[RET] = read(fd, buf, BUF_SIZE - 1);
			if (var[RET] < 0)
				return (-1);
			else if (var[RET] == 0)
				return ((var[READED] == 1) ? 1 : 0);
			buf[var[RET]] = '\0';
		}
		stock_line(buf, *line, &i, var);
	}
	return (1);
}
