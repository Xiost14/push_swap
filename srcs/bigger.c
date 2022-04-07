#include "push_swap.h"

void		sort_bigger_first(t_stack **a, t_stack **b, int len, t_var *v)
{
	int		c;
	int		pvt;
	t_stack	*tmp1;
	t_stack	*tmp2;

	c = len;
	while (c >= ft_abs(len / 4))
	{
		tmp1 = ft_lst_dup(*a);
		pvt = find_pivot(tmp1);
		while (check_pivot((*a), pvt, 1) && (*a))
		{
			if ((*a)->nbr <= pvt)
			{
				tmp2 = *a;
				first_parsing(a, b, 1, v);
				c--;
				free(tmp2);
			}
			else
				sort_big_norm_1(a,b, v, pvt);
		}
		free_stk(&tmp1);
	}
}

void		sort_bigger_second(t_stack **a, t_stack **b, int len, t_var *v)
{
	int		min;
	t_stack	*tmp;

	tmp = NULL;
	while (*a && !check_sort(a, len))
	{
		min = find_min(*a);
		tmp = (*a)->next;
		while ((*a)->nbr != min && tmp && tmp->nbr == min)
			first_parsing(a, b, 8, v);
		while (list_size(*a) && check_pivot((*a), min, 1))
		{
			if ((*a)->nbr == min)
			{
				tmp = *a;
				first_parsing(a, b, 1, v);
				free(tmp);
				len--;
			}
			else
				sort_big_norm_1(a, b, v, min);
		}
	}
}

void		sort_bigger_third(t_stack **a, t_stack **b, int max, t_var *v)
{
	t_stack	*tmp;

	tmp = NULL;
	while (*b)
	{
		max = find_max(*b);
		while (check_pivot((*b), max, 2))
		{
			max = find_max(*b);
			tmp = (*b)->next;
			while ((*b)->nbr != max && tmp && tmp->nbr == max)
				first_parsing(a, b, 7, v);
			while (((*b)->nbr != max) && *b)
				sort_big_norm_2(a, b, v, max);
			while (*b && (*b)->nbr == max)
			{
				tmp = *b;
				first_parsing(a, b, 4, v);
				max = find_max(*b);
				free(tmp);
			}
		}
	}
}

void		sort_bigger(t_stack **a, t_stack **b, int len, t_var *v)
{
	int		max;

	max = 0;
	sort_bigger_first(a, b, len, v);
	sort_bigger_second(a, b, len, v);
	sort_bigger_third(a, b, max, v);
	free_stk(a);
	free_stk(b);
}