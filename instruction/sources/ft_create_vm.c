#include "op.h"
#include "libft.h"

char	*ft_create_vm(void)
{
	char *vm;

	vm = (char *)ft_memalloc(sizeof(char) * MEM_SIZE);
	return (vm);
}
