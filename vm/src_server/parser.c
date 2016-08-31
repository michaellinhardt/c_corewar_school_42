/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:20:34 by pba               #+#    #+#             */
/*   Updated: 2016/08/28 17:59:54 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** We remove th '\n' at the end of the command line.
** We check if the path does exist, if yes we get the path.
** And finally, we execute the command.
*/

void			parser(t_env *serv_env, char *line)
{
	char		**cmd;

	(void)serv_env;
	line = ft_strtrim(line);
	if (line && line[0] != '\0')
	{
		cmd = ft_strsplit(line, ' ');
		if (ft_strequ(cmd[0], "champion"))
		{
			if (check_champion(cmd[0]) >= 0)
				ft_putendl_fd("CHAMPION OK", serv_env->cs);
			else
				ft_putendl_fd("CHAMPION NOT OK", serv_env->cs);
		}
	}
}
