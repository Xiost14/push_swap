#include "push_swap.h"

t_stack		*ft_lst_dup(t_stack *stk)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = malloc(sizeof(t_stack));
	ft_bzero(tmp1, sizeof(t_stack));
	tmp2 = tmp1;
	while (stk)
	{
		tmp1->nbr = stk->nbr;
		if (stk->next)
		{
			tmp1->next = malloc(sizeof(t_stack));
			ft_bzero(tmp1->next, sizeof(t_stack));
			tmp1 = tmp1->next;
		}
		stk = stk->next;
	}
	tmp1 = tmp2;
	return (tmp1);
}

void		ft_list_swap(t_stack *x, t_stack *y)
{
	int		tmp;

	tmp = x->nbr;
	x->nbr = y->nbr;
	y->nbr = tmp;
}

t_stack		*ft_list_sort(t_stack *stk)
{
	t_stack	*base;
	t_stack	*tmp;
	t_stack	*cmp;

	base = NULL;
	base = stk;
	tmp = NULL;
	cmp = NULL;
	while (base->next)
	{
		cmp = base;
		tmp = base->next;
		while (tmp)
		{
			if (cmp->nbr > tmp->nbr)
				cmp = tmp;
			tmp = tmp->next;
		}
		ft_list_swap(base, cmp);
		base = base->next;
	}
	return (stk);
}

int			ft_list_nbr(t_stack **stk, int index)
{
	t_stack	*tmp;
	int		c;

	c = 0;
	tmp = *stk;
	while (tmp != NULL)
	{
		if (c == index)
			return (tmp->nbr);
		c++;
		tmp = tmp->next;
	}
	return (1);
}