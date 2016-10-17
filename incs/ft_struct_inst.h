#ifndef FT_STRUCT_INST_H
# define FT_STRUCT_INST_H

typedef char		t_arg_type;
typedef struct s_dvm	t_dvm;
typedef struct s_proc	t_proc;

typedef	struct		s_instructions
{
	int				id;
	char			name[6];
	short			nbr_args;
	t_arg_type		types[MAX_ARGS_NUMBER];
	int				cycles;
	char			comment[37];
	int				flag_ocp;
	int				flag_size_ind;
	void			(*f_instructions)(t_dvm *vm,
			struct s_instructions ins, t_proc *proc);
}					t_instructions;

#endif
