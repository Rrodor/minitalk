/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:35:25 by rrodor            #+#    #+#             */
/*   Updated: 2023/06/06 18:02:04 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

char	*mt_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;
	int		i;
	int		j;

	if (!s1)
		return (s2);
	ls1 = mt_strlen2((char *)s1);
	ls2 = mt_strlen2((char *)s2);
	str = (char *)malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	free(s1);
	free(s2);
	return (str);
}

size_t	mt_strlen2(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	mt_atoi(char *nptr)
{
	int	i;
	int	pol;
	int	res;

	i = 0;
	pol = 1;
	res = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			pol *= -1;
		i++;
	}
	while (mt_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * pol);
}

int	mt_isdigit(int c)
{
	if (c < 58 && c > 47)
		return (1);
	return (0);
}
