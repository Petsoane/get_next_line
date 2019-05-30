/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:07:15 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/30 16:07:10 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_isline(char *s)
{
	while (*s)
	{
		if (*(s + 1) == '\0' &&  *s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	int		i ;
	int		ret;
	char	*out;
	char	*inc_buff;

	i = 0;
	inc_buff = NULL;
	out = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!out)
		return (-1);
	while ((ret = read(fd, &out[i], 1)) > 0 && out[i] !='\n' && i < BUFF_SIZE)
		i++;
	out[i + 1] = '\0';
	if (ft_isline(out) != 1 && i == BUFF_SIZE)
	{
		get_next_line(fd, &inc_buff);
		*line = ft_strjoin(out, inc_buff);
	}else
	{
		out[i] = '\0';
		*line = out;
	}
	if (ret != 0)
		return (ret);
	return (0);
}
