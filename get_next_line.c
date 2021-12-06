/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:30:26 by mait-aad          #+#    #+#             */
/*   Updated: 2021/12/06 18:00:51 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// void	my_free(void *p)
// {
// 	if (p)
// 		free(p);
// }

// char	*get_line(char	*line)
// {
// 	int		len;
// 	char	*temp;

// 	if (!*line)
// 	{
// 		my_free(line);
// 		return (NULL);
// 	}
// 	len = 0;
// 	while (line[len] != '\n' && line[len] != '\0')
// 		len++;
// 	if (line[len] == '\n')
// 		len++;
// 	temp = line;
// 	line = malloc (len + 1);
// 	ft_strncpy(line, temp, len);
// 	my_free(temp);
// 	return (line);
// }

// void	ft_save(char *buffer)
// {
// 	size_t	l;
// 	size_t	i;

// 	l = 0;
// 	i = 0;
// 	while (buffer[l] != '\n' && buffer[l] != '\0')
// 		l++;
// 	while (buffer[l++])
// 		buffer[i++] = buffer[l];
// 	buffer[i] = 0;
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	char		*temp;
// 	int			i;
// 	static char	buf[BUFFER_SIZE + 1];

// 	i = 1;
// 	line = NULL;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
// 	if (*buf)
// 		line = ft_strjoin(line, buf);
// 	while (!ft_strchr(line, '\n') && i > 0)
// 	{
// 		i = read(fd, buf, BUFFER_SIZE);
// 		buf[i] = '\0';
// 		temp = line;
// 		line = ft_strjoin(line, buf);
// 		my_free(temp);
// 	}
// 	line = get_line(buf);
// 	ft_save(buf);
// 	return (line);
// }

#include "get_next_line.h"

char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
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

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	if (save[i] == '\n')
		i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char *ptr;

// 	fd = open("/Users/mait-aad/Desktop/test.txt", O_RDONLY);
// 	i = 9;
// 	while (i-- > 0)
// 	{
// 		ptr = get_next_line(fd);
// 		printf("%s", ptr);
// 		//free(ptr);
// 	}
// 	close(fd);
// 	//system("leaks a.out");
// }
