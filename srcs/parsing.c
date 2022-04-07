#include "push_swap.h"

void			third_parsing(t_stack **a, t_stack **b, int nbr, t_var *v)
{
	t_stack		*tmp;

	tmp = NULL;
	if (nbr == 7 && list_size(*b) > 1)
	{
		ft_putstr_fd("sb\n", v->fd);
		op_s_stk(b);
	}
	else if (nbr == 8 && list_size(*a) > 1)
	{
		ft_putstr_fd("sa\n", v->fd);
		op_s_stk(a);
	}
}

void			second_parsing(t_stack **a, t_stack **b, int nbr, t_var *v)
{
	t_stack *tmp;

	tmp = NULL;
	if (nbr == 4)
	{
		ft_putstr_fd("pa\n", v->fd);
		op_p_stk(b, a, tmp);
		free(tmp);
	}
	else if (nbr == 5 && list_size(*b) > 1)
	{
		ft_putstr_fd("rb\n", v->fd);
		op_r_stk(b);
		free(tmp);
	}
	else if (nbr == 6 && list_size(*b) > 1)
	{
		ft_putstr_fd("rrb\n", v->fd);
		op_rr_stk(b,tmp);
		free(tmp);
	}
	else
		third_parsing(a, b, nbr, v);
}

void			first_parsing(t_stack **a, t_stack **b, int nbr, t_var *v)
{
	t_stack		*tmp;

	tmp = NULL;
	if (nbr == 1)
	{
		ft_putstr_fd("pb\n", v->fd);
		op_p_stk(a, b, tmp);
		free(tmp);
	}
	else if (nbr == 2)
	{
		ft_putstr_fd("ra\n", v->fd);
		op_r_stk(a);
		free(tmp);
	}
	else if (nbr == 3 && list_size(*a) > 1)
	{
		ft_putstr_fd("rra\n", v->fd);
		op_rr_stk(a, tmp);
	}
	else
		second_parsing(a, b, nbr, v);
}