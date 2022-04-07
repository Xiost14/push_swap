#include "push_swap.h"

void		op_s_stk(t_stack **top)
{
	int		i;
	int		j;
	t_stack	*tmp;

	tmp = NULL;
	if ((*top) && (*top)->next)
	{
		tmp = *top;
		i = (*top)->nbr;
		j = (*top)->next->nbr;
		tmp = *top;
		(*top)->nbr = j;
		tmp = *top;
		(*top)->next->nbr = i;
		(*top) = tmp;
	}
}