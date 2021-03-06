/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operateur_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:02:13 by thsamina          #+#    #+#             */
/*   Updated: 2022/04/09 11:02:14 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	op_sa(t_data *d)
{
	long	tmp;

	tmp = d->a[0];
	d->a[0] = d->a[1];
	d->a[1] = tmp;
	ft_putstr_fd("sa\n", 1);
	copy_stacks(d);
}

void	op_pa(t_data *d)
{
	long	i;

	i = 0;
	d->a[0] = d->b[0];
	d->len_b--;
	d->len_a++;
	while (i < d->len_b)
	{
		d->b[i] = d->b_copy[i + 1];
		i++;
	}
	d->b[i] = d->to_fill;
	i = 1;
	while (i < d->len_a)
	{
		d->a[i] = d->a_copy[i - 1];
		i++;
	}
	ft_putstr_fd("pa\n", 1);
	copy_stacks(d);
}

void	op_rra(t_data *d)
{
	long	i;

	i = 1;
	d->a[0] = d->a[d->len_a - 1];
	while (i < d->len_a)
	{
		d->a[i] = d->a_copy[i - 1];
		i++;
	}
	ft_putstr_fd("rra\n", 1);
	copy_stacks(d);
}

void	op_ra(t_data *d)
{
	long	i;

	i = 0;
	d->a[d->len_a - 1] = d->a[0];
	while (i < d->len_a - 1)
	{
		d->a[i] = d->a_copy[i + 1];
		i++;
	}
	ft_putstr_fd("ra\n", 1);
	copy_stacks(d);
}
