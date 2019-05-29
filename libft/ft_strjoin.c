/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 11:37:39 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/21 09:32:03 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size2;
	int		o_size;
	int		i;
	char	*out;

	i = 0;
	size1 = 0;
	size2 = 0;
	while (s1[size1])
		size1++;
	while (s2[size2])
		size2++;
	o_size = size1 + size2;
	out = (char *)malloc(o_size - 1);
	if (!out)
		return (NULL);
	while (*s1)
		out[i++] = *s1++;
	while (*s2)
		out[i++] = *s2++;
	return (out);
}
