#include "ft_corewar.h"

int		main(int argc, char **argv)
{
	t_data	*d;

	d = data();
	*argv += 0 * argc; // brain compilateur flag
	/* lance les 4 premiers affichage dans le terminal, puis démarre mlx */
	d->mlx.scene = SCENE_START;
	d->vm.graphic = GRAPHIC_MODE;
	d->vm.console = CONSOLE_LOG;

	// parse options + champs;
	ft_recup_files(&d->vm, &d->args, argv, argc);
	ft_recup_headers(&d->vm, &d->args);
	ft_recup_code(&d->vm, &d->args);

	ft_init_instructions(d->vm.instructions);

	int i;
	int j;

	i = 1;

	while (i < 17)
	{

		ft_printf("OP_CODE %d\n", i );
		ft_printf("name : %s\n", d->vm.instructions[i].name);
		ft_printf("nbr_args : %d\n", d->vm.instructions[i].nbr_args);
		j = 0;
		ft_printf("args : ");
		while (j < d->vm.instructions[i].nbr_args)
			ft_printf("%d , ", d->vm.instructions[i].types[j++]);
		ft_printf("cycles : %d\n", d->vm.instructions[i].cycles);
		ft_printf("comment : %s\n", d->vm.instructions[i].comment);
		ft_printf("flag ocp : %d\n", d->vm.instructions[i].flag_ocp);
		ft_printf("flag a definir : %d\n", d->vm.instructions[i].flag_size_ind);
		d->vm.instructions[i].f_instructions(&d->vm, d->vm.instructions[i], 0);
		ft_printf("\n----------------------------------\n");
		++i;
	}

	t_argument argument[MAX_ARGS_NUMBER];
	char	oc_p;

	oc_p =	84;
	i = 0;
	ft_decode_args(104, argument);
	while (i < MAX_ARGS_NUMBER)
	{
		if (argument[i].type == REG_CODE)
			ft_putendl("REG_CODE");
		else if (argument[i].type == DIR_CODE)
			ft_putendl("DIR CODE");
		else if (argument[i].type == IND_CODE)
			ft_putendl("IND CODE");
		else 
		{
			ft_putnbr(argument[i].type);
			ft_putendl("NULL");
		}
		++i;
	}

	int pc = 0;
	
	vm_init(d, &d->vm);
	ft_display_vm(&d->vm);


	ft_decode_args(104, argument);
	int ret = ft_fill_args(argument, &d->vm, 4, 1);

	ft_putchar(*(d->vm.arene + 5));
	ft_putchar('\n');

	i = 0;
	while (i < 4)
	{
		ft_printf("valeur arg : %d\n", argument[i].value);
		++i;
	}
	ft_printf("ret :%d\n", ret);
//
//unsigned int u = ft_getchar(d->vm.arene + 28);
//	ft_putnbr(u);

	char arene[4097] = {0};

	(void)arene;
	(void)pc;

	/*
	while (pc < 4096)
	{
		arene[pc] = ft_getchar((d->vm.arene + pc * 2));
		int t = (unsigned char)arene[pc];
		ft_printf("%X", t);
		ft_putchar(' ');
		pc++;
		if (!(pc % 64))
			ft_putchar('\n');
	}
	*/

	/*
	if (ascii(ASC_LOGO) && ascii(ASC_INIT) && ascii_init()
		&& ascii(ASC_LOG)
	&& d->vm.graphic)
		mlx_start(d, &d->mlx);
	else
		while (42)
			loop_vm(d);
			*/
	return (0);
}
