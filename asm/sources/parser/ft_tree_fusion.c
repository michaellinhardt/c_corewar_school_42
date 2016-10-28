#include <stdlib.h>
#include "libft.h"
#include "ft_asm.h"

/*
** ajoute les t2 au t1
*/

t_parse_tree	*ft_fusion_fils(t_parse_tree *t1, t_parse_tree *t2)
{
	unsigned int i;
	t_parse_tree **fils;

	fils = t2->fils;

	t1->fils = (t_parse_tree **)realloc(t1->fils, sizeof(t_parse_tree *) *
			(t1->nbr_fils +	t2->nbr_fils));

	i = t1->nbr_fils;
	t1->nbr_fils += t2->nbr_fils;
	while (i < t1->nbr_fils)
	{
		t1->fils[i] = *(t2->fils);
		t2->fils++;
		++i;
	}
	t2->fils = fils;
	return (t1);
}
