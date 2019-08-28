/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:29:02 by lpetsoan          #+#    #+#             */
<<<<<<< HEAD:srcs/main.c
/*   Updated: 2019/08/28 10:33:07 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
=======
/*   Updated: 2019/08/16 12:00:43 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
>>>>>>> 5e9f52626dea7ab4ed3cc4e1346afaaec2c95673:main.c
#include <fcntl.h>

int main(void)
{
	int fd = open("bible.txt", O_RDONLY);
	char *out;
	//int fd = 0;
	while (get_next_line(fd, &out) == 1)
	{
		printf("%s\n", out);
	}
	return (0);
}
