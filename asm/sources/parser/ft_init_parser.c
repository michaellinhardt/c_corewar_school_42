#include "libft.h"
#include "ft_asm.h"

void	ft_init_parser(t_parser *parser)
{
	ft_bzero((void *)parser, sizeof(t_parser));
	ft_bzero((void *)&(parser->memory), sizeof(t_memory));
	ft_putendl("lalallalalalallalallalalalalalallalalalalalalala");
	ft_init_instructions(parser->inst);
	parser->f_reduce[0] = ft_rule_name;
	parser->f_reduce[1] = ft_rule_ccomment;
	parser->f_reduce[2] = ft_rule_endline;
	parser->f_reduce[3] = ft_rule_instruction;

}
