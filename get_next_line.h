/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:29:02 by lpetsoan          #+#    #+#             */
<<<<<<< HEAD:includes/get_next_line.h
/*   Updated: 2019/08/28 10:30:57 by lpetsoan         ###   ########.fr       */
=======
/*   Updated: 2019/08/16 12:00:36 by lpetsoan         ###   ########.fr       */
>>>>>>> 5e9f52626dea7ab4ed3cc4e1346afaaec2c95673:get_next_line.h
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
<<<<<<< HEAD:includes/get_next_line.h
# define BUFF_SIZE 1000
# define LINE_BUFF 1
=======
# define BUFF_SIZE 32
# define LINE_BUFF 100
>>>>>>> 5e9f52626dea7ab4ed3cc4e1346afaaec2c95673:get_next_line.h
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# define FD_MAX 1024
# define IS_BUFF_EMPTY file.buff[0] == '\0'

typedef struct		s_buff
{
	char			*buff;
	char			*start;
	char			*tmp;
}					t_buff;

typedef struct	s_prev
{
	char *prev;
}			t_prev;

int		get_next_line(const int fd, char **line);
#endif
