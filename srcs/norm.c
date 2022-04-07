#include "push_swap.h"

void		sort_big_norm_1(t_stack **a, t_stack **b, t_var *v, int pvt)
{
	int		index;
	int		nbr;

	index = find_index((*a), pvt, 1);
	nbr = (list_size((*a)) / 2);
	if (index < nbr)
		first_parsing(a, b, 2, v);
	else
		first_parsing(a, b, 3, v);
}

void		sort_big_norm_2(t_stack **a, t_stack **b, t_var *v, int pvt)
{
	int		index;
	int		num;

	index = find_index((*b), pvt, 2);
	num = ft_abs((list_size((*b)) / 2));
	if (index < num && *b)
		first_parsing(a, b, 5, v);
	else if (*b)
		first_parsing(a, b, 6, v);
}