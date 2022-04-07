#include "push_swap.h"

int			ft_abs(float num)
{
	int		dummy;

	dummy = (int)num;
	if ((num - dummy) >= 0.5)
		return ((int) num + 1);
	else
		return ((int) num);
}