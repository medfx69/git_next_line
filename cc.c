#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*ptr;
	int		j;
	int		k;
	int		c;

	if (s2)
	{
		k = (int)ft_strlen(s1);
		j = (int)ft_strlen(s2);
		ptr = malloc(k + j + 1);
		if (!ptr)
			return (NULL);
		c = 0;
		while (c < k)
		{
			ptr[c] = s1[c];
			c++;
		}	
		c = 0;
		while (c < j)
			ptr[k++] = s2[c++];
		ptr[k] = '\0';
		return (ptr);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	int			byts;
	char		buf[BUFSIZE];
	int			j;
	static int	i;

	j = 0;
	if (BUFSIZE == 0)
		return (NULL);
	while (read(fd, (buf + j), 1) > 0)
	{
		if (BUFSIZE - 1 == j || buf[j] == 10)
			break ;
		j++;
	}
	if (buf[j] != '\n')
		buf[j + 1] = '\0';
	if (i == 0)
	{
		i++;
		free(ptr);
		ptr = (char *)malloc(1);
	}
	if (j == 0)
		return (NULL);
	ptr = ft_strjoin(ptr, buf);
	if (buf[j] != '\n')
		get_next_line(fd);
	i = 0;
	return (ptr);
}

int	main(void)
{
	int	fd;
	int i = 9;
	int j;

	fd = open("/home/mohamed/Desktop/test.txt", O_RDONLY);
	j = 1;
	while (i--)
		printf("line %d : %s \n", j++, get_next_line(fd));
	close(fd);
}
