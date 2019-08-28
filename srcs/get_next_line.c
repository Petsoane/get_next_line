/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:srcs/get_next_line.c
/*   Created: 2019/05/30 08:07:15 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/28 10:33:24 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
=======
/*   Created: 2019/08/16 11:45:04 by event             #+#    #+#             */
/*   Updated: 2019/08/16 12:11:16 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
>>>>>>> 5e9f52626dea7ab4ed3cc4e1346afaaec2c95673:get_next_line.c

static int	line_copy(char *buf, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (ft_strlen(line) > i + 1)
		buf = ft_strcpy(buf, &(line[i + 1]));
	line[i] = '\0';
	return (1);
}

static int	reader(const int fd, char **buf, char **line)
{
	int		r;
	char	*store;

	r = 1;
	if (buf[fd][0] != '\0')
		*line = ft_strcpy(*line, buf[fd]);
	ft_bzero(buf[fd], BUFF_SIZE);
	while (!(ft_strchr(*line, '\n')) && (r = read(fd, buf[fd], BUFF_SIZE)) > 0)
	{
		store = *line;
		*line = ft_strjoin(store, buf[fd]);
		free(store);
		if (!*line)
			return (-1);
		ft_bzero(buf[fd], BUFF_SIZE);
	}
	if (r >= 0 && *line[0] != '\0')
		return (line_copy(buf[fd], *line));
	return (r);
}

int			get_next_line(const int fd, char **line)
{
<<<<<<< HEAD:srcs/get_next_line.c
	int			i;
	int			ret;
	char		*out;
	char		*inc;
=======
	static char	*buf[FD_MAX];
>>>>>>> 5e9f52626dea7ab4ed3cc4e1346afaaec2c95673:get_next_line.c

	if (fd < 0 || fd > FD_MAX || read(fd, buf[fd], 0) < 0 || !line)
		return (-1);
<<<<<<< HEAD:srcs/get_next_line.c
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
=======
	if (!(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!buf[fd])
		buf[fd] = ft_strnew(BUFF_SIZE + 1);
	return (reader(fd, buf, line));
>>>>>>> 5e9f52626dea7ab4ed3cc4e1346afaaec2c95673:get_next_line.c
}
