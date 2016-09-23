#include "ft_corewar.h"


void	wip(t_data *d)
{
	d->args.file[4] = (char *)NULL;

	d->args.file[0] = "./zaz/_.cor";
	d->args.file[1] = (char *)NULL;
}


int		main(int argc, char **argv)
{
	t_data	*d;

	d = data();
	*argv += 0 * argc; // brain compilateur flag
	/* lance les 4 premiers affichage dans le terminal, puis démarre mlx */
	d->mlx.scene = SCENE_START;
	d->vm.graphic = GRAPHIC_MODE;
	d->vm.console = CONSOLE_LOG;


	wip(d);

	int fd;
	char line[2048];
	ft_bzero(line, 2048);
	if ((fd = open(d->args.file[0], O_RDONLY)) < 1)
		ft_printf("cant read\n");
	else {

		ft_printf("INFO PRATIQUE:\n");
		ft_printf("\tread fd %d: %s\n", fd, d->args.file[0]);
		ft_printf("\tsize of char: %lu\n", sizeof(char));
		ft_printf("\tsize of int: %lu\n", sizeof(int));
		ft_printf("\tsize of unsigned int: %lu\n", sizeof(unsigned int));
		ft_printf("\tsize of unsigned char: %lu\n", sizeof(unsigned char));
		ft_printf("\tunsigned int MAX: %lu\n", UINT_MAX);
		ft_printf("\tsize of line[0]: %lu\n", sizeof(line[0]));
		ft_printf("\tsize of line: %lu\n", sizeof(line));
		ft_printf("\tsize of void *: %lu\n", sizeof(void *));
		ft_printf("\ttaille code champion max: %d\n", (4096 / 6));
		ft_printf("\tEOF on my system is %d\n", EOF);
		ft_printf("\tEOF convertis en unsigned int %hhu\n", EOF);
		ft_printf("\tsize of header_t %lu\n", sizeof(struct header_s));
		ft_printf("--\n");

		header_t file_header;
		ft_bzero(&file_header, sizeof(header_t));
		read( fd, (void *)&file_header, sizeof(header_t));
		unsigned char *ptr_octet;

		ft_printf("Magic number (%lu octet): %X\n", sizeof(file_header.magic), file_header.magic);
		ptr_octet = (void *)&file_header.magic;
		ft_printf("octet 1: %.2X\n", ptr_octet[0]);
		ft_printf("octet 2: %.2X\n", ptr_octet[1]);
		ft_printf("octet 3: %.2X\n", ptr_octet[2]);
		ft_printf("octet 4: %.2X\n", ptr_octet[3]);


		ft_printf("Name (%lu octet): %s\n", sizeof(file_header.prog_name), file_header.prog_name);

		ft_printf("Code size (%lu octet): %X\n", sizeof(file_header.prog_size), file_header.prog_size);
		ptr_octet = (void *)&file_header.prog_size;
		ft_printf("octet 1: %.2X\n", ptr_octet[0]);
		ft_printf("octet 2: %.2X\n", ptr_octet[1]);
		ft_printf("octet 3: %.2X\n", ptr_octet[2]);
		ft_printf("octet 4: %.2X\n", ptr_octet[3]);

		ft_printf("Comment (%lu octet): %s\n", sizeof(file_header.comment), file_header.comment);


		/*
		read( fd, line, 4);
		ft_printf("READ 4 PREMIER OCTETS (4 octets):\n");
		ft_printf("\tversion hexa ->\n");
		ft_printf("\toctets 1: %x\n", line[0]);
		ft_printf("\toctets 2: %x\n", line[1]);
		ft_printf("\toctets 3: %x\n", line[2]);
		ft_printf("\toctets 4: %x\n", line[3]);
		ft_printf("\n");

		ft_printf("\tversion unsigned char ->\n");
		ft_printf("\toctets 1: %hhu\n", line[0]);
		ft_printf("\toctets 2: %hhu\n", line[1]);
		ft_printf("\toctets 3: %hhu\n", line[2]);
		ft_printf("\toctets 4: %hhu\n", line[3]);

		ft_printf("--\n");

		ft_printf("NOM DU PROGRAMME (%d octets):\n", PROG_NAME_LENGTH);
		read (fd, line, PROG_NAME_LENGTH + 1);
		ft_printf("\t%s\n", line);
		ft_printf("--\n");

		ft_printf("PROGRAMME SIZE (%d octets):\n", sizeof(unsigned int));
		read (fd, line, 4);
		ft_printf("\t%u\n", line);
		ft_printf("--\n");


		ft_printf("COMMENTAIRE (%d octets):\n", COMMENT_LENGTH);
		read (fd, line, COMMENT_LENGTH + 1);
		ft_printf("\t");
		write(1, &line, 2048);
		ft_printf("\n");
		ft_printf("--\n");


		ft_printf("CODE (%d octets):\n", COMMENT_LENGTH);
		read (fd, line, COMMENT_LENGTH);

		int empty = -1;
		while (line[++empty] == 0)
			;
		empty++;
		ft_printf("empty char: %d\n", empty);
		empty--;


		int octet = -1;
		// while (++octet < 682)
		while (line[++octet + empty] != 3)
			ft_printf("[%x]", line[octet + empty]);
		ft_printf("\n\toctets lus: %d\n", (octet + 1));
		ft_printf("\tnb caractère hexa: %d\n", (octet + 1) * 2);
		ft_printf("--\n");



		ft_printf("\nFIN DE LECTURE SUR: [%x]\n", line[octet + empty]);
		ft_printf("\tvaleur unsigned char: [%hhu]\n", line[octet + empty]);
		ft_printf("\tvaleur char: [%c]\n", line[octet + empty]);
		ft_printf("--\n");

		ft_printf("TAILLE DU FICHIER: %d\n", (octet + 1) + (empty + 1) + 2048 + 128);
		*/
	}

	exit (0);


	if (ascii(ASC_LOGO) && ascii(ASC_INIT) && ascii_init()
		&& ascii(ASC_LOG)
	&& d->vm.graphic)
		mlx_start(d, &d->mlx);
	else
		while (42)
			loop_vm(d);
	return (0);
}
