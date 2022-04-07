/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:42:30 by thsamina          #+#    #+#             */
/*   Updated: 2021/04/16 16:01:45 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			c;

	c = 0;
	str = (unsigned char *)s;
	while (c < n)
	{
		str[c] = 0;
		c++;
	}
}
