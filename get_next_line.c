/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:30:26 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/05 18:02:15 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_save(int fd, char *save)
{
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			i;

	i = 1;
	while (!ft_strchr(save, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0)
			return (NULL);
		buf[i] = '\0';
		temp = save;
		save = ft_strjoin(save, buf);
		if (2)
			free(temp);
	}
	return (save);
}

char	*get_line(char	*save)
{
	char	*s;
	int		i;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] != '\n')
		i++;
	s = (char *)malloc((sizeof(char) * i) + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char	*save)
{
	char	*s ;
	int		i;
	int		c;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
	if (!s)
		return (0);
	if (save[i] == '\n')
		i++;
	c = 0;
	while (save[i])
	{
		s[c] = save[i];
		c++;
		i++;
	}
	free(save);
	s[c] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = read_save(fd, save);
	if (!save)
	{
		free (save);
		return (NULL);
	}
	line = get_line(save);
	save = ft_save(save);
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;
	char *ptr;

	fd = open("/Users/mait-aad/Desktop/test.txt", O_RDONLY);
	i = 9;
	while (i-- > 0)
	{
		ptr =get_next_line(fd);
		printf("%s", ptr);
		free (ptr);
	}
	close(fd);
	system("leaks a.out");
}
