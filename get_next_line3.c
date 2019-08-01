/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:29:02 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/01 09:10:29 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static int		get_line(char **line, const int fd);

int				get_next_line(const int fd, char **line)
{
	static char *out;
	if (read(fd, line, 0) == -1)
		return (-1);
	int ret = get_line(&out, fd);
	if (ret != -1)
		*line = ft_strdup(out);
	free(out);
	return (ret);
}

static int 		get_line(char **line, const int fd)
{
	int i;
	int ret;
	static char out[BUFF_SIZE + 1];

	i = 0;
	*line = ft_strdup("");
	while ((ret = read(fd, &out[i], 1)) > 0 && out[i] != '\n')
	{
		i++;
		if (i == BUFF_SIZE)
		{
			out[i] = '\0';
			*line = ft_strjoin(*line, out);
			i = 0;
		}
	}
	out[i] = '\0';
	*line = ft_strjoin(*line, out);
	if (ret != 0)
		return (ret);
	return (0);
}
