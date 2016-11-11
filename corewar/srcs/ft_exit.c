/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:42 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:11:36 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	exitascii(t_data *d, int err, char *msg)
{
	if (!d->vm.console)
		return ;
	ft_putstr("🎼  ╔═════════════════════════════════════════════════════════");
	ft_putendl("═════════════════╗");
	ft_printf(" %C ║ %s%-72s%s ║\n", ((err == 1) ? L'🚨' : L'🌙')
		, ((err == 1) ? "\e[91m" : "\e[96m"), msg, "\e[93m");
	ft_putstr("🎼  ╚═════════════════════════════════════════════════════════");
	ft_putendl("═════════════════╝");
}

int		exit1(int err, t_data *d, char *msg)
{
	free_data(d);
	if (err != 0)
		ascii(ASC_EXIT_1);
	else
		ascii(ASC_EXIT_0);
	exitascii(d, err, msg);
	if (!d->vm.console && err)
		ft_printf("%s\n", msg);
	exit(err);
	return (1);
}

int		exit2(int err, t_data *d, char *del, char *msg)
{
	ft_strdel(&del);
	exit1(err, d, msg);
	return (1);
}

int		exit3(int err, t_data *d, int winner)
{
	char	*msg;

	if (d->vm.console)
	{
		ft_printf("%!Contestant %d, \"%s\", has won !", &msg, winner,
				data()->vm.p[winner - 1].header.prog_name);
		free_data(d);
		if (err != 0)
			ascii(ASC_EXIT_1);
		else
			ascii(ASC_EXIT_0);
		exitascii(d, err, msg);
		ft_strdel(&msg);
	}
	else
		ft_printf("Contestant %d, \"%s\", has won !\n", winner,
				data()->vm.p[winner - 1].header.prog_name);
	exit(err);
	return (1);
}

int		exit4(int err, t_data *d, int winner)
{
	char	*msg;

	if (d->vm.console)
	{
		ft_printf("%!Contestant %d, \"%s\", has won !", &msg, winner,
				data()->vm.p[winner - 1].header.prog_name);
		free_data(d);
		if (err != 0)
			ascii(ASC_EXIT_1);
		else
			ascii(ASC_EXIT_0);
		exitascii(d, err, msg);
		ft_strdel(&msg);
	}
	else
		ft_printf("Contestant %d, \"%s\", has won !\n", winner,
				data()->vm.p[winner - 1].header.prog_name);
	exit(err);
	return (1);
}
