/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:07:15 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/30 14:56:41 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_isline(char *s, int i)
{
	if (s[i] == '\n' && s[i + 1] == '\0')
		return (1);
	return (0);
}

static void		join_and_free(char **line, char *out, char **inc)
{
	*line = ft_strjoin(out, *inc);
	free(*inc);
}

int				get_next_line(const int fd, char **line)
{
	int			i;
	int			ret;
	char		*out;
	char		*inc;

	i = 0;
	inc = NULL;
	out = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!out || fd < 0 || read(fd, &out, 0) == -1)
		return (-1);
	while ((ret = read(fd, &out[i], 1)) > 0 && out[i] != '\n' && i < BUFF_SIZE)
		i++;
	out[i + 1] = '\0';
	if (!ft_isline(out, i) && i == BUFF_SIZE)
	{
		get_next_line(fd, &inc);
		join_and_free(line, out, &inc);
	}
	else
	{
		out[i] = '\0';
		*line = ft_strdup(out);
	}
	free(out);
	return (ret != 0 ? ret : 0);
}
