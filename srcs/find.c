#include "push_swap.h"

t_stack		*find_bottom(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while ((tmp)->next)
		(tmp) = (tmp)->next;
	return (tmp);
}

int			find_min(t_stack *stk)
{
	int		min;

	min = stk->nbr;
	while (stk)
	{
		if (stk->nbr < min)
			min = stk->nbr;
		stk = stk->next;
	}
	return (min);
}

int			find_max(t_stack *stk)
{
	int		max;
	t_stack	*tmp;

	max = 0;
	tmp = NULL;
	if (stk)
	{
		max = stk->nbr;
		tmp = stk;
		while (stk)
		{
			if (stk->nbr >= max)
				max = stk->nbr;
			stk = stk->next;
		}
		stk = tmp;
	}
	return (max);
}

int			find_index(t_stack *stk, int num, int flag)
{
	int		c;

	c = 1;
	if (flag == 1)
	{
		while (stk)
		{
			if (stk->nbr <= num)
				return (c);
			stk = stk->next;
			c++;
		}
	}
	if (flag == 2)
	{
		while (stk)
		{
			if (stk->nbr >= num)
				return (c);
			stk = stk->next;
			c++;
		}
	}
	return (-1);
}

int			find_pivot(t_stack *stk)
{
	t_stack	*tmp;
	int		len;
	int		pvt;

	pvt = 0;
	len = 0;
	tmp = NULL;
	len = list_size(stk);
	tmp = ft_list_sort(stk);
	if (len <= 10)
		pvt = ft_abs(len / 2);
	else if (len > 10 && len < 200)
		pvt = ft_abs(len / 4);
	else if (len >= 200)
		pvt = ft_abs(len / 8);
	return (ft_list_nbr(&tmp, pvt));
}