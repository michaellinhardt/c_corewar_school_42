/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:46 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:46 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_asm.h"

static void	ft_init_parser_accept(t_parser *parser)
{
	parser->f_accept[0] = ft_accept_argument;
	parser->f_accept[1] = ft_accept_separator_char;
	parser->f_accept[2] = ft_accept_instruction;
	parser->f_accept[3] = ft_accept_instruction_plus;
	parser->f_accept[4] = ft_accept_label_inst;
	parser->f_accept[5] = ft_accept_position_inst;
	parser->f_accept[6] = ft_accept_fin;
	parser->f_accept[7] = ft_accept_code_fin;
	parser->f_accept[8] = ft_accept_comment;
	parser->f_accept[9] = ft_accept_name;
	parser->f_accept[10] = ft_accept_header;
}

static void	ft_init_parser_shift(t_parser *parser)
{
	parser->f_shift[0] = ft_shift_no_focus;
	parser->f_shift[1] = ft_shift_whitespaces;
	parser->f_shift[2] = ft_shift_command_name;
	parser->f_shift[3] = ft_shift_string;
	parser->f_shift[4] = ft_shift_endline;
	parser->f_shift[5] = ft_shift_command_comment;
	parser->f_shift[6] = ft_shift_label;
	parser->f_shift[7] = ft_shift_instruction;
	parser->f_shift[8] = ft_shift_register;
	parser->f_shift[9] = ft_shift_separator_char;
	parser->f_shift[10] = ft_shift_direct_label;
	parser->f_shift[11] = ft_shift_direct;
	parser->f_shift[12] = ft_shift_indirect;
	parser->f_shift[13] = ft_shift_indirect_label;
	parser->f_shift[14] = ft_shift_comment;
	parser->f_shift[15] = ft_shift_end;
}

void		ft_init_parser(t_parser *parser)
{
	ft_bzero((void *)parser, sizeof(t_parser));
	ft_init_instructions(parser->inst);
	parser->f_reduce[0] = ft_rule_name;
	parser->f_reduce[1] = ft_rule_ccomment;
	parser->f_reduce[2] = ft_rule_endline;
	parser->f_reduce[3] = ft_rule_instruction;
	parser->f_reduce[4] = ft_rule_separator_char;
	parser->f_reduce[5] = ft_rule_argument;
	parser->f_reduce[6] = ft_rule_label;
	parser->f_reduce[7] = ft_rule_end;
	ft_init_parser_accept(parser);
	ft_init_parser_shift(parser);
}
