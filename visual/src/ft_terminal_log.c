#include "ft_corewar.h"

wchar_t log_ico(char ico)
{
	if (ico == 1)
		return (L'📗');
	else if (ico == 2)
		return (L'🕹');
	else if (ico == 3)
		return (L'🖥');
	else if (ico == 4)
		return (L'🎦');
	else if (ico == 5)
		return (L'🖱');
	else if (ico == 6)
		return (L'➿');
	else if (ico == 7)
		return (L'❎');
	else if (ico == 8)
		return (L'❎');
	else if (ico == 9)
		return (L'🆕');
	else
		return (L'🎬');
}

int		l(char ico, char *name, char *info)
{
	t_data		*d;

	/* AFFICHE LE LOG qUE SI NECESSAIRE SELON LA CONFIG DU HEADER */
	if (!LOG_DISPLAY
	|| (!LOG_ALL && ((ico == 1 && !LOG_GENERAL) || (ico == 2 && !LOG_KEY)
	|| (ico == 3 && !LOG_ITOW) || (ico == 4 && !LOG_SCENE)
	|| (ico == 5 && !LOG_MOUSE) || (ico == 6 && !LOG_LOOP)
	|| (ico == 7 && !LOG_FREE) || (ico == 8 && !LOG_XTOI)
	|| (ico == 9 && !LOG_NEWI) || (ico == 10 && !LOG_MLX))))
		return (1);
	d = data();
	ft_printf(" %C %s %20s  %s  %-47s %s\n", log_ico(ico), LINE_BLUE, name
	, LINE_GREEN2, info, LINE_YEL);
	return (1);
}
