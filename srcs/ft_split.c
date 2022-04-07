/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:02:21 by thsamina          #+#    #+#             */
/*   Updated: 2021/04/16 16:26:46 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nstring(const char *str, char cara)
{
	int	nbr;
	int	sep;
	int	c;

	nbr = 0;
	sep = 0;
	c = 0;
	if (str[c] == '\0')
		return (0);
	while (str[c] != '\0')
	{
		if (str[c] == cara)
			sep = 0;
		else if (sep == 0)
		{
			sep = 1;
			nbr++;
		}
		c++;
	}
	return (nbr);
}

int	ft_ncara(const char *str, char cara, int c)
{
	int	len;

	len = 0;
	while (str[c] != cara && str[c] != '\0')
	{
		len++;
		c++;
	}
	return (len);
}

char	**ft_free_alloc(char **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

char	**ft_alloc(const char *str, char cara, char **dst, int nbr)
{
	int	k;
	int	c;
	int	j;
	int	temp_len;

	c = 0;
	j = 0;
	while (str[c] != '\0' && j < nbr)
	{
		k = 0;
		while (str[c] == cara)
			c++;
		temp_len = ft_ncara(str, cara, c);
		dst[j] = (char *)malloc(sizeof(char) * temp_len + 1);
		if (dst[j] == NULL)
			return (ft_free_alloc(dst, j));
		while (str[c] != '\0' && str[c] != cara)
			dst[j][k++] = str[c++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char		**ft_split(const char *str, char cara)
{
	char	**dst;
	int		nbr;

	if (str == NULL)
		return (NULL);
	nbr = ft_nstring(str, cara);
	dst = (char **)malloc(sizeof(char *) * (nbr + 1));
	if (!dst)
		return (NULL);
	return (ft_alloc(str, cara, dst, nbr));
}
