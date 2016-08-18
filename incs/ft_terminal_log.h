#ifndef FT_TERMINAL_H
# define FT_TERMINAL_H
/*
 *	Header lié à la gestion du terminal & log
 */

/* ft_terminal_ascii.c */
int			ascii(char *path);
int			ascii_init(void);

/* FICHIER FT_TERMINAL_LOG.C */
int			l(char ico, char *name, char *info);

#endif
