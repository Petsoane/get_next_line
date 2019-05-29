/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:33:05 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/29 15:10:23 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_isline(char *s)
{
	while (*s)
	{
		if (*s == '\n' && *(s + 1) == '\0')
			return (1);
		s++;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int		i;
	int		ret;
	char	*out;
	char	*inc_buff;

	i = 0;
	inc_buff = NULL;
	if (!(out = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (fd < 0 || read(fd, out, 0) == -1)
		return (-1);
	while ((ret = read(fd, &out[i], 1)) > 0 && out[i] != '\n' && i < BUFF_SIZE - 1)
		i++;
	out[i + 1] = '\0';
	if (ft_isline(out) != 1 && ret != 0)
	{
		get_next_line(fd, &inc_buff);
		*line = ft_strjoin(out, inc_buff);
		free(inc_buff);
	}
	else
	{
		out[i] = '\0';
		*line = out;
	}
	if (ret != 0)
		return (1);
	else if (ret == -1)
		return (-1);
	return (0);
}
