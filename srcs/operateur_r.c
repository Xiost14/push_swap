#include "push_swap.h"

t_stack			*op_rr_swap(t_stack *top, t_stack *tmp)
{
	while (top->next)
		top = top->next;
	tmp->nbr = top->nbr;
	tmp->next = NULL;
	tmp->prv = NULL;
	return (tmp);
}

void			op_rr_bottom(t_stack **top)
{
	while ((*top))
	{
		if ((*top)->next->next == NULL)
			break ;
		*top = (*top)->next;
	}
	free((*top)->next);
	(*top)->next = NULL;
}

void			op_rr_stk(t_stack **top, t_stack *tmp)
{
	t_stack		*a;

	a = NULL;
	tmp = NULL;
	if (*top)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (tmp == NULL)
			return ;
		tmp = op_rr_swap(*top, tmp);
		a = *top;
		op_rr_bottom(top);
		*top = a;
		add_list_front(top, tmp);
	}
}

void			op_r_stk(t_stack **top)
{
	if (*top)
	{
		*top = (*top)->next;
		add_list_back_r(top);
	}
}