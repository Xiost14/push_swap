#include "push_swap.h"

int				check_overf(char *str)
{
	long long	tmp;

	tmp = ps_atoll(str);
	if (tmp >=INT_MIN && tmp <= INT_MAX && ft_strlen(str) < 12)
		return (1);
	return (0);
}

void			check_nbr(char **av)
{
	int			c;
	int			x;

	c = 0;
	if (!av[0])
		ft_exit("Error\n", 1);
	while (av[c])
	{
		x = 0;
		if (check_overf(av[c]) == 0)
			ft_exit("Error\n", 1);
		while (av[c][x])
		{
			if (ft_isalpha(av[c][x]) == 1 || av[c][x] == '.'
			|| ((av[c][x]) == '-' && (av[c][x +1]) == '\0')
			|| ((av[c][x]) == '+' && (av[c][x +1]) == '\0'))
				ft_exit("Error\n", 1);
			x++;
		}
		c++;
	}
}

void			check_dup(char **av)
{
	int			c;
	int			x;
	char		*tmp;

	c = 0;
	while (av[c])
	{
		tmp = ft_strdup(av[c]);
		x = 0;
		while (av[x])
		{
			if (c == x)
				x++;
			else if (ft_strcmp(tmp, av[x]) == 0)
			{
				ft_free_arg(&tmp);
				ft_exit("Error\n", 1);
			}
			else
				x++;
		}
		ft_free_arg(&tmp);
		c++;
	}
}

int				check_sort(t_stack **a, int len)
{
	t_stack		*tmp;

	if (list_size(*a) != len)
		return (0);
	(void)len;
	tmp = *a;
	while (tmp && tmp->next)
	{
		if((tmp)->next != NULL && ((tmp)->nbr < (tmp)->next->nbr))
			(tmp) = tmp->next;
		else
			return (0);
	}
	return (1);
}

int				check_pivot(t_stack *a, int pvt, int flag)
{
	while (a)
	{
		if (flag == 1)
		{
			if (a->nbr <= pvt)
				return (1);
			a = a->next;
		}
		if (flag == 2)
		{
			if (a->nbr == pvt)
				return (1);
			a = a->next;
		}
	}
	return (0);
}