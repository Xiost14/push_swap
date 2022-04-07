#include "push_swap.h"

void		ft_push_swap(t_var *v, int ac, char **av)
{
	t_stack	*stk;

	stk = NULL;
	v->split = fill_arg(v, ac, av);
	check_dup(v->split);
	check_nbr(v->split);
	v->a = fill_list(v, v->split, stk);
	if (check_sort(&v->a, list_size(v->a)) == 1)
		ft_exit("Error\n", 0);
	v->len = list_size(v->a);
	free_stk(&stk);
	if (v->len <= 10)
		sort_short(&(v->a), &(v->b), v->len, v);
	else
		sort_bigger(&(v->a), &(v->b), v->len, v);
	if (ac == 2 || (ac == 3 && v->fd !=1))
		ft_free_array(v->split);
	close(v->fd);
}

void		ft_exit(char *str, int err)
{
	ft_putstr_fd(str, 2);
	exit(err);
}

int			main(int ac, char **av)
{
	t_var	*v;

	v = NULL;
	if (ac < 2)
		ft_exit("Error\n", 1);
	else
	{
		v = init_var(v);
		ft_push_swap(v, ac, av);
	}
	free(v);
	v = NULL;
}