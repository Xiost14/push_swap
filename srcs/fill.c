#include "push_swap.h"

char		**fill_arg(t_var *v, int ac, char **av)
{
	v->fd = 1;
	if (ac == 2)
		v->split = ft_split(av[1], ' ');
	else
		v->split = &av[1];
	return (v->split);
}

t_stack		*fill_list(t_var *v, char **split, t_stack *tmp)
{
	int		c;

	c = 0;
	while (split[c])
	{
		tmp = malloc(sizeof(t_stack));
		if (tmp == NULL)
			return (NULL);
		tmp->nbr = ps_atoll(split[c]);
		if (tmp->nbr > 2147483647 || tmp->nbr < -2147483648)
			ft_exit("Error\n", 1);
		tmp->next = NULL;
		tmp->prv = NULL;
		add_list_back(&v->a, tmp);
		tmp = NULL;
		c++;
	}
	return (v->a);
}