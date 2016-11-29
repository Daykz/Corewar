/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 17:59:54 by mleconte          #+#    #+#             */
/*   Updated: 2015/09/15 20:27:41 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# define BUF_SIZE 1024
# define RET 0
# define READED 1
# define EOL 2

int		get_next_line(int const fd, char **line);

#endif
