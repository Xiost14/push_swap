/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operateur_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:02:51 by thsamina          #+#    #+#             */
/*   Updated: 2022/04/09 11:02:52 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	op_sb(t_data *d)
{
	long	tmp;

	tmp = d->b[0];
	d->b[0] = d->b[1];
	d->b[1] = tmp;
	ft_putstr_fd("sb\n", 1);
	copy_stacks(d);
}

void	op_pb(t_data *d)
{
	long	i;

	i = 0;
	d->b[0] = d->a[0];
	d->len_b++;
	d->len_a--;
	while (i < d->len_a)
	{
		d->a[i] = d->a_copy[i + 1];
		i++;
	}
	d->a[i] = d->to_fill;
	i = 1;
	while (i < d->len_b)
	{
		d->b[i] = d->b_copy[i - 1];
		i++;
	}
	ft_putstr_fd("pb\n", 1);
	copy_stacks(d);
}

void	op_rrb(t_data *d)
{
	long	i;

	i = 1;
	d->b[0] = d->b[d->len_b - 1];
	while (i < d->len_b)
	{
		d->b[i] = d->b_copy[i - 1];
		i++;
	}
	ft_putstr_fd("rrb\n", 1);
	copy_stacks(d);
}

void	op_rb(t_data *d)
{
	long	i;

	i = 0;
	d->b[d->len_b - 1] = d->b[0];
	while (i < d->len_b - 1)
	{
		d->b[i] = d->b_copy[i + 1];
		i++;
	}
	ft_putstr_fd("rb\n", 1);
	copy_stacks(d);
}
