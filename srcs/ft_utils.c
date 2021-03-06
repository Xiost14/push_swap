/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:59:52 by thsamina          #+#    #+#             */
/*   Updated: 2022/04/09 10:59:56 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_is_space(char c)
{
	if (c == '\f' || c == '\t' || c == '\v' || c == '\n'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int n)
{
	if (n >= 48 && n <= 57)
	{
		return (1);
	}
	else
		return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_swap(long *a, long *b)
{
	long	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
