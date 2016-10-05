#include "ft_corewar.h"

int		main(int argc, char **argv)
{
	exit(1);
	t_data	*d;

	d = data();
	*argv += 0 * argc; // brain compilateur flag
	/* lance les 4 premiers affichage dans le terminal, puis démarre mlx */
	d->mlx.scene = SCENE_START;
	d->vm.dump = -1;
	d->vm.console = CONSOLE_LOG;


	
	d->args[0].player = -1;
	d->args[1].player = -1;
	d->args[2].player = -1;
	d->args[3].player = -1;
	// parse options + champs;
	if (!(ft_recup_options(&d->vm, d->args, argv, argc)))
	{
		ft_printf("erreur ft_recup_options\n");
		exit(1);

	}
	if (d->vm.nbr_players == 0)
		return (0);
	ft_printf("nbr joueurs %d\n:", d->vm.nbr_players);
	if (!(ft_check_value_number(d->args, &d->vm)))
	{
		ft_printf("erreur ft_check_value_number\n");
		exit(1);
	}
	int p ;

	p = 0;

	while (p < d->vm.nbr_players)
	{
		ft_printf("player: %d, file: %s\n", d->args[p].player, d->args[p].file);
		++p;
	}

	ft_recup_files(&d->vm, d->args);
	ft_recup_headers(&d->vm, d->args);
	ft_recup_code(&d->vm, d->args);

	d->vm.graphic = d->vm.dump == -1 ? GRAPHIC_MODE : 0;
	ft_init_instructions(d->vm.instructions);



	int i;
	//int j;

	i = 1;

	/*
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
//		1d->vm.instructions[i].f_instructions(&d->vm, d->vm.instructions[i], 0);
//		eqrifoefk
		ft_printf("\n----------------------------------\n");
		++i;
	}

	*/

	/*
	t_argument argument[MAX_ARGS_NUMBER];
	char	oc_p;

	oc_p =	84;
	i = 0;
	ft_decode_args(144, argument);
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

	ft_decode_args(144, argument);
	int ret = ft_fill_args(argument, &d->vm, 1174, 0);


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
	*/

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


	if (ascii(ASC_LOGO) && ascii(ASC_INIT) && ascii_init()
		&& ascii(ASC_LOG)
	&& d->vm.graphic )
		mlx_start(d, &d->mlx);
	else
		while (42)
			loop_vm(d);
	return (0);
}
