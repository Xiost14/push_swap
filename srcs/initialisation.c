#include "push_swap.h"

t_var		*init_var(t_var *v)
{
	v = (t_var *)malloc(sizeof(t_var));
	if (v == NULL)
		exit(1);
	v->a = NULL;
	v->b = NULL;
	v->line = NULL;
	v->split = NULL;
	v->len = 0;
	v->print = 0;
	return (v);
}