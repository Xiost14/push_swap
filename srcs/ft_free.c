#include "push_swap.h"

void		ft_free_arg(char **arg)
{
	if (*arg)
		free(*arg);
	*arg = NULL;
}