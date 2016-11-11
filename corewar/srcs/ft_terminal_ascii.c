/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_ascii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:54 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:54 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	ascii_init2(void)
{
	if (!data()->vm.console)
		return ;
	ft_putstr("🎼  ╠═══════════════════════╬═══════════════════════════════");
	ft_putendl("═══════════════════╣");
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG NEW IMG"
	, LINE_GREEN2, ((LOG_NEWI) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG IMG TO WIN"
	, LINE_GREEN2, ((LOG_ITOW) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG XPM TO IMG"
	, LINE_GREEN2, ((LOG_XTOI) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG MOUSE INPUT"
	, LINE_GREEN2, ((LOG_MOUSE) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG KEY INPUT"
	, LINE_GREEN2, ((LOG_KEY) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG LOOP"
	, LINE_GREEN2, ((LOG_LOOP) ? "true" : "false"), LINE_YEL);
}

int		ascii_init(void)
{
	if (!data()->vm.console)
		return (1);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "WIN_TITLE"
	, LINE_GREEN2, WIN_TITLE, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "GIF_DIR", LINE_GREEN2
	, GIF_DIR, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47d %s\n", LINE_MAG, "WIN_X", LINE_GREEN2
	, WIN_X, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47d %s\n", LINE_MAG, "WIN_Y", LINE_GREEN2
	, WIN_Y, LINE_YEL);
	ft_putstr("🎼  ╠═══════════════════════╬═══════════════════════════════");
	ft_putendl("═══════════════════╣");
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_MAG, "USLEEP_BOOL"
	, LINE_GREEN2, USLEEP_BOOL, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_MAG, "USLEEP_TIME"
	, LINE_GREEN2, USLEEP_TIME, LINE_YEL);
	ascii_init2();
	return (1);
}

int		ascii(char *path)
{
	int		fd;
	char	*line;

	if (!data()->vm.console)
		return (1);
	line = NULL;
	fd = open(path, O_RDONLY);
	ft_putstr(TERMINAL_COLOR);
	while (ft_strdel(&line) && (get_next_line(fd, &line)) > 0)
		ft_printf("%s\n", line);
	close(fd);
	return (1);
}
