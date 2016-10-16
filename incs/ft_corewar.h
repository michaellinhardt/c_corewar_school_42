#ifndef FT_COREWAR_H
# define FT_COREWAR_H
/*
 *	Header lié à corewar
 */

/* LIB STANDAR */
# include <fcntl.h>
# include <dirent.h>
# include <limits.h>
# include "libft.h"
# include "mlx.h"
/* LIB COREWAR/MLX */
# include "op.h"
# include "ft_conf.h"
# include "ft_conf_obj.h"
# include "ft_terminal_log.h"
# include "ft_struct_mlx.h"
# include "ft_struct_vm.h"
# include "ft_struct_args.h"
# include "ft_struct_data.h"
# include "ft_mlx.h"
#define ABS(x) x < 0 ? -x : x

/* FICHIER FT_EXIT.C */
int		exit1(int err, t_data *d, char *msg);
int		exit2(int err, t_data *d, char *del, char *msg);
void	exitascii(t_data *d, int err, char *msg);

/* FICHIER FT_FREE.C */
void	free_data(t_data *d);

/* FICHIER FT_COREWAR.C */
t_data	*data(void);

/* FICHIER FT_VM_INIT.C */
void	vm_init(t_data *d, t_dvm *v);

/* FICHIER FT_VM.C */
void	vm(t_dvm *v, int cperloop);

/* FICHIER FT_VM_PROCESSUS.C */
void	proc_new(t_data *d, t_proc *new, int player, int i);
int		proc_kill(t_data *d, t_proc *target, t_proc *procdie);

/* FICHIER FT_GAMELOOP.C */
int		gameloop(t_dvm *v);

/* FICHIER FT_VM_PROCESSUS_READ.C */
void	processus_read(t_dvm *v, t_proc *proc);

/* Tools */
// caca
// ca c'est kdo bsx :)
int		ft_little_to_big(int little);
char	*ft_read_code_champ(int size);
void	ft_recup_files(t_dvm *vm, t_dargs *args);
void	ft_recup_headers(t_dvm *vm, t_dargs *args);
void	ft_recup_code(t_dvm *vm, t_dargs *args);
void	ft_fill_arene(t_dvm *vm);
void	ft_init_vm(t_dvm *vm);
void	ft_display_vm(t_dvm *vm);
void	ft_init_instructions(t_instructions *inst);
int		ft_get_instruction(t_instructions *inst,const t_dvm *vm, t_proc *proc);
int		ft_check_value_args(const t_argument *args, const t_instructions *inst,
		t_dvm *vm, t_proc *proc);
int		ft_recup_options(t_dvm *vm, t_dargs *args, char **argv, int argc);
int		ft_check_value_number(t_dargs *args, t_dvm *vm);
int		ft_convert_pc(int pc);
void	ft_get_oc_p(const t_dvm *vm, t_proc *proc);

int		ft_get_indirect(int pc, t_dvm *vm);



void	vm_dump(t_dvm *vm);
// ici on vas peupler le types des arguemnts
void	ft_decode_args(char oc_p, t_argument *arg);
void	ft_no_ocp(t_argument *args, t_arg_type *types);
// ici on peuple les valeurs
int		ft_fill_args(t_argument *arg, const t_dvm *vm, int pc, const t_proc *proc);

char	ft_getchar(const char	*arene);
int		ft_get_value_registre(t_proc *proc, int registre);
int		ft_check_reg(int registre);
int		ft_get_args(t_proc *proc);
int		ft_fill_args_dir(t_argument *arg, const t_dvm *vm, int pc);
void	ft_put_registre(char *arene, unsigned int code, int pc);
void	ft_put_color_size(int *color, unsigned int code_color, int pc, int size);
/*
 * Instructions
 */

void		ft_instructions_live(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_ld(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_st(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_add(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_sub(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_and(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_or(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_xor(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_zjmp(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_ldi(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_sti(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_fork(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_lld(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_lldi(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_lfork(t_dvm *vm, t_instructions inst, t_proc *proc);
void		ft_instructions_aff(t_dvm *vm, t_instructions inst, t_proc *proc);
#endif
