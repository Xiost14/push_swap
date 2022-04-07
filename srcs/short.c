#include "push_swap.h"

void		sort_short_big_norm(t_stack **a, t_stack **b, t_var *v, int min)
{
	int		index;
	int		num;

	index = find_index((*a), min, 1);
	num = (list_size((*a)) / 2);
	if (num > index)
		first_parsing(a, b, 2, v);
	else
		first_parsing(a, b, 3, v);
}

void		sort_short_big(t_stack **a, t_stack **b, int len, t_var *v)
{
	int		c;
	int		min;
	t_stack	*tmp1;
	t_stack	*tmp2;

	c = len;
	while (c > 3)
	{
		min = find_min(*a);
		tmp1 = (*a)->next;
		if ((*a)->nbr != min && tmp1 && tmp1->nbr == min)
			first_parsing(a, b, 8, v);
		while (min != (*a)->nbr)
			sort_short_big_norm(a, b, v, min);
		if (min == (*a)->nbr)
		{
			tmp2 = *a;
			first_parsing(a, b, 1, v);
			free(tmp2);
			c--;
		}
	}
}

void		sort_short_3(t_stack **a, t_stack **b, t_var *v, int c)
{
	first_parsing(a, b, 8, v);
	first_parsing(a, b, c, v);
}

void		sort_short_short(t_stack **a, t_stack **b, int len, t_var *v)
{
	t_stack	*tmp;
	int		min;

	tmp = find_bottom(*a);
	min = find_min(*a);
	while (check_sort(a, len) == 0)
	{
		if ((*a)->nbr < (*a)->next->nbr && tmp->nbr == min)
			first_parsing(a, b, 3, v);
		else if ((*a)->nbr > (*a)->next->nbr && tmp->nbr == min)
			sort_short_3(a, b, v, 3);
		else if ((*a)->next->nbr == min)
		{
			if ((*a)->nbr < tmp->nbr)
				first_parsing(a, b, 8, v);
			else if ((*a)->nbr > tmp->nbr)
				first_parsing(a, b, 2, v);
		}
		else if ((*a)->nbr == min && (*a)->next->nbr > tmp->nbr)
			sort_short_3(a, b, v, 2);
	}
}

void		sort_short(t_stack **a, t_stack **b, int len, t_var *v)
{
	t_stack	*tmp;

	tmp = NULL;
	if (len == 2 && (*a)->nbr > (*a)->next->nbr)
		first_parsing(a, b, 8, v);
	if (len <= 3)
		sort_short_short(a, b, len, v);
	else if (len > 3)
	{
		sort_short_big(a, b, len, v);
		sort_short_short(a, b, 3, v);
		while ((*b))
		{
			tmp = *b;
			first_parsing(a, b, 4, v);
			free(tmp);
		}
		free_stk(b);
	}
	free_stk(a);
}