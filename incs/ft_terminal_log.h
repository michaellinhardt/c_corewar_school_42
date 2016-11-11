/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_log.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:16:21 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:16:21 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINAL_LOG_H
# define FT_TERMINAL_LOG_H

int			ascii(char *path);
int			ascii_init(void);
int			l1(char ico, char *name, char *info);
int			l2(char ico, char *name, char *info, int val1);
int			log_inst(int player, int id, char *inst);

#endif
