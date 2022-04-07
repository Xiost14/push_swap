/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:55:48 by thsamina          #+#    #+#             */
/*   Updated: 2021/04/16 16:30:47 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *old_string)
{
	char	*new_string;
	int		len;
	int		c;

	len = ft_strlen(old_string);
	new_string = malloc(len * sizeof(char) + 1);
	if (!new_string)
		return (NULL);
	c = 0;
	while (old_string[c] != '\0')
	{
		new_string[c] = old_string[c];
		c++;
	}
	new_string[c] = '\0';
	return (new_string);
}
