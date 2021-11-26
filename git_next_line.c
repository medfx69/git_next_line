/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:32:04 by mait-aad          #+#    #+#             */
/*   Updated: 2021/11/26 22:45:31 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "git_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*ptr;
	int			byts;
	char		buf[BUFSIZE];
	int			j;
	int			i;

	j = 0;
	while (read(fd, (buf + j), 1) > 0)
	{
		if (buf[j] == 10)
			break ;
		j++;
	}
	ptr = malloc(j);
	i = 0;
	while (j > i)
	{
		ptr[i] = buf[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	main(void)
{
	int	fd;
	int i = 4;
	int j;

	fd = open("/Users/mait-aad/Desktop/test.txt", O_RDONLY);
	j = 1;
	while (i--)
		printf("line %d : %s \n", j++, get_next_line(fd));
	close(fd);
}	
