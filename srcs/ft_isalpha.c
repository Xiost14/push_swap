/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:47:14 by thsamina          #+#    #+#             */
/*   Updated: 2021/04/14 13:47:36 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalpha(int character)
{
	if ((character >= 65 && character <= 90)
		|| (character >= 97 && character <= 122))
		return (1);
	return (0);
}
