#include "push_swap.h"

void			add_list_back_r(t_stack **top)
{
	t_stack		*tmp1;
	t_stack		*tmp2;

	tmp1 = NULL;
	tmp1 = *top;
	tmp2 = (*top)->prv;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = tmp2;
	tmp1->next->prv = tmp1;
	tmp1->next->next = NULL;
}

void			add_list_back(t_stack **first, t_stack *new)
{
	t_stack		*tmp;

	if (*first == NULL)
		*first = new;
	else
	{
		tmp = *first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prv = tmp;
	}
}

void			add_list_front(t_stack **top, t_stack *new)
{
	new->next = (*top);
	new->prv = NULL;
	if ((*top) != NULL)
		(*top)->prv = new;
	(*top) = new;
}

int				list_size(t_stack *a)
{
	int			len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

void			free_stk(t_stack **stk)
{
	t_stack		*tmp;

	if (*stk)
	{
		while (*stk)
		{
			tmp = (*stk)->next;
			free(*stk);
			*stk = NULL;
			(*stk) = tmp;
		}
		free(*stk);
		*stk = NULL;
	}
}