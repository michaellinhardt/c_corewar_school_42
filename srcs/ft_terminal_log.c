#include "ft_corewar.h"

wchar_t log_ico(char ico)
{
	wchar_t		c;

	c = (wchar_t)NULL;
	(ico < 0) ? (c = L'🆘') : 0;
	(ico == 1) ? (c = L'📗') : 0;
	(ico == 2) ? (c = L'🕹') : 1;
	(ico == 3) ? (c = L'🖥') : 1;
	(ico == 4) ? (c = L'🎦') : 1;
	(ico == 5) ? (c = L'🖱') : 1;
	(ico == 6) ? (c = L'➿') : 1;
	(ico == 7) ? (c = L'❎') : 1;
	(ico == 8) ? (c = L'❎') : 1;
	(ico == 9) ? (c = L'🆕') : 1;
	(ico == 10) ? (c = L'🎬') : 1;
	(ico == 11) ? (c = L'🖥') : 1;
	(ico == 12) ? (c = L'❤') : 1;
	(ico == 13) ? (c = L'❤') : 1;
	!(c) ? (c = L'➿') : 1;
	return (c);
}

int		log_bool(char ico)
{
	if (LOG_DEBUG && ((ico == -1
	|| (LOG_DEBUG_DETAILED && ico == -2))
	|| (LOG_DEBUG_CHECKLIVE && ico == -3)))
		return (1);
	if ((!LOG_DEBUG && ico < 0)
	|| (!LOG_DEBUG_DETAILED && ico == -2)
	|| (!LOG_DEBUG_CHECKLIVE && ico == -3))
		return (0);
	if (!LOG_DISPLAY
	|| (!LOG_ALL
	&& ((ico == 1 && !LOG_GENERAL) || (ico == 2 && !LOG_KEY)
	|| (ico == 3 && !LOG_ITOW) || (ico == 4 && !LOG_SCENE)
	|| (ico == 5 && !LOG_MOUSE) || (ico == 6 && !LOG_LOOP)
	|| (ico == 7 && !LOG_FREE) || (ico == 8 && !LOG_XTOI)
	|| (ico == 9 && !LOG_NEWI) || (ico == 10 && !LOG_MLX)
	|| (ico == 11 && !LOG_VM) || (ico == 12 && !LOG_PROC)
	|| (ico == 13 && !LOG_INST)
	)))
		return (0);
	return (1);
}

int		l1(char ico, char *name, char *info)
{
	t_data		*d;

	/* AFFICHE LE LOG qUE SI NECESSAIRE SELON LA CONFIG DU HEADER */
	if (!data()->vm.console || !log_bool(ico))
		return (1);
	d = data();
	if (ico != -2 && ico != -3)
		ft_printf(" %C %s %21s %s %46s %s\n", log_ico(ico), LINE_BLUE, name
		, LINE_GREEN2, info, LINE_YEL);
	else
		ft_printf(" %C %s %21s %s \e[90m%46s %s\n", log_ico(ico), LINE_BLUE, name
		, LINE_GREEN2, info, LINE_YEL);
	return (1);
}

int		l2(char ico, char *name, char *info, int val1)
{
	t_data		*d;

	/* AFFICHE LE LOG qUE SI NECESSAIRE SELON LA CONFIG DU HEADER */
	if (!data()->vm.console || !log_bool(ico))
		return (1);
	d = data();
	if (ico != -2 && ico != -3)
		ft_printf(" %C %s %21s %s %9d \e[90m-> \e[35m%-35s\e[93m %s\n", log_ico(ico), LINE_BLUE, name
		, LINE_GREEN2, val1, info, LINE_YEL);
	else
		ft_printf(" %C %s %21s %s \e[90m%9d -> %-35s\e[93m %s\n", log_ico(ico), LINE_BLUE, name
		, LINE_GREEN2, val1, info, LINE_YEL);
	return (1);
}
