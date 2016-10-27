#include "ft_asm.h"

void	ft_init_compilation(t_compile *compile)
{
	compile->f_compile[NONE] = 0;
	compile->f_compile[COMMAND_NAME] = ft_compile_name;
	compile->f_compile[COMMAND_COMMENT] = ft_compile_comment;
	compile->f_compile[COMMENT] = 0;
	compile->f_compile[STRING] = ft_compile_string;
	compile->f_compile[WHITESPACE] = 0;
	compile->f_compile[SEPARATOR] = 0;
	compile->f_compile[LABEL] = ft_compile_label;
	compile->f_compile[REGISTER] = ft_compile_register;
	compile->f_compile[INDIRECT] = ft_compile_indirect;
	compile->f_compile[INSTRUCTION] = ft_compile_instruction;
	compile->f_compile[DIRECT_LABEL] = ft_compile_direct_label;
	compile->f_compile[INDIRECT_LABEL] = ft_compile_indirect_label;
	compile->f_compile[DIRECT] = ft_compile_direct;
	compile->f_compile[ENDLINE] = ft_compile_endline;

}
