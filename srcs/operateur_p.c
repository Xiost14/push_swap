#include "push_swap.h"

void			op_p_stk(t_stack **a, t_stack **b, t_stack *tmp)
{
	tmp = NULL;
	if (*b == NULL && *a)
	{
		*b = (t_stack *)malloc(sizeof(t_stack));
		(*b)->prv = NULL;
		(*b)->nbr = (*a)->nbr;
		(*b)->next = NULL;
		(*a) = (*a)->next;
		(*a)->prv = NULL;
	}
	else
	{
		if (*a)
		{
			tmp = (t_stack *)malloc(sizeof(t_stack));
			tmp->nbr = (*a)->nbr;
			tmp->next = NULL;
			tmp->prv = NULL;
			add_list_back(b, tmp);
			(*a) = (*a)->next;
		}
	}
}